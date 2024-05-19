#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

void print(struct ListNode *head){
    struct ListNode *temp = head;

    while(temp != NULL){
        printf("%d, ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// use recursion to reverse the order of the list
struct ListNode *reverse(struct ListNode *head, struct ListNode **newHead){
    if(head->next == NULL){
        *newHead = head;
        return head;
    }

    // when at the end of list, reverse() returns the tail of the list
    // i.e.: [2] -> [3] returns [3]
    struct ListNode *temp = reverse(head->next, &(*newHead));

    // make tail to points at the previous node in the list
    // i.e.: [2] <- [3]
    temp->next = head;

    // fix the previous node in the list to not point back to the tail and creating a loop
    head->next = NULL;

    return head;
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *sumHead = NULL;
    struct ListNode *l1h = l1;
    struct ListNode *l2h = l2;
    int sumTemp = 0;
    int carry = 0;

    // reverse the list to calculate the sum
    reverse(l1h, &l1h);
    reverse(l2h, &l2h);

    while(l1h != NULL || l2h != NULL){
        if(l2h == NULL){
            sumTemp = l1h->val + carry;
        }
        else if(l1h == NULL){
            sumTemp = l2h->val + carry;
        }
        else{
            sumTemp = l1h->val + l2h->val + carry;
        }

        carry = 0;
        if(sumTemp > 9){
            sumTemp -= 10;
            carry = 1;
        }

        // insert sum result to a new list
        insert(&sumHead, sumTemp);

        if(l1h != NULL){
            l1h = l1h->next;
        }
        if(l2h != NULL){
            l2h = l2h->next;
        }
    }

    if(carry == 1){
        insert(&sumHead, 1);
    }

    reverse(sumHead, &sumHead);
    return sumHead;
}

int main(){
    struct ListNode *l1h = NULL;
    struct ListNode *l2h = NULL;

    insert(&l1h, 7);
    insert(&l1h, 2);
    insert(&l1h, 4);
    insert(&l1h, 3);
    // print(l1h);

    insert(&l2h, 5);
    insert(&l2h, 6);
    insert(&l2h, 4);
    // print(l2h);

    struct ListNode *sum = addTwoNumbers(l1h, l2h);
    print(sum);

    return 0;
}
