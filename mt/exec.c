#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int pid = fork();
  if (pid == 0) {
    execlp("ls", "ls", "-alh");
    //   printf("child, %d, %d\n", getpid(), getppid());
  } else {
    //    printf("parent, %d, %d\n", getpid(), pid);
    execlp("ls", "ls", "-a");
  }
  printf("%d\n", getpid()); // wont print bc of execs ^^
  return 0;
}
