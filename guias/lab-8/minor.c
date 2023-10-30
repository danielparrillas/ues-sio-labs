#include <stdlib.h>

/*assume 4KB page size*/

const int PAGES = 1024 * 4;

int main(int argc, char **argv)
{
  char *p = 0;
  int i = 0, j = 0;

  /*n is number of pages*/
  int n = 100;
  if (argc == 2)
  {
    n = atoi(argv[1]);
  }
  p = (char *)malloc(PAGES * n);
  for (i = 0; i < PAGES; i++)
  {
    for (j = 0; j < PAGES * (n - 1); j += PAGES)
    {
      p[(i + j)] = 42;
    }
  }
  return 0;
}