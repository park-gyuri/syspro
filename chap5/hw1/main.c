#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char savedText[10][100];
    char buf;
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0) return 1;
    else printf("File read success\n");

    int line = 0, col = 0;
    while (read(fd, &buf, 1) > 0 && line < 10) {
        if (buf == '\n') {
            savedText[line][col] = '\0';
            line++;
            col = 0;
        } else {
            savedText[line][col++] = buf;
        }
    }
    close(fd);

    printf("Total line : %d\n", line);
    printf("You can choose line %d ~ %d\n", 1, line);
    printf("Please enter the line to select: ");

    char input[10];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 

    if (strcmp(input, "*") == 0) {
        for (int i = 0; i < line; i++) {
            printf("%s\n", savedText[i]);
        }
    }
    else if (strchr(input, '-') != NULL) {
        int start, end;
        sscanf(input, "%d-%d", &start, &end);

        if (start >= 1 && end <= line && start <= end) {
            for (int i = start - 1; i < end; i++) {
                printf("%s\n", savedText[i]);
            }
        }
    }
    else {
        char *token = strtok(input, ",");
        while (token != NULL) {
            int lineNum = atoi(token);
            if (lineNum >= 1 && lineNum <= line) {
                printf("%s\n", savedText[lineNum - 1]);
            }
            token = strtok(NULL, ",");
        }
    }

    return 0;
}
