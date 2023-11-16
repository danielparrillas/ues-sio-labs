/**
 * Autor: Brandon Daniel Parrillas Sánchez
 * Objetivo: Recibir una serie de número enteros y guardarlos en memoria compartida
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>b
#include <sys/shm.h>

const int CANTIDAD = 4;
const int PERMISO = 0666;
const int LLAVE = 1212;

// Función para validar los argumentos
int validarArgumentos(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Uso: %s <numero 1> <numero 2> ... <nmero n>\n", argv[0]);
    return 0; // indica que los argumentos no son validos
  }

  for (int i = 1; i < argc; i++)
  {
    char *p;
    strtol(argv[i], &p, 10);
    if (*p != '\0')
    {
      printf("Argumento no valido: %s\n", argv[i]);
      return 0; // no es un entero vlido
    }
  }

  return 1; // Todos los argumentos son válidos
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
  int memoriaId = shmget(llave, 512, PERMISO | IPC_CREAT); // shmget([llave], [tamaño en bytes], []);
  // int memoriaId = shmget(llave, sizeof(int) * CANTIDAD, 0666 | IPC_CREAT); tamaño para n cantidad de enteros

  if (memoriaId == -1)
  {
    printf("No se pudo crear el segmento de memoria\n");
    exit(-1);
  }

  // Crear el segmento de memoria compartida
  // se asocia a una variable
  int *data = (int *)shmat(memoriaId, (void *)0, 0);

  // proceso
  // guardar los datos pasados como parametros en la memoria compartida
  data[0] = argc - 1; // En la primera posición se guarda el tamaño del arreglo
  for (int i = 1; i < argc; i++)
  {
    data[i] = atoi(argv[i]);
  }

  // desasociar la memoria compartida
  shmdt(data);

  return 0;
}