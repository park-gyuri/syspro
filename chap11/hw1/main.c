#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int my_signal(int signo, void (*handler)(int)) {
    struct sigaction act;

    act.sa_handler = handler;    
    sigemptyset(&act.sa_mask);    
    act.sa_flags = 0;              

    if (sigaction(signo, &act, NULL) < 0) {
        perror("sigaction error");
        return -1; 
    }

    return 0;  
}

void alarmHandler(int signo) {
    printf("Wake up!\n");
    exit(0); 
}

int main() {
	if (my_signal(SIGALRM, alarmHandler) < 0) {
        fprintf(stderr, "Failed to set signal handler.\n");
        return 1;
    }

	alarm(5);
	short i = 0;
	while(1) {
		sleep(1);
		i++;
		printf("%d second\n", i);
	}
	printf("end\n");
}
