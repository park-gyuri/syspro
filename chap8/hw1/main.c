#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
	

	for(int i = 1; i < argc; i++) {
		if(strcmp(argv[i], "-e") == 0) {
		}
	// -e
	char **ptr;
	extern char **environ;

	for(ptr = environ; *ptr != 0; ptr++)
		printf("%s \n", *ptr);

	exit(0);

	char *ptr;

	//-e HOME
	ptr = getenv("HOME");
	printf("HOME = %s \n", ptr);
	//-e SHELL
	ptr = getenv("SHELL");
	printf("SHELL = %s \n", ptr);
	// -e PATH
	ptr = getenv("PATH");
	printf("PATH = %s \n", ptr);


	// -u
	printf("My Realistic User ID : %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
	printf("My Valid  User ID : %d(%s) \n", getuid(), getpwuid(geteuid())->pw_name);

	// -g
	printf("My Realistic Group ID : %d(%s) \n", getgid(), getgrgid(getgid())->gr_name);
	printf("My Valid Group ID : %d(%s) \n", getgid(), getgrgid(getegid())->gr_name);

	// -i
	printf("My process number : [%d] \n", getpid());
	
	// -p
	printf("My parent process number : [%d] \n", getppid());

}
