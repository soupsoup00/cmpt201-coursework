#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int pid = fork();
  if (pid == 0) {
    printf("child, %d, %d\n", getpid(), getppid());
  } else {
    printf("parent, %d, %d\n", getpid(), pid);
  }

  return 0;
}
