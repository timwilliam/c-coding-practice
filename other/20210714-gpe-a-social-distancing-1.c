// Problem  : GPE Exam 20210714 Problem A - Social Distancing 1
// Author   : timwilliam
// Compiled : 08/15/2021

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b){
    return *(int*) a - *(int*) b;
}

int main(void){
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);

    int *person_loc = (int*) malloc(P * sizeof(int));
    int i, j, temp, distance, max_distance = 1;

    for(i = 0; i < P; i++)
        scanf("%d %d", &person_loc[i], &temp);

    qsort(person_loc, P, sizeof(*person_loc), cmpfunc);

    int start, end;
    for(i = 0; i < P - 1; i++){
        start = person_loc[i];
        end = person_loc[i+1];

        distance = (end - start) / 2;

        if(distance > max_distance)
            max_distance = distance;
    }

    printf("max now = %d\n", max_distance);

    // special case check for when no people seats at the very beginning of very end of available seats
    if(person_loc[0] != 0){ // very beginning
        distance = person_loc[0];
        
        if(distance > max_distance)
            max_distance = distance;
    }

    if(person_loc[P-1] != N-1){ // very end
        distance = ((N-1) - person_loc[P-1]);
        
        if(distance > max_distance)
            max_distance = distance;
    }
    
    printf("%d\n", max_distance);

    return 0;
}