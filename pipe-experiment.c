#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

static const int kPipeFailed = 1;
static const int kForkFailed = 2;

int main(int argc, char *argv[]) {
  int fds[2]; //fds[0] is the reader, fds[1] is the writer
  pipe(fds);
  pid_t pid = fork();
  if(pid == 0) {
    //child will read from the pipe
    close(fds[1]); //no need to write
    char buffer[6];
    read(fds[0], buffer, sizeof(buffer));
    printf("Read from pipe bridging the processes: %s\n", buffer);
    close(fds[0]); //done reading
    return 0;
  }
  //parent
  close(fds[0]);
  write(fds[1], "hello", 6);
  waitpid(pid, NULL, 0);
  close(fds[1]);
  return 0;
}
