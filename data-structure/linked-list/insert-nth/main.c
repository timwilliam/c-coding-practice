#include <stdio.h>
#include <stdlib.h>

typedef struct grading_t{
	int grade;
	struct grading_t *next;
}Grading;

Grading *head;
Grading *tail;

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

	if(head == NULL){
		head = temp;
		tail = temp;

		tail->grade = grade;
		tail->next = NULL;
	}
	else{
		temp->grade = grade;
		tail->next = temp;
		tail = temp;
	}

	return;
}

int main(void){
	head = NULL;
	tail = NULL;

	insert(99);
	insert(70);
	insert(85);
	print();

	return 0;
}
