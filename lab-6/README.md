1. Mostrará información sobre los dispositivos que están conectados a través de algún puerto USB

```bash
lsusb
```

2. Mostrará información sobre los dispositivos de bloque, que generalmente son dispositivos de almacenamiento

```bash
lsblk
```

3. Compilar el archivo utilizando el archivo Makefile
```bash
make
```

4. Cargar el driver al kernel
```bash
sudo insmod program.ko
```

5. Verificar que el dispositivo ha sido agregado al archivo /proc/devices
```bash
cat /proc/devices
```

6. Demostración
> Usamos este identificador para "adjuntar" el controlador a un archivo de dispositivo, mediante el comando mknod. Y luego leeremos ese archivo para mostrar el funcionamiento. Así como se muestra en los comandos de la siguiente imagen

```bash
DEVNUM=`cat /proc/devices | grep Mi-Dispositivo | cut -d' ' -f 1`
sudo mknod /dev/mydev c $DEVNUM 0
cat /dev/midev
```