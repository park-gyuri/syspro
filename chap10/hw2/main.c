#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
	int data;
	struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;

	if(*tail == NULL) *head = *tail = newNode;
	else {
		(*tail)->next = newNode;
		*tail = newNode;
	}
}

int delete(struct node **head, struct node **tail) {
	if(*head == NULL) {
		printf("Queue is Enpty.\n");
		return -1;
	}

	struct node *temp = *head;
	int deleteValue = temp->data;

	*head = (*head)->next;
	if(*head == NULL) *tail = NULL;

	free(temp);
	return deleteValue;
}

int main () {

	struct node *head = NULL;
	struct node *tail = NULL;
	int num[200];
	int count = 0;
	int value;

	while(1) {
		if(scanf("%d", &value) == 1) {
			if(count < 200) {
				num[count++] = value;
				addq(&head, &tail, value);
			}
			else {
				printf("Maximum input reached (200).\n");
				break;
			}
		}
		else {
			printf("Print queue\n");

			while(head != NULL) {
				printf("%d\n", delete(&head, &tail));
			}
			break;
		}
	}
	return 0;
}
