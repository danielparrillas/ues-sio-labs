/**
 * Autor: Brandon Daniel Parrillas Sánchez
 * Objetivo: Leer desde memoria compartida, el arreglo de enteros y calcular el promedio
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

float calcularPromedio(int *datos, int tamano)
{
  int suma = 0;
  for (int i = 1; i <= tamano; i++)
  {
    suma += datos[i];
  }
  return (float)suma / tamano;
}

int main()
{
  // valor arbitrario de la llave
  key_t llave = 1212;

  // definir las caracteristicas de la memoria compartida
  int memoriaId = shmget(llave, 512, 0666 | IPC_CREAT); // shmget([llave], [tamaño en bytes], []);
  // int memoriaId = shmget(llave, sizeof(int) * [n], 0666 | IPC_CREAT); tamaño para n cantidad de enteros
  if (memoriaId == -1)
  {
    printf("No se pudo crear el segmento de memoria\n");
    exit(-1);
  }

  // Crear el segmento de memoria compartida
  // se asocia a una variable
  int *data = (int *)shmat(memoriaId, (void *)0, 0);

  // Llamada a la función calcularPromedio
  float promedio = calcularPromedio(data, data[0]);

  printf("El promedio es: %.2f\n", promedio);

  // Desasociar la memoria compartida
  shmdt(data);

  return 0;
}
