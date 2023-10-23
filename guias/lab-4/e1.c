/**
 * *1. Escriba el siguiente programa y explique la salida obtenida en la línea printf("PADRE: valor = %d", value);
 */
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main () {
  pid_t pid;
  pid = fork();

  if (pid == 0) { //proceso hijo
    value += 15;
    // printf("HIJO: valor = %d", value);
    printf("\n");
    return 0;
  } else if(pid > 0) { //proceso padre
    wait(NULL);
    printf("PADRE: valor = %d", value);
    printf("\n");
    return 0;
  }
}

/**
 * En resumen, el programa creará un proceso hijo que modificará su propia copia de la variable value y luego terminará. El proceso padre imprimirá el valor original de value ya que la modificación hecha por el hijo no afecta la copia del padre de la variable. Entonces, aunque la línea printf("HIJO: valor = %d", value); está comentada, si decides descomentarla y ejecutar el código, la salida será algo así:
 * HIJO: valor = 20
 * PADRE: valor = 5
 *
 * Cuando se crea un proceso hijo mediante la función fork(), el sistema operativo realiza una copia completa del espacio de memoria del proceso padre para el proceso hijo. Esto significa que el proceso hijo recibe su propia copia de todas las variables, y cualquier cambio que el proceso hijo realice en sus variables no afectará las variables del proceso padre. Los dos procesos no comparten memoria; operan en espacios de memoria separados.
 */
