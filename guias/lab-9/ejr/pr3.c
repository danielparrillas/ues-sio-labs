/**
 * Autor: Brandon Daniel Parrillas Sánchez
 * Objetivo: Leer desde memoria compartida el arreglo de enteros y obtener el valor maximo y minimo
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int obtenerMinimo(int *datos, int tamano)
{
  int minimo = datos[1];
  for (int i = 1; i <= tamano; i++)
  {
    if (datos[i] < minimo)
    {
      minimo = datos[i];
    }
  }
  return minimo;
}

int obtenerMaximo(int *datos, int tamano)
{
  int maximo = datos[1];
  for (int i = 1; i <= tamano; i++)
  {
    if (datos[i] > maximo)
    {
      maximo = datos[i];
    }
  }
  return maximo;
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

  printf("El valor mínimo es: %i\n", obtenerMinimo(data, data[0]));
  printf("El valor máximo es: %i\n", obtenerMaximo(data, data[0]));

  // Desasociar la memoria compartida
  shmdt(data);

  // Liberar la zona de memoria compartida
  shmctl(memoriaId, IPC_RMID, NULL);

  return 0;
}
