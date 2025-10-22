#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define ITERATIONS 1000000000

int main(void) {
  struct timeval start, end;
  long elapsed;
  int fd = 0; // stdin
  char buf[1];
  long total_time = 0;

  for (int i = 0; i < ITERATIONS; i++) {
    gettimeofday(&start, NULL);
    read(fd, buf, 0);
    gettimeofday(&end, NULL);

    elapsed =
        (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
    total_time += elapsed;
  }

  double avg = (double)total_time / ITERATIONS;
  printf("Average system call cost: %.3f microseconds\n", avg);

  return 0;
}
