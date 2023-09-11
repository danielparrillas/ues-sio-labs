/***************
Archivo: hello.c
Descripcion: Cereacion de un moudlo del kernel y uso dle sistema de archivos /proc, se mostrara el mensaje Hola mundo! cuando se lea la entrada /proc/hello
****************/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/proc_fs.h>

#define BUFFER_SIZE 128
#define PROC_NAME "hello"

//Definir el prototipo de la funcion a utilizar cuando se lea /proc/hello
ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);

//Crear una estructura para definir los parametros de la entrada a crear en /proc
const struct proc_ops proceso_ops = {
	.proc_read = proc_read, // Nombre de la funcion que se llamara cuando se lea la entrada
};

// Funcion que se llaam cuando el modulo se carga
int proc_init (void) {
	// Crear la entrada en /proc/hello
	proc_create(PROC_NAME, 0666, NULL, &proceso_ops);
	return 0;
}

// Funcion que es llamada cuando el modulo es removido
void proc_exit(void) {
	//Remover la entrada /proc/hello
	remove_proc_entry (PROC_NAME, NULL);
}

//Funcion que es llamada cada vez que /proc/hello es leido
ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos) {
	int rv = 0;
	char buffer[BUFFER_SIZE];
	static int completed = 0;

	if (completed) {
		completed = 0;
		return 0;
	}

	completed = 1;

	rv = sprintf (buffer, "Hola Mundo!\n");

	//Copia el espacio del kernel al espacio de usuario usr_buf
	copy_to_user(usr_buf, buffer, rv);

	return rv;
}

//Macros para registrar los puntos de entrada y salida del modulo
module_init (proc_init);
module_exit (proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION(" Modulo de kernel");
MODULE_AUTHOR("SIO115");