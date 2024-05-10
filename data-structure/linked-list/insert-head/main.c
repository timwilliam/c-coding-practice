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
		printf("%3d ", (*temp).grade);
		temp = temp->next;
	}

	printf("\n");
}

void insert(int grade){
	Grading *temp = (Grading*) malloc(sizeof(Grading));
	temp->grade = grade;

	if(head == NULL){
		temp->next = NULL;
	}
	else{
		temp->next = head;
	}

	head = temp;

	return;
}

int main(void){
	head = NULL;

	insert(99);
	insert(70);
	insert(85);
	print();

	return 0;
}
