/**
 * Autor: Brandon Daniel Parrillas Sánchez
 * Objetivo: Leer desde memoria compartida..
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
  // valor arbitrario de la llave
  key_t llave = 1212;

  // definir las caracteristicas de la memoria compartida
  int memoriaId = shmget(llave, sizeof(long), 0666 | IPC_CREAT); // shmget([llave], [tamaño en bytes], []);
  // int memoriaId = shmget(llave, sizeof(int) * [n], 0666 | IPC_CREAT); tamaño para n cantidad de enteros
  if (memoriaId == -1)
  {
    printf("No se pudo crear el segmento de memoria\n");
    exit(-1);
  }

  // Crear el segmento de memoria compartida
  // se asocia a una variable
  long *data = (long *)shmat(memoriaId, (void *)0, 0);

  printf("El calculo es: %ld\n", *data);

  // Desasociar la memoria compartida
  shmdt(data);

  // Liberar la zona de memoria compartida
  shmctl(memoriaId, IPC_RMID, NULL);

  return 0;
}
