// Problem  : Linked list with insert at tail
// Author   : timwilliam
// Compiled : 07/23/2021

#include<stdio.h>
#include<stdlib.h>

typedef struct _GRADING{
    int grade;
    struct _GRADING *next;
}GRADING;

GRADING *head = NULL;
GRADING *tail = NULL;

void print(){
    if(head == NULL) // don't print anything if list is empty
        return;

    GRADING *temp = head;
    while(temp != NULL){
        printf("%d ", temp->grade);
        temp = temp->next;
    }
    
    printf("\n");

    return;
}

void insert(int input_grade){
    GRADING *temp = (GRADING*) malloc(sizeof(GRADING));
    temp->grade = input_grade;
    
    if(head == NULL){
        temp->next = NULL;
        head = tail = temp;
    }
    else{
        tail->next = temp;
        temp->next = NULL;
        tail = temp;
    }

    return;
}

int main(void){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print();

    return 0;
}