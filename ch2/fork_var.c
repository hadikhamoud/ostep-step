#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){
  int x = 100;
  int rc = fork();
  x++;

  if (rc<0){
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0){
    x++;
    printf("value for x in child %d \n", x);
  }
  else{
    x++;
    printf("value for x in parent %d \n", x);
  }
  return 0;
}

