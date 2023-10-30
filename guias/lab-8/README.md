# Guía de laboratorio 8

## Comandos

Encontrar el tamaño de página configurado de su sistema en bytes. `getconf PAGESIZE`

`cat /proc/meminfo`

Muestra estadísticas de la memoria virtual `vmstat`

```bash
daniel@BrandonParrillas:~/ues/ues-sio-labs/guias/lab-8$ /usr/bin/time ./major alice.txt
total = 13951
0.00user 0.00system 0:00.06elapsed 1%CPU (0avgtext+0avgdata 1480maxresident)k
344inputs+0outputs (3major+64minor)pagefaults 0swaps
daniel@BrandonParrillas:~/ues/ues-sio-labs/guias/lab-8$ /usr/bin/time -v ./major alice.txt
total = 13951
        Command being timed: "./major alice.txt"
        User time (seconds): 0.00
        System time (seconds): 0.00
        Percent of CPU this job got: 1%
        Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.05
        Average shared text size (kbytes): 0
        Average unshared data size (kbytes): 0
        Average stack size (kbytes): 0
        Average total size (kbytes): 0
        Maximum resident set size (kbytes): 1488
        Average resident set size (kbytes): 0
        Major (requiring I/O) page faults: 3
        Minor (reclaiming a frame) page faults: 66
        Voluntary context switches: 3
        Involuntary context switches: 0
        Swaps: 0
        File system inputs: 344
        File system outputs: 0
        Socket messages sent: 0
        Socket messages received: 0
        Signals delivered: 0
        Page size (bytes): 4096
        Exit status: 0
```

> El programa se ejecutó en el archivo alice.txt. El total impreso, 13951, es la suma de los bytes ubicados en las posiciones múltiples de 1024 en el archivo.

> El tiempo empleado por el programa es mínimo (0.00 segundos para el usuario y sistema). El tamaño máximo de memoria residente fue de 1488 KB. Hubo 3 fallos de página mayores (requiere E/S) y 66 fallos de página menores. Esto indica que el programa tuvo que cargar partes del archivo desde el disco en 3 ocasiones y reutilizar/recuperar marcos de memoria en 66 ocasiones.

> El detalle proporcionado por el comando /usr/bin/time -v da una visión más detallada de las estadísticas, pero en esencia confirma la información inicial.