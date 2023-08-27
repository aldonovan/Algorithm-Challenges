#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  srandom(time(NULL));
  printf("I am unique and just get printed once\n");
  pid_t pid = fork();
  bool parent = pid != 0;
  if((random() % 2 == 0) == parent) sleep(1);
  if(parent) waitpid(pid, NULL, 0); //parent waits for Child
  printf("I get printed twice (this one is from %s)\n", parent ? "parent": "child");

  //At most one process sleeps because random() returns same for both (same seed)
}
