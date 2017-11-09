#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

static void sighandler(int signo){
  // check if SIGINT
  if(signo == SIGINT){
    int fd = open("error", O_CREAT|O_WRONLY, 0644);
    char x[] = "SIGINT\n";
    write(fd, x, sizeof(x));
    // exit
    printf("\nExiting due to SIGINT.\n");
    exit(0);
  }

  // check if SIGUSR1
  if(signo == SIGUSR1){}
    printf("Parent: %d\n", getppid());
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  // constant loop
  while(1){
    // prints pid and sleeps for 1
    printf("PID: %d\n", getpid());
    sleep(1);
  }

  return 0;
}
