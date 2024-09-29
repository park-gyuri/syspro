#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE];
char strings[5][MAXLINE];
int lengths[5];

int main() {
	int count = 0;

	while (count < 5) {
		scanf("%[^\n]", line);
		getchar();
		copy(line, strings[count]);
		lengths[count] = strlen(strings[count]);
		count++;
	}

	for(int i = 0; i < 5 - 1; ++i) {
		for(int j = 0; j < 5 - i - 1; ++j) {
			if(lengths[j] < lengths[j+1]) {
				int temp_len = lengths[j];
				lengths[j] = lengths[j+1];
				lengths[j+1] = temp_len;

				char temp_line[MAXLINE];
				copy(strings[j], temp_line);
				copy(strings[j+1], strings[j]);
				copy(temp_line, strings[j+1]);
			}
		}
	}

	for (int i = 0; i < 5; ++i) {
		printf("%s\n", strings[i]);
	}

	return 0;
}
