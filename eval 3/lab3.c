#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>
// #include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Mostrar el tiempo que lleva cargado el manejador de  interrupción cada X tiempo");
MODULE_AUTHOR("Brandon Daniel Parrillas Sanchez");
MODULE_VERSION("PS19005");

static const char *fortytwo = "*";
// static const int x = 5;
// static unsigned long jiffies_inicio;
// static long contador = 0;

static ssize_t device_file_read(
    struct file *file_ptr,
    char __user *user_buffer,
    size_t count,
    loff_t *position)
{
  int i = count;
  while (i--)
  {
    if (copy_to_user(user_buffer, fortytwo, 1) != 0)
    {
      return -EFAULT;
    }
  }
  return count;
}

static struct file_operations driver_fops = {
    .owner = THIS_MODULE,
    .read = device_file_read};

static int device_file_major_number = 0;
static const char device_name[] = "Mi-Dispositivo";

static int register_device(void)
{
  int result = 0;
  result = register_chrdev(0, device_name, &driver_fops);
  if (result < 0)
  {
    printk(KERN_WARNING "Mi-Dispositivo no se pudo registrar, código de error %i", result);
    return result;
  }
  device_file_major_number = result;
  return 0;
}

static void unregister_device(void)
{
  if (device_file_major_number != 0)
  {
    unregister_chrdev(device_file_major_number, device_name);
  }
}

static int simple_driver_init(void)
{
  printk(KERN_INFO "Mi controlador PS19005 \n");
  int result = register_device();
  return result;
}

static void simple_driver_exit(void)
{
  result = 3;
  printk(KERN_INFO "Tiempo total de módulo activo: %lu\n", result);
  unregister_device();
}

module_init(simple_driver_init);
module_exit(simple_driver_exit);