/**
 * *2. Escriba el siguiente programa y explique los valores que se muestran en las líneas;
 * printf("Hijo: pid = %d\n", pid);
 * printf("Hijo: pid1 = $d\n", pid1);
 * printf("Padre: pid = %d\n", pid);
 * printf("Padre: pid1 = %d\n", pid1);
 */
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main () {
  pid_t pid, pid1;
  pid = fork();

  if (pid < 0) {
    fprintf(stderr, "fork() falló\n");
    return 1;
  } else if (pid == 0) {
    pid1 = getpid();
    printf("Hijo: pid = %d\n", pid);
    printf("Hijo: pid1 = %d\n", pid1);
  } else {
    pid1 = getpid();
    printf("Padre: pid = %d\n", pid);
    printf("Padre: pid1 = %d\n", pid1);
    wait(NULL);
  }
  return 0;
}

/**
 * La función fork() devuelve 0 en el proceso hijo por diseño, y esto sirve para diferenciar entre el proceso hijo y el proceso padre después de que se haya realizado la bifurcación (fork).
 * 
 * *Resultado:
 * Padre: pid = 10320
 * Padre: pid1 = 10319
 * Hijo: pid = 0
 * Hijo: pid1 = 10320
 *
 * Lo que significa,
 * *Para el proceso padre:
 * pid es el número de proceso del hijo y pid1 es su propio numero de proceso, por eso el pid le sigue al pid1
 *
 * *Para el proceo hijo:
 * pid1 coincide con el pid del padre, ya que son el mismo proceso
 */