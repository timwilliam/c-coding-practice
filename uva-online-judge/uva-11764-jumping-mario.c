// Problem  : UVA 11764 - Jumping Mario
// Author   : timwilliam
// Compiled : 06/26/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int T, N, prev, current, H, L, *walls;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        H = L = 0;
        
        scanf("%d", &N);
        walls = malloc(N * sizeof(int));

        for(int i = 0; i < N; i++)
            scanf("%d", &walls[i]);

        for(int i = 0; i < N; i++){
            if(i == 0){
                prev = walls[i];
                continue;
            }

            current = walls[i];
            if(prev < current)
                H++;
            else if(prev > current)
                L++;

            prev = current;
        }

        printf("Case %d: %d %d\n", i, H, L);   
        free(walls);
    }
}
