#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

size_t get_size(const char *filename)
{
  struct stat st;
  stat(filename, &st);
  return st.st_size;
}

int main(int argc, char **argv)
{
  int i, total = 0;
  size_t filesize = get_size(argv[1]);
  int fd = open(argv[1], O_RDONLY, 0);
  char *data;
  assert(fd != -1);
  posix_fadvise(fd, 0, filesize, __POSIX_FADV_DONTNEED);
  data = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE | MAP_NONBLOCK, fd, 0);
  assert(data != MAP_FAILED);
  for (i = 0; i < filesize; i += 1024)
  {
    total += data[i];
  }
  printf("total = %d\n", total);
  int rc = munmap(data, filesize);
  assert(rc == 0);
  close(fd);
}