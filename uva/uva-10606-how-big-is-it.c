#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int n, m, i;
    double *r, length, temp;

    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        r = (double*) malloc(m * sizeof(double));
        for(i = 0; i < m; i++)
            scanf("%lf", &r[i]);

        length = 0.0;
        for(i = 0; i < m-1; i++){
            temp = pow((r[i] + r[i+1]), 2) - pow((r[i] - r[i+1]), 2);
            // printf("kurang %.3lf\n", temp);
            temp = sqrt(temp);
            // printf("sqrt %.3lf\n", temp);
            length += temp;

            // printf("i=%d, length = %.3lf\n", i, length);
        }

        length += r[0] + r[m-1];
        printf("%0.3lf\n", length);
    }

    return 0;
}