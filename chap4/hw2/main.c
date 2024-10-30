#include <stdio.h>

int main (int argc, char *argv[]) {
	
	FILE *fp;
	int c;

	if(argc < 2){
		fp = stdin;
		while((c = getc(fp)) != EOF)
			putc(c, stdout);
	}
	else {
		for(int i = 1; i < argc; i++) {
			fp = fopen(argv[i], "r");
			if(fp == NULL) {
				fprintf(stderr, "File %s Open Error\n", argv[i]);
				continue;
			}

			while (( c = getc(fp)) != EOF)
				putc(c, stdout);

			fclose(fp);
		}
	}
	return 0;
}
