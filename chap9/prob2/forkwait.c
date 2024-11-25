#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() 
{
   int pid, child, status;
   printf("[%d] Parental process start \n", getpid( ));
   pid = fork();
   if (pid == 0) {
      printf("[%d] Child process start \n", getpid( ));
      exit(1);
   }
   child = wait(&status);
   printf("[%d] Child process %d end \n", getpid(), child);
   printf("\t End Code %d\n", status>>8);
}


