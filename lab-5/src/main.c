#include <stdio.h>
#include "factorial.h"

int main() {
  int num = 7;

  if (num < 0) {
    printf("El número debe ser positivo o 0");
  } else {
    printf("Factorial de %d = %llu\n", num, factorial(num));
  }

  return 0;
}