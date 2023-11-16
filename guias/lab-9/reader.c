/**
 * Alumno: Brandon Daniel Parrillas Sánchez ༼ つ ◕_◕ ༽つ
 * Carnet: PS19005
 */
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
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

  printf("Datos leídos desde memoria: %s\n", str);

  //?De aqui para arriba cambia ↑

  // quitar de memoria compartida
  shmdt(str);

  // destruir la memoria compartida
  shmctl(shmid, IPC_RMID, NULL); //! esto solo se realiza en el ultimo que utiliza la memoria compartida

  return 0;
}
