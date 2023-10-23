/***************
Archivo: lab.2
Descripcion: Calculo simultaneo de la conjetrua de Collatz para los parametros pasados por la linea de comando utilizadn multiproceso

Autor: Brandon Daniel Parrillas Sánchez
Carnet: PS19005
Materia: COS
Evaluacion: Laboratorio 2
Fecha: 01/10/2023

- Documentación del programa (5%)
- Organización del código (3%)
- Uso de parámetros por línea de comandos (validación de que sean enteros positivos) . (10%)
- Función que realiza el cálculo de la conjetura de Collatz. (30%)
0 Uso correcto del fork para realizar los cálculos concurrentes. (20%)
0 Correcta finalización de procesos hijos. (10%)
0 Mostrar mensajes de finalización de procesos hijos (PID de cada proceso hijo finalizado). (20%)
- Entrega (2%)
****************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void collatz(int numero);

int main(int argc, char *argv[]) {
  if(argc < 2) { //validacion de que se ingrese parametros en linea
    fprintf(stderr, "Por favor, introduce una lista de números como argumentos mayor a 0.\n");
    return 1;
  }

  int n = argc -1;
  int numeros[n];

  for (int i = 0; i < n; i++) {
    numeros[i] = atoi(argv[i + 1]);
    if(numeros[i] <= 0) { //validacion de que sean numero enteros > 0
      fprintf(stderr, "Por favor, introduce una lista de números como argumentos mayor a 0.\n");
      return(1);
    }
  }

  pid_t pid;

  //se recorren los numero creando un subproceso para cada uno para calcular la conjetura de collatz
  for (int i = 0; i< n; i++) {
    pid = fork();
    collatz(numeros[i]);
    if (pid != 0) { //saldra cuando sea el proceso padre
      break;
    }
    //Probando la concurrencia
    srandom(getpid());
    sleep(random() % 3);
  }

  if(pid != 0) {
    printf("Fin del proceso PID %d con padre %d.\n", wait(NULL), getpid());
  }

  return 0;
}

void collatz(int n) {
  printf("%i ", n);
  while (n != 1) {
    if(n % 2 == 0) {
      n = n / 2;
    } else {
      n = 3 * n + 1;
    }
    printf("%i ", n);
  }
  printf("\n");
}