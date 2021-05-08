#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int x[1000000], n, i, j, A, A_min, n_of_A_min, n_of_psbl_A, sum, min_sum;

    while(scanf("%d", &n) != EOF){
        memset(x, 0, sizeof(x));

        for(i = 0; i < n; i++){
            scanf("%d", &x[i]);
        }

        // 1. Get minimum possible value for A
        
        
        // Repeat for all possible value of A derived from x
        for(i = n - 1; i >= 0; i--){
            sum = 0;
            for(j = n - 1; j >= 0; j--){
                // x[j] here is X1, X2, ..., Xn
                // x[i] here is A
                sum += abs(x[j] - x[i]);
            }

            //printf("[DBG] A=%d, sum=%d\n", x[i], sum);

            if(i == n - 1 || sum <= min_sum){
                min_sum = sum;
                A_min = x[i]; 
            }
            
            //printf("[DBG] A_min = %d\n", A_min);
        }

        // how many input satisfy property of A
        n_of_A_min = 0;
        for(i = 0; i < n; i++){
            sum = 0;
            for(j = 0; j < n; j++){
                sum += abs(x[j] - x[i]);
            }

            if(sum == min_sum){
                n_of_A_min++;
            }
        }

        // how many possible values for A
        n_of_psbl_A = 0;    

        // Print the result
        printf("%d %d %d\n", A_min, n_of_A_min, n_of_psbl_A);
    }
}
