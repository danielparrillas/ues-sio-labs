/**
 * 1. Ejecute el siguiente código y analice la salida del mismo. Modifique el programa para que los
valores de las variables g y loc sean ingresados desde la línea de comandos (utilice como
ejemplo el código base del ejercicio 3)
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int g;

int main(int argc, char *argv[])
{
  pid_t pid;
  int loc;

  if(argc != 3) {
    printf("Se esperaban 2 parametros, se recibieron %d\n", argc - 1);
    return 1;
  }

  printf("Los datos ingresados son: ");
  for (int i = 1; i < argc; i++) {
    printf("%d ", atoi(argv[i]));
  }
  printf("\n");
  
  g = atoi(argv[1]);
  loc = atoi(argv[2]);

  switch (fork())
  {
  case -1:
    fprintf(stderr, "fork() falló");
    return 1;
  case 0:
    printf("Proceso hijo, PID %d:\n", getpid());
    loc++;
    g--;
    printf(" loc=%d g=%d\n", loc, g);
    printf("Proceso hijo (%d) finalizado\n", getgid());
    break;

  default:
    wait(NULL);
    printf("Proceso padre, PID %d:\n", getpid());
    loc++;
    g--;
    printf(" loc=%d g=%d\n", loc, g);
    printf("Proceso padre (%d) finalizado\n", getegid());
  }

  return 0;
}