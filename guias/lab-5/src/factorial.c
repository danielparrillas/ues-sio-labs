#include "factorial.h"

unsigned long long factorial (int num) {
  unsigned long long fact = 1;
  for (int i = 1; i <= num; ++i) {
    fact *= i;
  }
  return fact;
}