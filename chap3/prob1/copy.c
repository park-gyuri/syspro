#include <stdio.h>

void copy(char from[], char too[]) {
	int i;
	i = 0;
	while ((too[i] = from[i]) != '\0'){
		++i;
	}
}
