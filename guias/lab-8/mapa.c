#include <stdio.h>
#include <stdlib.h>

int uig;
int ig = 5;

int func()
{
  return 0;
}

int main()
{
  int local;
  int *ptr;
  ptr = (int *)malloc(sizeof(int));

  printf("Una dirección del BSS:%p \n", &uig);
  printf("Una dirección del segmento de datos:%p \n", &ig);
  printf("Una dirección del segmento de código:%p \n", &func);
  printf("Una dirección del segmento de pila:%p \n", &local);
  printf("Una dirección de la pila: %p \n", ptr);
  printf("Otra dirección de la pila: %p \n", &ptr);
  free(ptr);
  return 0;
}