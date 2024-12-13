#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024

void alphabet(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    int pipe_fd[2]; 
    pid_t pid1, pid2;

    if (pipe(pipe_fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    printf("parent process start\n");

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid1 == 0) {
        close(pipe_fd[0]); 

        char input[BUFFER_SIZE];
        printf("input string: ");
        fgets(input, BUFFER_SIZE, stdin);
        
        input[strcspn(input, "\n")] = '\0';
        
        write(pipe_fd[1], input, strlen(input) + 1);
        close(pipe_fd[1]); 
        exit(0);
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid2 == 0) {
        close(pipe_fd[1]); 
        
        char buffer[BUFFER_SIZE];
        
        read(pipe_fd[0], buffer, BUFFER_SIZE);
        
        alphabet(buffer);
        
        printf("%s\n", buffer);
        close(pipe_fd[0]); 
        exit(0);
    }

    close(pipe_fd[0]);
    close(pipe_fd[1]);
    wait(NULL); 
    wait(NULL); 

    return 0;
}

