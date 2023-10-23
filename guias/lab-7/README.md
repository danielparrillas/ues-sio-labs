1. Identificar el número de interrupción apropiado y adecúe la definición del código fuente `INTERRUPT_ID`

```bash
cat /proc/interrupts
```

2. Compilar

```bash
make
```

3. Instalar módulo

```bash
sudo insmod ih.ko
```

4. Verificar si el módulo se instaló correctamente y si los mensajes personalizados del controlador de interrupciones se informan en el registro del kernel

```bash
dmesg
```

```bash
cat /proc/interrupts
```

5. Desinstalar módulo

```bash
sudo rmmod ih
```