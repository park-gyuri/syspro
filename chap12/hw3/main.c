#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define READ 0  
#define WRITE 1

int main(int argc, char *argv[]) {
    char str[1024];
    char *command1, *command2;
    char *args1[64], *args2[64];
    int fd[2];

    printf("[shell] ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; 

    if (strchr(str, '|') != NULL) {
        command1 = strtok(str, "|");
        command2 = strtok(NULL, "|");
        
        while (*command1 == ' ') command1++;
        while (*command2 == ' ') command2++;

        int i = 0;
        char *token = strtok(command1, " ");
        while (token != NULL) {
            args1[i++] = token;
            token = strtok(NULL, " ");
        }
        args1[i] = NULL; 

        i = 0;
        token = strtok(command2, " ");
        while (token != NULL) {
                        args2[i++] = token;
            token = strtok(NULL, " ");
        }
        args2[i] = NULL; 
    } else {
        fprintf(stderr, "Error: No pipe '|' found in command\n");
        exit(1);
    }

    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    if (fork() == 0) { 
        close(fd[READ]);          
        dup2(fd[WRITE], STDOUT_FILENO); 
        close(fd[WRITE]);         

        execvp(args1[0], args1);  
        perror("execvp failed");
        exit(1);
    }

    if (fork() == 0) {
        close(fd[WRITE]);        
        dup2(fd[READ], STDIN_FILENO);  
        close(fd[READ]);          

        execvp(args2[0], args2);  
        perror("execvp failed");
        exit(1);
    }

    close(fd[READ]);
    close(fd[WRITE]);
    wait(NULL);
    wait(NULL);

    return 0;
}
