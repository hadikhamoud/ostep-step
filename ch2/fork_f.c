#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){
  int rc = fork();
  int fd = open("test.txt", O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);

  if (rc<0){
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0){
    char data[] = "hello from child!\n";
    write(fd, data, sizeof(data)-1);
    printf("value for fdescriptor in child %d \n", fd);
  }
  else{

    char data[] = "hello from parent!\n";
    write(fd, data, sizeof(data)-1);
    printf("value for fdescriptor in parent %d \n", fd);
  }
  return 0;
}

