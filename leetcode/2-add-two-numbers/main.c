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

// insert new element at tail of list
void insert(struct ListNode **head, struct ListNode **tail, int val){
    struct ListNode *temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    temp->val = val;

    if(*head == NULL){
        *head = temp;
        *tail = temp;
    }
    else{
        (*tail)->next = temp; 
        *tail = temp;
    }

    // set tail to always point to NULL
    temp->next = NULL;
}

struct ListNode *addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *sumHead = NULL;
    struct ListNode *sumTail = NULL;

    struct ListNode *l1Head = l1;
    struct ListNode *l2Head = l2;

    int carry = 0;
    int sumTemp = 0;

    while(l1Head != NULL || l2Head != NULL){
        if(l1Head == NULL){
            sumTemp = l2Head->val + carry;
        }
        else if(l2Head == NULL){
            sumTemp = l1Head->val + carry;
        }
        else{
            sumTemp = l1Head->val + l2Head->val + carry;
        }

        carry = 0;

        if(sumTemp >= 10){
            sumTemp -= 10;
            carry = 1;
        }

        // carry operation to be carried out in the next element summation
        insert(&sumHead, &sumTail, sumTemp);

        // traverse the list l1 and the list l2
        if(l1Head != NULL){
            l1Head = l1Head->next;
        }
        if(l2Head != NULL){
            l2Head = l2Head->next;
        }
    }

    // add new carry element to the list
    if(carry == 1){
        insert(&sumHead, &sumTail, carry);
    }

    return sumHead;
}

int main(){
    struct ListNode *l1Head = NULL;
    struct ListNode *l1Tail = NULL;
    struct ListNode *l2Head = NULL;
    struct ListNode *l2Tail = NULL;
    struct ListNode *sum = NULL;

    // insert(&l1Head, &l1Tail, 2);
    // insert(&l1Head, &l1Tail, 4);
    // insert(&l1Head, &l1Tail, 3);
    // print(l1Head);
    // insert(&l2Head, &l2Tail, 5);
    // insert(&l2Head, &l2Tail, 6);
    // insert(&l2Head, &l2Tail, 4);
    // print(l2Head);

    // insert(&l1Head, &l1Tail, 2);
    // insert(&l1Head, &l1Tail, 4);
    // print(l1Head);
    // insert(&l2Head, &l2Tail, 5);
    // insert(&l2Head, &l2Tail, 6);
    // insert(&l2Head, &l2Tail, 4);
    // print(l2Head);

    insert(&l1Head, &l1Tail, 9);
    insert(&l1Head, &l1Tail, 9);
    insert(&l1Head, &l1Tail, 9);
    insert(&l1Head, &l1Tail, 9);
    insert(&l1Head, &l1Tail, 9);
    insert(&l1Head, &l1Tail, 9);
    insert(&l1Head, &l1Tail, 9);
    print(l1Head);
    insert(&l2Head, &l2Tail, 9);
    insert(&l2Head, &l2Tail, 9);
    insert(&l2Head, &l2Tail, 9);
    insert(&l2Head, &l2Tail, 9);
    print(l2Head);

    sum = addTwoNumbers(l1Head, l2Head);
    print(sum);

    return 0;
}
