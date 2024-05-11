#include <stdio.h>
#include <stdlib.h>

typedef struct grading_t{
	int grade;
	struct grading_t *next;
}Grading;

Grading *head;
int gradeCount;

void print(){
	Grading *temp = head;

	while(temp != NULL){
		printf("%3d ", (*temp).grade);
		temp = temp->next;
	}

	printf("\n");
}

void insert(int grade, int pos){
	if(pos > gradeCount + 1){
		printf("Invalid position! (gradeCount=%2d)\n", gradeCount);
		return;
	}

	Grading *temp = (Grading*) malloc(sizeof(Grading));
	temp->grade = grade;

	if(head == NULL){
		temp->next = NULL;
		head = temp;
	}
	else{
		int currentPos = 1;
		Grading *insertTail = head;

		while(currentPos < gradeCount - 1){
			insertTail = insertTail->next;
			currentPos++;
		}

		// when inserting at head, just need to link temp to head, and then update head as temp
		if(pos == 1){
			temp->next = head;
			head = temp;
		}
		// otherwise, link temp to pos + 1, and then update pos - 1 to link to temp
		else{
			temp->next = insertTail->next;
			insertTail->next = temp;
		}

		gradeCount++;
	}

	return;
}

int main(void){
	head = NULL;
	gradeCount = 0;

	insert(90, 1);
	print();
	insert(70, 1);
	print();
	insert(85, 3);
	print();
	insert(85, 2);
	print();
	insert(100, 1);
	print();

	return 0;
}
