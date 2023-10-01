/**
 * 1. Ejecute el siguiente código y analice la salida del mismo.
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int g = 7;

int main()
{
  pid_t pid;
  int loc = 8;

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