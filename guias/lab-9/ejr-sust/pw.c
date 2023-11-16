/**
 * Autor: Brandon Daniel Parrillas Sánchez
 * Objetivo: Recibir una serie de número enteros y guardarlos en memoria compartida
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

const int CANTIDAD = 4;
const int PERMISO = 0666;
const int LLAVE = 1212;

// Función para validar los argumentos
int validarArgumentos(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Uso: %s <numero>\n", argv[0]);
    return 0; // indica que los argumentos no son validos
  }

  return 1; // los argumentos son válidos
}

int main(int argc, char *argv[])
{
  // Validar argumentos
  if (!validarArgumentos(argc, argv))
  {
    return -1;
  }

  // valor arbitrario de la llave
  key_t llave = LLAVE;

  // definir las caracteristicas de la memoria compartida
  int memoriaId = shmget(llave, sizeof(long), PERMISO | IPC_CREAT); //! shmget([llave], [tamaño en bytes], []);
  // int memoriaId = shmget(llave, sizeof(int) * CANTIDAD, 0666 | IPC_CREAT); tamaño para n cantidad de enteros

  if (memoriaId == -1)
  {
    printf("No se pudo crear el segmento de memoria\n");
    exit(-1);
  }

  // Crear el segmento de memoria compartida
  // se asocia a una variable
  long *data = (long *)shmat(memoriaId, (void *)0, 0);

  // proceso
  // guardar los datos pasados como parametros en la memoria compartida
  *data = atol(argv[1]);
  printf("El valor guardado es: %ld\n", *data);

  // desasociar la memoria compartida
  shmdt(data);

  return 0;
}