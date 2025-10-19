#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello child %d \n", 0);
    execl("/bin/ls", "ls", "-l", "/Users/hadihamoud/Desktop", (char *)NULL);
  } else {
    printf("hello parent %d \n", 0);
  }
  return 0;
}
