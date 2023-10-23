#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/param.h>
#include <linux/jiffies.h>

static unsigned long jiffies_at_load;

int simple_init(void) {
    printk(KERN_ALERT "Cargando modulo de kernel \n");
    printk(KERN_NOTICE "Frecuencia de interruciones del temporizador: %llu \n", HZ);
    jiffies_at_load = jiffies; 
    return 0;
}

// seconds = jiffies / HZ
void simple_exit(void) {
    unsigned long jiffies_at_unload = jiffies;
    unsigned long seconds_elapsed;

    //calcular la cantidad de segundos transcurridos
    seconds_elapsed = (jiffies_at_unload - jiffies_at_load) / HZ;

    printk(KERN_INFO "Removiendo modulo de kernel \n");
    printk(KERN_NOTICE "Numero de interruciones desde que se inicio el sistema: %lu \n", jiffies); 

    printk(KERN_ALERT "Segundos transcurridos: %lu\n", seconds_elapsed);
}

module_init (simple_init);
module_exit (simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION(" Modulo de kernel Ejercicio 1");
MODULE_AUTHOR("PS19005");