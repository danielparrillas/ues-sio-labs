#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;

  // Bifurcar a un proceo hijo
  pid = fork();

  if (pid < 0)
  {
    fprintf(stderr, "Fork falló");
    return 1;
  }
  else if (pid == 0)
  {
    execlp("/bin/pwd", "listado", NULL);
    // execlp("/bin/ls", "listado", NULL);
    return 1;
  }
  else
  {
    // Proceso padre espera que el proceso hijo se complete
    wait(NULL);
    printf("Proceso hijo completado\n");
  }
  return 0;
}