// Problem  : UVA 10908 - Largest Square
// Author   : timwilliam
// Compiled : 07/13/2021 (v2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_largest_square(char **char_grid, int *center, int M, int N){
    int i, r, c, size, length;
    char current_char;

    size = length = 1;
    r = center[0];
    c = center[1];
    current_char = char_grid[r][c];

    while(r+size < M && r-size >= 0 && c+size < N && c-size >= 0 && char_grid[r-size][c+size] == current_char && char_grid[r+size][c+size] == current_char && \
        char_grid[r+size][c-size] == current_char && char_grid[r-size][c-size] == current_char){            
            size+=1;
            length+=2;
    }

    return length;
}

int main(void){
    int T, M, N, Q, **center, i;
    char **char_grid, buffer[100];

    scanf("%d", &T);
    getchar();
    while(T--){
        scanf("%d %d %d", &M, &N, &Q);
        getchar();

        char_grid = malloc(M * sizeof(char*));
        for(i = 0; i < M; i++){
            char_grid[i] = malloc(N * sizeof(char));
        
            fgets(buffer, N+2, stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            strcpy(char_grid[i], buffer);
        }

        center = malloc(Q * sizeof(int*));
        for(i = 0; i < Q; i++){
            center[i] = malloc(2 * sizeof(int));
            scanf("%d %d", &center[i][0], &center[i][1]);
            getchar();

            printf("%d\n", get_largest_square(char_grid, center[i], M, N));
        }

        memset(buffer, 0, sizeof(buffer));
        
        for(i = 0; i < M; i++)
            free(char_grid[i]);
        free(char_grid);
       
        for(i = 0; i < Q; i++)
            free(center[i]);
        free(center);
    }

    return 0;
}