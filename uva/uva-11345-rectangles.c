// Problem  : UVA 11345 - Rectangles
// Author   : timwilliam
// Compiled : 08/13/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct _RECT{
    int x1, y1, x2, y2;
}RECT;

int getMax(int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}

int getMin(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

int main(void){
    int N, M, case_count, i, A;

    case_count = 1;
    scanf("%d", &N);

    while(N--){
        RECT temp, current;

        // default value
        temp.x1 = -10001;
        temp.y1 = -10001;
        temp.x2 = 10001;
        temp.y2 = 10001;
        A = 0;

        scanf("%d", &M);
        for(i = 0; i < M; i++){
            scanf("%d %d %d %d", &current.x1, &current.y1, &current.x2, &current.y2);
            temp.x1 = getMax(temp.x1, current.x1);
            temp.y1 = getMax(temp.y1, current.y1);
            temp.x2 = getMin(temp.x2, current.x2);
            temp.y2 = getMin(temp.y2, current.y2);
        }

        // the rectangle does not intersect, so A remains 0
        if(temp.x1 < temp.x2 && temp.y1 < temp.y2)
            A = (temp.x2 - temp.x1) * (temp.y2 - temp.y1);

        printf("Case %d: %d\n", case_count, A);
        case_count++;
    }

    return 0;
}