/**
 * 3. Escriba un programa multiproceso que calcule varios valores estadísticos para una lista de números. A este programa se le pasará una serie de números en la línea de comando y luego creará tres subprocesos de trabajo separados.
 * Un proceso determinará el promedio de los números, el segundo determinará el valor máximo y el tercero determinará el valor mínimo.
 * Por ejemplo, suponga que a su programa se llama “calculos” y se le pasan números enteros de la siguiente forma:
 * $ ./calculos 90 81 78 95 79 72 85
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void calcular_promedio(int numeros[], int n);
void calcular_minimo(int numeros[], int n);
void calcular_maximo(int numeros[], int n);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Por favor, introduce una lista de números como argumentos.\n");
    return 1;
  }

  printf("Los datos ingresados son: ");
  for (int i = 1; i < argc; i++) {
    printf("%d ", atoi(argv[i]));
  }
  printf("\n");

  int n = argc - 1;
  int numeros[n];

  for (int i = 0; i < n; i++) {
    numeros[i] = atoi(argv[i + 1]);
  }

  pid_t pid_promedio, pid_minimo, pid_maximo;

  // Proceso para calcular el promedio
  if ((pid_promedio = fork()) == 0) {
    srandom(getpid());
    sleep(random() % 5);
    calcular_promedio(numeros, n);
    exit(0);
  }

  // Proceso para calcular el valor mínimo
  if ((pid_minimo = fork()) == 0) {
    srandom(getpid());
    sleep(random() % 5);
    calcular_minimo(numeros, n);
    exit(0);
  }

  // Proceso para calcular el valor máximo
  if ((pid_maximo = fork()) == 0) {
    srandom(getpid());
    sleep(random() % 5);
    calcular_maximo(numeros, n);
    exit(0);
  }

  waitpid(pid_promedio, NULL, 0);
  waitpid(pid_minimo, NULL, 0);
  waitpid(pid_maximo, NULL, 0);

  return 0;
}


void calcular_promedio(int numeros[], int n)
{
  int suma = 0;
  for (int i = 0; i < n; i++)
  {
    suma += numeros[i];
  }
  printf("El promedio es %d\n", suma / n);
}

void calcular_minimo(int numeros[], int n)
{
  int minimo = numeros[0];
  for (int i = 1; i < n; i++)
  {
    if (numeros[i] < minimo)
      minimo = numeros[i];
  }
  printf("El valor mínimo es %d\n", minimo);
}

void calcular_maximo(int numeros[], int n)
{
  int maximo = numeros[0];
  for (int i = 1; i < n; i++)
  {
    if (numeros[i] > maximo)
      maximo = numeros[i];
  }
  printf("El valor máximo es %d\n", maximo);
}
