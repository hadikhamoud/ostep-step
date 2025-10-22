#include <stdio.h>
#include <sys/time.h>

int main() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  printf("Seconds since epoch: %ld\n", tv.tv_sec);
  printf("microseconds : %ld\n", tv.tv_usec);
  return 0;
}
