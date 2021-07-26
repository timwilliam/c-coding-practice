// Problem  : GPE Exam 20210714 Problem C - Buying Vaccines
// Author   : timwilliam
// Compiled : 07/26/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct _PRICE{
    int id, qty, qty_price;
    double unit_price;
}PRICE;

void print(PRICE *pricing, int N){
    int i;
    for(i = 0; i < N; i++)
        printf("%2d. %3d %3d %4.2lf\n", pricing[i].id, pricing[i].qty, pricing[i].qty_price, pricing[i].unit_price);

    printf("\n");
    return;
}

int cmpfunc(const void *a, const void *b){
    if(((PRICE*)a)->unit_price == ((PRICE*)b)->unit_price)
        return 0;
    else if(((PRICE*)a)->unit_price > ((PRICE*)b)->unit_price)
        return 1;
    else
        return -1;
}

int main(void){
    int N, A, C, T, P, i, cost, vacc_count, counter;

    scanf("%d", &N);
    PRICE *pricing = malloc(N * sizeof(PRICE));
    for(i = 0; i < N; i++){
        pricing[i].id = i;

        scanf("%d %d", &A, &C);
        pricing[i].qty = A;
        pricing[i].qty_price = C;
        pricing[i].unit_price = (double) C / (double) A;
    }

    // sort pricing of vendor based on unit_price (ascendingly)
    qsort(pricing, N, sizeof(*pricing), cmpfunc);
    
    scanf("%d", &T);
    for(i = 0; i < T; i++){
        scanf("%d", &P);

        vacc_count = cost = counter = 0;
        while(vacc_count < P && counter < N){
            vacc_count += pricing[counter].qty;
            cost += pricing[counter].qty_price;

            counter++;
        }

        if(vacc_count < P) // impossible to get enough doses
            printf("0\n");
        else
            printf("%d\n", cost);
    }

    return 0;
}