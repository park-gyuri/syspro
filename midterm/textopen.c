#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

	FILE *fp;
	int c;

	if(argc < 2)
		fp = stdin;
	else fp = fopen(argv[1], "r");

	c = getc(fp);
	while (c != EOF) {
		putc(c, stdout);
		c = getc(fp);
	}

	fclose(fp);
	return 0;
}
