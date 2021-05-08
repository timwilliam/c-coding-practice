#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int x[1000000], n, i, j, A_min, n_A, n_possible_A, sum, min_sum, A;

    while(scanf("%d", &n) != EOF){
        memset(x, 0, sizeof(x));

        for(i = 0; i < n; i++){
            scanf("%d", &x[i]);
        }

        // minimum possible value for A
        //min_sum = 65536;
        A_min = 0;
        for(i = 0; i < n; i++){
            sum = 0;
            for(j = 0; j < n; j++){
                sum += abs(x[j] - x[i]);
            }

            //printf("    %d Current Sum %d, min_sum=%d\n", i, sum, min_sum);
            if(sum <= min_sum || i == 0){
                if(sum == min_sum)
                    continue;            
    
                min_sum = sum;
                A_min = x[i];
                //printf("    UPDATE: min_sum=%d, A_min=%d\n", min_sum, A_min);
            }
        }
  
        //printf("min_sum=%d, A_min=%d\n", min_sum, A_min); 
        // how many input satisfy property of A
        n_A = 0;
        for(i = 0; i < n; i++){
            if(abs(x[i] - A_min) == 0){
                n_A++;
            }
        }

        // how many possible values for A
        n_possible_A = 0;
        A = 1;
        while(1){
            sum = 0;
            for(i = 0; i < n; i++){
                sum += abs(x[i] - A);
            }

            if(sum <= min_sum){
                n_possible_A++;
            }
            
            A++;
            if(A == 65536){
                break;
            }
        }
    
        // Print the result
        printf("%d %d %d\n", A_min, n_A, n_possible_A);
    }
}
