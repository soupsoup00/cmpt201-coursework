#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) { // child
    execlp("ls", "ls", "-al");
    //   printf("child, %d, %d\n", getpid(), getppid());
  } else {
    //    printf("parent, %d, %d\n", getpid(), pid);
    // execlp("ls", "ls", "-a");
    int wstatus = 0;
    if (waitpid(pid, &wstatus, 0) == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }

    if (WIFEXITED(wstatus)) {
      printf("exit status %d\n", WEXITSTATUS(wstatus));
    }
  }
  printf("%d\n", getpid()); // wont print bc of execs ^^
  return 0;
}
