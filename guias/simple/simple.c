#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hash.h> //funciones hash dentro del kernel GOLDEN_RATIO_PRIME
#include <linux/gcd.h> //funciones gcd

// KERN_EMERG
// KERN_ALERT
// KERN_ERR
// KERN_CRIT
// KERN_WARNING
// KERN_NOTICE
// KERN_INFO
// KERN_DEBUG

int simple_init(void) {
    printk(KERN_ALERT "Cargando modulo de kernel \n");
    // printk(KERN_INFO "%llu \n", GOLDEN_RATIO_PRIME); 
    return 0;
}

void simple_exit(void) {
    unsigned long result;
    printk(KERN_INFO "Removiendo modulo de kernel \n");
    result = gcd(3300, 24);
    printk(KERN_INFO "Maximo comun divisor de 3300 y 24: %lu\n", result);
}

module_init (simple_init);
module_exit (simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION(" Modulo de kernel");
MODULE_AUTHOR("SIO115");