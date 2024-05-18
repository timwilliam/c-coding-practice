#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListPtrOfNode{
    struct ListNode *nodePtr;
    struct ListPtrOfNode *next;
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

// use stack to store the address of each traversed node
void insertStack(struct ListPtrOfNode **stackHead, struct ListNode *nodePtr){
    struct ListPtrOfNode *temp = (struct ListPtrOfNode*) malloc(sizeof(struct ListPtrOfNode));
    temp->nodePtr = nodePtr;

    if(*stackHead == NULL){
        temp->next = NULL;
        *stackHead = temp;
    }
    else{
        temp->next = *stackHead;
        *stackHead = temp;
    }
}

struct ListNode *reverseList(struct ListNode *head){
    if(head == NULL){
        return NULL;
    }

    struct ListNode *temp = head;
    struct ListPtrOfNode *stackHead = NULL;

    // traverse the list, and store each node address in a stack
    while(temp != NULL){
        insertStack(&stackHead, temp);
        temp = temp->next;
    }

    // set top of stack as new head
    struct ListNode *newHead = stackHead->nodePtr;

    // traverse the stack and fix the link
    while(stackHead->next != NULL){
        (stackHead->nodePtr)->next = (stackHead->next)->nodePtr;
        stackHead = stackHead->next;
    }

    (stackHead->nodePtr)->next = NULL;

    return newHead;
}


int main(void){
    struct ListNode *head = NULL;

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
