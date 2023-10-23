# Creando el modulo
> El archivo debe llamarse `Makefile` 
- El comando que compila se llama make
- Para cargar el modulo el comando es:

```bash
sudo insmod simple.ko
```

# Agregando el modulo

Para listar los modulos
```bash
lsmod
```

Para listar el mensaje en el bufer de registro del kernel
```bash
dmesg
```

Para eliminar el modulo del kernel
> El sufijo `.ko` no es nencesario

```bash
sudo rmmod simple
```

# Limpiar el bufer

```bash
sudo dmesg -C
```