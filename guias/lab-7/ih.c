#include <linux/interrupt.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Ejemplo de controlador de dispositivo de caracteres");
MODULE_AUTHOR("Brandon Daniel Parrillas Sanchez");
MODULE_VERSION("0.O1");

#define INTERRUPT_ID 74; //Adecuar el número según el número de la interrupción deseada

static int count = 0;
static char* dev = "mi manejador de interrupción"

static irqreturn_t custom_interrupt(int irq, void *dev_id) {
  if(count++%50 == 0) {
    printk("Mi controlador de interrupción ha sido llamado");
  }
  return IRQ_HANDLED;
}

static int simple_driver_init(void) {
  int result = 0;
  result = request_irq(INTERRUPT_ID, custom_interrupt, IRQF_SHARED, "mi-controlador-interrupcion", (void *)&dev);
  if(result < 0) {
    printk(KERN_ERR "Controlador: no se pudo registrar la interrupción %d\n", INTERRUPT_ID);
    return -EIO;
  }
  return result;
}

static void simple_driver_exit(void) {
  free_irq(INTERRUPT_ID, (void *)&dev);
}

module_init(simple_driver_init);
module_exit(simple_driver_exit);