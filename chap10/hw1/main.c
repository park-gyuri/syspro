#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node *top, int data);
int pop(struct node *top);

int main() {
	
	scanf("%d"); 

	printf("Print stack\n");
	printf("%d\n");

}
