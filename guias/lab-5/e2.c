/**
 *  Modifique el programa para que realice de forma paralela el cálculo del factorial de los dos números.
*/
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "./src/factorial.h"

int main() {
  pid_t pid_fact1, pid_fact2, pidfin;
  int num1 = 30;
  int num2 = 1;

  if (num1 < 0 || num2 < 0) {
    printf("Los números deben ser positivos o 0");
    exit(0);
  }

  pid_fact1 = fork();
  if (pid_fact1 < 0) {
        perror("Error en fork");
        exit(1);
    }
  if (pid_fact1 == 0) {
    printf("1.Factorial de %d = %llu\n", num1, factorial(num1));
    exit(0);
  }
  
  pid_fact2 = fork();
  if (pid_fact2 < 0) {
        perror("Error en fork");
        exit(1);
    }
  if (pid_fact2 == 0) {
    printf("2.Factorial de %d = %llu\n", num2, factorial(num2));
    exit(0);
  }

  for (int i = 0; i < 2; i++) {
    wait(NULL);
  }
  printf("Calculos realizados\n");
  return 0;
}