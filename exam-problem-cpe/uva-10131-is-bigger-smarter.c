// Problem  : UVA 10131 - Is Bigger Smarter
// Author   : timwilliam
// Compiled : 07/30/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct _list{
    int w, iq, id;
}LIST;

int cmpfunc(const void *a, const void *b){
    if (((LIST*)a)->w > ((LIST*)b)->w)
        return 1;
    else
        return -1;

    if(((LIST*)a)->iq < ((LIST*)b)->iq)
        return 1;
    else if(((LIST*)a)->iq == ((LIST*)b)->iq)
        return 0;
    else
        return -1;
}

int main(void){
    int n_elephant, i, highest_iq_index, temp, *subset_of_elephant, subset_count;

    LIST *list_of_elephants = (LIST*) malloc(1000 * sizeof(LIST));

    n_elephant = 0;
    while(scanf("%d %d", &list_of_elephants[n_elephant].w, &list_of_elephants[n_elephant].iq) != EOF){
        list_of_elephants[n_elephant].id = n_elephant + 1,
        n_elephant++;
    }

    // list are sorted by weight (ascending), and then by iq (descending)
    qsort(list_of_elephants, n_elephant, sizeof(*list_of_elephants), cmpfunc);

    // for(i = 0; i < n_elephant; i++){
    //     printf("%d. %4d %4d %2d\n", i+1, list_of_elephants[i].w, list_of_elephants[i].iq, list_of_elephants[i].id);
    // }

    // find the array index of the elephant with the highest iq
    highest_iq_index = 0;
    for(i = 1; i < n_elephant; i++){
        if(list_of_elephants[i].iq >= list_of_elephants[highest_iq_index].iq)
            highest_iq_index = i;
    }

    // then go through the list and store the id of the elephant in an array
    subset_of_elephant = (int*) malloc(n_elephant * sizeof(int));
    subset_count = 0;
    subset_of_elephant[subset_count++] = list_of_elephants[highest_iq_index].id;
    temp = list_of_elephants[highest_iq_index].iq;

    for(i = highest_iq_index+1; i < n_elephant; i++){
        if(temp >= list_of_elephants[i].iq){
            subset_of_elephant[subset_count++] = list_of_elephants[i].id;
            temp = list_of_elephants[i].iq;
        }
    }

    printf("%d\n", subset_count);
    for(i = 0; i < subset_count; i++)
        printf("%d\n", subset_of_elephant[i]);

    return 0;
}