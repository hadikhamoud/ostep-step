#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define ITERATIONS 100000

void set_cpu_affinity() {
  cpu_set_t my_set;
  CPU_ZERO(&my_set);
  CPU_SET(0, &my_set);
  sched_setaffinity(0, sizeof(cpu_set_t), &my_set);
}

int main(void) {
  int p1[2], p2[2];
  pipe(p1);
  pipe(p2);

  set_cpu_affinity();

  pid_t pid = fork();
  if (pid == 0) {
    set_cpu_affinity();
    char msg = 'x';
    for (int i = 0; i < ITERATIONS; i++) {
      read(p1[0], &msg, 1);
      write(p2[1], &msg, 1);
    }
    exit(0);
  } else {
    struct timeval start, end;
    char msg = 'x';
    gettimeofday(&start, NULL);

    for (int i = 0; i < ITERATIONS; i++) {
      write(p1[1], &msg, 1);
      read(p2[0], &msg, 1);
    }

    gettimeofday(&end, NULL);
    long elapsed =
        (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

    double avg = (double)elapsed / (ITERATIONS * 2);
    printf("Average context switch time: %.3f microseconds\n", avg);
  }

  return 0;
}
