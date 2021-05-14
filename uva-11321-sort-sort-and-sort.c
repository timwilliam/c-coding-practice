// Program	: UVA 11321 - Sort Sort and Sort
// Author	: Timothy William
// Compiled	: 05/12/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc_a(void const *a, void const *b){
    return(*(int*) a - *(int*) b);
}

int cmpfunc_d(void const *a, void const *b){
    return(*(int*) b - *(int*) a);
}

void print(int *array, int start, int end){
    int i;
    for(i = start; i < end; i++){
        printf("%d\n", array[i]);
    }
}

int main(void){
	int N, M, i, j, k, n_rem, n_even, n_odd, odd_cntr, even_cntr;
	int *input, **modulus, *modulus_cntr, *even_bucket, *odd_bucket, temp_odd, temp_even;

	scanf("%d %d", &N, &M);

    // 1. get the input numbers
    n_even = 0;
	input = malloc(N * sizeof(int));
	for(i = 0; i < N; i++){
		scanf("%d", &input[i]);
        if(input[i] % 2 == 0)
            n_even++;
    }

    //printf("[DBG] Input has %d even numbers, %d odd numbers\n", n_even, N - n_even);

    // 2. sort the input ascendingly
    qsort(input, N, sizeof(int), cmpfunc_a);

	// 3. calculate and store the mod results and count
    modulus = malloc(M * sizeof(int*));
    modulus_cntr = malloc(M * sizeof(int));    

    for(i = 0; i < M; i++){
        // calculate the number of input that have remainder i
        //  e.g.: N mod M = i
        n_rem = 0;
        for(j = 0; j < N; j++)
            if(input[j] % M == i)
                n_rem++;

        //printf("[DBG] For modulus=%d, we have %d numbers.\n", i, n_rem);

        // allocate space to store the numbers that have remainder i
        modulus[i] = malloc(n_rem * sizeof(int));
        modulus_cntr[i] = n_rem;

        // store all numbers with remainder 
        //printf("[DBG] They are: ");
        k = 0;
        for(j = 0; j < N; j++){
            if(input[j] % M == i){
                modulus[i][k] = input[j];
                //printf("%d ", modulus[i][k]);
                k++;
            }
        }
        printf("\n");
    }

    // 4. Split the modulus into even and odd bucket
    n_odd = N - n_even;
    even_bucket = malloc(n_even * sizeof(int));
    odd_bucket = malloc(n_odd * sizeof(int));
    odd_cntr = 0;
    even_cntr = 0;
    //printf("[DBG] Storing in buckets:\n");
    for(i = 0; i < M; i++){
        //printf("[DBG] Now at modulus=%d\n", i);
        temp_odd = odd_cntr;
        temp_even = even_cntr;
        for(j = 0; j < modulus_cntr[i]; j++){
            if(modulus[i][j] % 2 == 0){
                even_bucket[even_cntr] = modulus[i][j];
                //printf("    - %d in even bucket\n", even_bucket[even_cntr]);
                even_cntr++;
            }
            else{
                odd_bucket[odd_cntr] = modulus[i][j];
                //printf("    - %d in odd bucket\n", odd_bucket[odd_cntr]);
                odd_cntr++;
            }
        }

        qsort(&odd_bucket[temp_odd], odd_cntr - temp_odd, sizeof(int), cmpfunc_d);

        print(odd_bucket, temp_odd, odd_cntr);
        print(even_bucket, temp_even, even_cntr);
    }

    printf("\n");
}
