// Program  : UVA 10056 - What is the Probability?
// Author   : timwilliam
// Compiled : 04/16/2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int S, N, I, R;
    double p, temp, result, q;

    scanf("%d", &S);

    while(S--){
        scanf("%d %lf %d", &N, &p, &I);
   
        // formula for calculating probability of winning of I
        //      q^(I-1) * p
        // formula for calculating probability of winning of I in R-th round
        //      q^[N(R-1)] * q^(I-1) * p
        // problem is, the number of Round is not specified, need to be generalize 
        //      reference: https://youtu.be/soxR1USFDK0?t=337       
 
        q = 1 - p;
        result = pow(q, I - 1) * p / (1 - pow(q, N));
        
        printf("%.4lf\n", result);
    }
}
