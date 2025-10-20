#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int rc = fork();
  int status;

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello child %d \n", 0);
    pid_t pid = waitpid(rc, &status, 0);
  } else {
    printf("hello parent %d \n", 0);
  }
  return 0;
}
