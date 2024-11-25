#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **top, int data){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
}

int pop(struct node **top){
	if(*top == NULL) {
		printf("Stack is empty.\n");
		return -1;
	}
	struct node *temp = *top;
	int popValue = temp->data;
	*top = temp->next;
	free(temp);
	return popValue;
}

int main() {
	struct node *stack = NULL;
		int value;

	while(1) {
		if(scanf("%d", &value) == 1){
			push(&stack, value);
		}
		else {
			printf("Print stack\n");

			while(stack != NULL) {
				printf("%d\n", pop(&stack));
			}
			break;
		}
	}
	return 0;
}
