#include <stdio.h>
#include <stdlib.h>

typedef struct grading_t{
	int grade;
	struct grading_t *next;
}Grading;

Grading *head;

void print(){
	Grading *temp = head;

	while(temp != NULL){
		printf("%d, ", temp->grade);
		temp = temp->next;
	}
	
	printf("\n");
}

void add(int grade){
	Grading *temp = (Grading*) malloc(sizeof(Grading));
	temp->grade = grade;

	if(head == NULL){
		temp->next = NULL;
		head = temp;
	}
	else {
		Grading *current = head;
		
		// insert ascending
		while(current->next != NULL && (current->next)->grade < temp->grade) {
			current = current->next;
		}
		
		temp->next = current->next;
		current->next = temp;
	}
}

int main(){
	head = NULL;

	add(1);
	add(5);
	add(2);
	add(4);
	print();

	return 0;
}
