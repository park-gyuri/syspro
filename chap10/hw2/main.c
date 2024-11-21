#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};
void addq(struct node *head, struct node *tail, int data);
int delete(struct node *head, struct node *tail);

int main () {
	int num[200];
	struct node *next, *head, *tail = NULL;

	scanf("%d ");

	printf("Print queue\n");
	
	printf("%d\n");

}
