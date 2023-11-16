/**
 * Alumno: Brandon Daniel Parrillas Sánchez ༼ つ ◕_◕ ༽つ
 * Carnet: PS19005
 */
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h> // constantes definidas
#include <sys/shm.h> // contiene las funciones principales
#include <stdlib.h>

int main()
{
  // ftko para generar llave única, (el enunciado lo pedira como parametro)
  // key_t key = ftok("memory", 67); //! probablemente no se utilizara el el lab04
  key_t key = 2019; // (el enunciado no dira nada o lo pedira como llave)

  // shmet regresa un identificador en shmid
  int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
  if (shmid == -1)
  {
    printf("No se pudo crear el segmento de memoria compartida.\n");
    exit(1); //! falta en la guía
  }
  // shmat agregar a memoria compartida
  char *str = (char *)shmat(shmid, (void *)0, 0);

  //?De aqui para abajo cambia ( ͡° ͜ʖ ͡°) ↓

  printf("Ingrese un mensaje a guardar en memoria compartida: ");
  scanf("%[^\n]s", str);                          //! no se utilizara, en el evaluado se hara a travez de la línea de comandos
  printf("Datos escritos en memoria: %s\n", str); // Engaños, todavia no se garantiza que se hayan guardado

  //?De aqui para arriba cambia ↑

  // quitar de memoria compartida
  shmdt(str);
  return 0;
}