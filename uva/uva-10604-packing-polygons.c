// Problem  : UVA 10604 - Packing Polygons
// Author   : timwilliam
// Compiled : 08/03/2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int i, n, **points;
    double R, temp;

    while(1){
        scanf("%d", &n);
        if(n == 0)
            break;

        points = (int**) malloc(n * sizeof(int*));
        for(i = 0; i < n; i++){
            points[i] = malloc(2 * sizeof(int));
            scanf("%d %d", &points[i][0], &points[i][1]);
        }

        scanf("%lf", &R);
        for(i = 0; i < n; i++){
            temp = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            if(temp > R)
                break;
        }

        if(i == n)
            printf("The polygon can be packed in the circle.\n");
        else
            printf("There is no way of packing that polygon.\n");
    }

    return 0;
}