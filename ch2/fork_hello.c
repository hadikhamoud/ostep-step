#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char *argv[]){
  struct sigaction sa;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_RESTART | SA_NOCLDWAIT;

  int rc = fork();

  if (sigaction(SIGCHLD, &sa, 0) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    if (rc<0){
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0){
    printf("hello child %d \n", 0);
  }
  else{
    printf("hello parent %d \n", 0);
  }
  return 0;
}

