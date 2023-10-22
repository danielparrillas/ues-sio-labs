#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Ejemplo de controlador de dispositivo de caracteres");
MODULE_AUTHOR("Brandon Daniel Parrillas Sanchez");

static const char *fortytwo = "*";

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
      return -EFAULT
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
  int result = register_device();
  return result;
}

static void simple_driver_exit(void)
{
  unregister_device();
}

module_init(simple_driver_init);
module_exit(simple_driver_exit);