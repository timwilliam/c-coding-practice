// Problem  : Big Integer Arithmetic
// Author   : timwilliam
// Compiled : 07/26/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BASE = 10;
int N_DIGIT = 5;

void reset(int C[]){
    int i;
    for(i = 0; i < N_DIGIT; i++)
        C[i] = 0;

    return;
}

void print(int big_int[]){
    int i;
    for(i = N_DIGIT - 1; i >= 0; i--)
        printf("%d%c", big_int[i], i == 0 ? '\n' : ' ');

    return;
}

void make_big_int(int n, int big_int[]){
    int i = 0;

    while(n){
        big_int[i++] = n % BASE;
        n = n / BASE;
    }

    while(i < N_DIGIT)
        big_int[i++] = 0;

    return;
}

void shift(int big_int[], int pos){
    int i;

    // start from the back, then update big_int[i] w/ big_int[i-pos]
    for(i = N_DIGIT-1; i >= 0; i--){
        if(i >= pos)
            big_int[i] = big_int[i-pos];
        else
            big_int[i] = 0;
    }

    return;
}

void add(int A[], int B[], int C[]){
    int i, carry = 0;

    for(i = 0; i < N_DIGIT; i++){
        C[i] = A[i] + B[i] + carry;

        if(C[i] >= BASE){
            C[i] = C[i] - BASE;
            carry = 1;
        }
        else
            carry = 0;
    }

    return;
}

// multiplication of a big_int with a single digit
void multiply_one(int A[], int b, int C[]){
    int i;

    for(i = 0; i < N_DIGIT; i++){
        C[i] = A[i] * b + C[i];

        while(C[i] >= BASE){
            C[i] -= BASE;
            C[i+1]++;
        }
    }

    return;
}

void multiply(int A[], int B[], int C[]){
    int i, *temp = malloc(N_DIGIT * sizeof(int));
    
    for(i = 0; i < N_DIGIT; i++){
        reset(temp);

        multiply_one(A, B[i], temp);
        shift(temp, i);

        add(C, temp, C);
    }

    return;
}

int main(void){
    int a = 121, *A = malloc(N_DIGIT * sizeof(int));
    int b = 19, *B = malloc(N_DIGIT * sizeof(int));
    int *C = malloc(N_DIGIT * sizeof(int));

    printf("Input a: %d\n", a);
    printf("Input b: %d\n", b);

    printf("A: ");
    make_big_int(a, A);
    print(A);

    printf("B: ");
    make_big_int(b, B);
    print(B);

    reset(C);
    add(A, B, C);
    printf("A+B = ");
    print(C);

    reset(C);
    multiply(A, B, C);
    printf("A*B = ");
    print(C);

    return 0;
}