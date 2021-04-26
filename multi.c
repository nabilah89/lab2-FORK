#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
void childTask() {
  printf("Hello i am kid\n");
}
 
void parentTask() {
  printf("hi,and i am his father\n");
}
 
int main(void) {
  pid_t pid = fork();
 
  if(pid == 0) {
    childTask();
    exit(EXIT_SUCCESS);
  }
  else if(pid > 0) {
    wait(NULL);
    parentTask();
  }
  else {
    printf("Unable to create child process.");
  }
 
  return EXIT_SUCCESS;
}
