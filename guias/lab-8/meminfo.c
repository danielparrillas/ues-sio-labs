#include <stdio.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main()
{
  int pages = get_phys_pages();
  int pagesize = getpagesize(); // in bytes
  double ramGB = ((double)pages * (double)pagesize / 1024 / 1024 / 1024);
  printf("RAM Size %.2f GB, Page Size %d B\n", ramGB, pagesize);
  return 0;
}