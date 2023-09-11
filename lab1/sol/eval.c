/***************
Archivo: eval.c
Descripcion: Creacin de un moudlo del kernel y uso dle sistema de archivos /proc, se mostrara el mensaje cuando se lea la entrada /proc/segundos:
- Mostrar mensaje cuando se cargue el kernel
- Cantidad de segundos desde que se cargo el kernel
- Registro de cuantas veces se lee el archivo al eliminar el kernel
****************/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>
#include <asm/param.h>
#include <linux/jiffies.h>

static unsigned long jiffies_inicio;

#define BUFFER_SIZE 256
#define PROC_NAME "segundos"

//Definir el prototipo de la funcion a utilizar cuando se lea /proc/hello
ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);

//Crear una estructura para definir los parametros de la entrada a crear en /proc
const struct proc_ops proceso_ops = {
	.proc_read = proc_read, // Nombre de la funcion que se llamara cuando se lea la entrada
};

// Funcion que se llaam cuando el modulo se carga
int proc_init (void) {
	// Crear la entrada en /proc/hello
	printk(KERN_ALERT "Modulo cargado \n");
	proc_create(PROC_NAME, 0666, NULL, &proceso_ops);
	jiffies_inicio = jiffies; 
	return 0;
}

// Funcion que es llamada cuando el modulo es removido
void proc_exit(void) {
	//Remover la entrada /proc/hello
	printk(KERN_ALERT "Cantidad de veces que se leyo el archivo: \n");
	remove_proc_entry (PROC_NAME, NULL);
}

// seconds = jiffies / HZ
ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos) {
	int rv = 0;
	char buffer[BUFFER_SIZE];
	static int completed = 0;

	if (completed) {
		completed = 0;
		return 0;
	}

	completed = 1;

	//
    unsigned long jiffies_actual = jiffies;
    unsigned long segundos_transcurridos;

    //calcular la cantidad de segundos transcurridos
    segundos_transcurridos = (jiffies_actual - jiffies_inicio) / HZ;

	//

	rv = sprintf (buffer, "Segundo transcurridos: %llu\n", segundos_transcurridos);

	//Copia el espacio del kernel al espacio de usuario usr_buf
	copy_to_user(usr_buf, buffer, rv);

	return rv;
}

//Macros para registrar los puntos de entrada y salida del modulo
module_init (proc_init);
module_exit (proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Modulo kernel segundos");
MODULE_AUTHOR("Brandon Daniel Parrillas Sanchez");