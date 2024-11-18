#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

void print_e(const char *var_name) {
	char *value = getenv(var_name);
	if(value)
		printf("%s = %s\n", var_name, value);
}

void print_e_all() {
	extern char **environ;
	char **ptr;

	for(ptr = environ; *ptr != NULL; ptr++) {
		printf("%s\n", *ptr);
	}
}

void print_e_name() {
	print_e("HOME");
	print_e("SHELL");
	print_e("PATH");
}

void print_u() {
	printf("My Realistic User ID : %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
	printf("My Valid  User ID : %d(%s) \n", getuid(), getpwuid(geteuid())->pw_name);
}

void print_g() {
	 printf("My Realistic Group ID : %d(%s) \n", getgid(), getgrgid(getgid())->gr_name);
     printf("My Valid Group ID : %d(%s) \n", getgid(), getgrgid(getegid())->gr_name);

}

void print_i() {
	printf("My Process ID : [%d]\n", getpid());
}

void print_p() {
	printf("My Perent Process ID : [%d]\n", getppid());
}

int main(int argc, char *argv[]) {
	int env = 0, s_user = 0, s_group = 0, s_pid = 0, s_ppid = 0;
	char *env_var = NULL;

	for(int i = 1; i < argc; i++) {
		if(strcmp(argv[i], "-e") == 0) {
			if(i + 1 < argc && (strcmp(argv[i + 1], "HOME") == 0 || strcmp(argv[i + 1], "SHELL") == 0 || strcmp(argv[i + 1], "PATH") == 0)) {
				env_var = argv[++i];
			}
			else env = 1;
		}
		else if(strcmp(argv[i], "-u") == 0) s_user = 1;
		else if(strcmp(argv[i], "-g") == 0) s_group = 1;
		else if(strcmp(argv[i], "-i") == 0) s_pid = 1;
		else if(strcmp(argv[i], "-p") == 0) s_ppid = 1;
	}

	if(env) print_e_all();
	else if(env_var) print_e(env_var);
	
	if(s_user) print_u();
	if(s_group) print_g();
	if(s_pid) print_i();
	if(s_ppid) print_p();
	
	return 0;

}
