#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

int main() {
    int fd;
    char *lines[MAX_LINES];
    int count = 0;

    fd = open("test.txt", O_RDONLY);

    char buffer[MAX_LENGTH];
    ssize_t bytesRead;
    while (count < MAX_LINES && (bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0'; 

        char *line = strtok(buffer, "\n"); 
        while (line != NULL && count < MAX_LINES) {
            lines[count++] = strdup(line); 
            line = strtok(NULL, "\n"); 
        }
    }
    close(fd);

    for (int i = count - 1; i >= 0; i--) {
        printf("%s\n", lines[i]);
        free(lines[i]);
    }

    return 0; 
}

