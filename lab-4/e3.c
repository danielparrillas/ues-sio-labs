/**
 * *3. Compile y ejecuta el código siguiente y conteste las siguientes preguntas:
 * ¿Por qué aparecen mensajes repetidos?
 * Preste atención al orden de terminación de los procesos ¿Qué observa? ¿Por qué?
 */
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
  int num;
  pid_t pid;

  for (num = 0; num < 3; num++) {
    pid = fork();
    printf("%d.Soy el proceso de PID %d y mi padre tiene %d de PID.\n",num, getpid(), getppid());
    if (pid != 0) { //saldra cuando sea el proceso padre
      break;
    }
    srandom(getpid());
    sleep(random() % 3);
  }

  if(pid != 0) { //si es el proceso padre
    printf("Fin del proceso PID %d con padre %d.\n", wait(NULL), getpid());
  }

  return 0;
}