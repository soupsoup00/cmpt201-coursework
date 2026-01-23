#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t input;
  bool run = true;

  while (run) {
    printf("Enter programs to run.\n");
    input = getline(&line, &len, stdin);
    char *str = line;

    if (input != -1) {
      str[strcspn(str, "\n")] = '\0';

      pid_t cpid = fork();
      if (cpid == 0) {                 // if this is child process
        execl(str, str, (char *)NULL); // execute command
      } else if (cpid != 0) {
        int wstatus;
        if ((waitpid(cpid, &wstatus, 0)) == -1) {
          exit(EXIT_FAILURE);
        } else if (WIFEXITED(wstatus)) {
          // printf("exited, status=%d\n", WEXITSTATUS(wstatus));
        } else if (WIFSIGNALED(wstatus)) {
          printf("killed by signal %d\n", WTERMSIG(wstatus));
        }
      }
      // parse user input - strtok
      // fork into child and thru child run exec(input command)
      // waitpid for child to terminate before looping process
    } else {
      printf("failed to read line\n");
    }
    free(line);
  }
}
