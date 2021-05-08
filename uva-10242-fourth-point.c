// Problem  : UVA 10242 - Fourth Point
// Author   : timwilliam
// Compiled : 05/08/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
    double x1, y1, x2, y2, x3, y3, x4, y4, x_res, y_res;

    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) != EOF){
        // NOTE: This only works assuming if x3, y3 always start from the same position as x2, y2        

        x_res = x3 - x2 + x1;
        y_res = y3 - y2 + y1;

        printf("%.3lf %.3lf\n", x_res, y_res);
    }
}
