#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void print(struct ListNode *head){
    struct ListNode *temp = head;

    while(temp != NULL){
        printf("%d, ", temp->val);
        temp = temp->next;
    }

    printf("\n");
}

void insert(struct ListNode **head, int val){
    struct ListNode *temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    temp->val = val;

    if(*head == NULL){
        temp->next = NULL;
        *head = temp;
    }
    else{
        struct ListNode *current = *head;

        while(current->next != NULL){
            current = current->next;
        }

        current->next = temp;
        temp->next = NULL;
    }
}

// to store new head of the list
struct ListNode *newHead;

struct ListNode *doReverse(struct ListNode *head){
    if(head->next == NULL){
        newHead = head;
        return head;    
    }

    struct ListNode *temp = doReverse(head->next);

    // reverse the linking direction
    // [2] -> [1] to [1] -> [2]
    temp->next = head;

    // delete the original link
    // [2] -> [1] to [2] -> NULL
    head->next = NULL;

    return head;
}

struct ListNode *reverseList(struct ListNode *head){
    if(head == NULL){
        return NULL;
    }
    else{
        // doReverse will return address of the new tail
        // if original list is [2] -> [1]
        // doReverse will return address of [2]
        doReverse(head);

        // we cannot return head since it stores the address of the new tail, not the address of the new head after traversing the list
        return newHead;
    }
}

int main(void){
    struct ListNode *head = NULL;
    newHead = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    
    print(head);
    head = reverseList(head);
    print(head);

    return 0;
}
