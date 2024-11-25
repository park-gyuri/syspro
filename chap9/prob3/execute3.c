#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
   int child, pid, status;
   pid = fork( );
   if (pid == 0) { 
	   execvp(argv[1], &argv[1]);
      fprintf(stderr, "%s:실행 불가\n",argv[1]);
   } else {
	   child = wait(&status);
      printf("[%d] child process %d end \n", getpid(), pid);
      printf("\t end code %d \n", status>>8);
   }
}


