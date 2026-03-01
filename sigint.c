#define _POSIX_C_SOURCE 200809
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char *message = "CTRL-C pressed\n";

//handler - runs when SIGINT occurs
void handle_sigint(int signum) {
  write(STDOUT_FILENO, message, strlen(message));
  // dont use printf (not secure)
  // - if you dont pass \n it doesnt print right away, so its stored in buffer, and then returns it
  // and how much space the buffer is using, might receive signal while its doing this, result in
  // conflict . printf gets called in printf
}

int main(){
  struct sigaction sa;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0; // default
  sa.sa_handler = handle_sigint; //function pointer

  // which signal, (act) what to do when get signal, oldact to store prev behaviour (optional)
  // for signal that corresponds to (ctrl c), do this behaviour 
  if(sigaction(SIGINT, &sa, NULL)){
    perror("sigaction");
    return 1;
  }

  sleep(10);

  // sigaction tells kernel what function to execute LATER, when a specific signal is delivered
}
