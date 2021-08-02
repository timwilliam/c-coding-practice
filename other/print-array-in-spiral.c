// Problem  : Print a 2D-Array in a Spiral Order
// Author   : timwilliam
// Compiled : 08/02/2021

#include <stdio.h>
#include <stdlib.h>

void fill_array(int **A, int m, int n){
    int i, j, counter = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            A[i][j] = ++counter;
        }
    }
    
    return;
}

void print_array(int **A, int m, int n){
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%3d%c", A[i][j], (j+1) % n ? ' ' : '\n');
        }
    }

    return;
}

void print_in_spiral(int **A, int m, int n){
    int i, T, B, L, R, dir;

    // initial coordinates
    // 0,0   ---->   0,n-1
    //  |               |
    //  |               |
    // m-1,0 ---->   m-1,n-1

    T = 0; B = m - 1; // Top, Bottom
    L = 0; R = n - 1; // Left, Right

    // can move in 4 possible directions
    // dir 0, 1, 2, 3 <==> right, down, left, up
    dir = 0;
    while(T <= B && L <= R){
        // proceed with printing and peeling inward        
        if(dir == 0){
            for(i = L; i <= R; i ++)
                printf("%d ", A[T][i]);
            
            T++;
        }
        else if(dir == 1){
            for(i = T; i <= B; i++)
                printf("%d ", A[i][R]);

            R--;
        }
        else if(dir == 2){
            for(i = R; i >= L; i--)
                printf("%d ", A[B][i]);

            B--;
        }
        else if(dir == 3){
            for(i = B; i >= T; i--)
                printf("%d ", A[i][L]);

            L++;
        }

        dir = (dir + 1) % 4;
    }

    printf("\n");
    return;
}

int main(void){
    int i, m, n, **A;

    // size of array m x n
    m = n = 4;
    A = (int**) malloc(m * sizeof(int*));
    for(i = 0; i < n; i++)
        A[i] = (int*) malloc(n * sizeof(int));

    fill_array(A, m, n);
    print_array(A, m, n);

    printf("\n");
    print_in_spiral(A, m, n);

    return 0;
}