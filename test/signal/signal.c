#include <signal.h>
#include <stdio.h>

void sighandler(int signum) {
  printf("Received signal %u\n", signum);
  exit(0);
}

void main() {
  printf("Installing signal handler\n");
  signal(SIGSEGV, sighandler);

  printf("Dereferencing NULL pointer\n");
  int i = *((int *)NULL);

  printf("Done.\n");
}
