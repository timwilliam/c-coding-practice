#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_index(int *index, int r){
    int i;

    for(i = 0; i < r; i++)
        printf("%d", index[i]);

    printf("\n");

    return;
}

void get_combination(int *index, int n, int r){
    int pos = r -1;

    while(index[0] < n-r+1){
        if(pos >= 0)
    }

    return;
}

int main(void){
    int *index;
    int i, n, r;

    n = 5;
    r = 3;
    
    index = malloc(r * sizeof(int));
    for(i = 0; i < r; i++)
        index[i] = i;

    get_combination(index, n, r);
}