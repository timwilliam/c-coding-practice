#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N, M, P, i, j, distance, max_distance = 2;
    int **person_loc;

    scanf("%d %d %d", &N, &M, &P);

    person_loc = (int**) malloc(P * sizeof(int*));
    for(i = 0; i < P; i++)
        person_loc[i] = (int*) malloc(2 * sizeof(int));

    for(i = 0; i < P; i++)
        scanf("%d %d", &person_loc[i][0], &person_loc[i][1]);

    for(i = 0; i < P-1; i++){
        distance = abs(person_loc[i][0] - person_loc[i+1][0]) + abs(person_loc[i][1] - person_loc[i+1][1]);

        if(distance > max_distance)
            max_distance = distance;
    }

    // check for the distance from the four courner
    for(i = 0; i < P && P == 1; i++){
        // bottom left corner
        distance = abs(person_loc[i][0] - 0) + abs(person_loc[i][1] - 0);
        max_distance = distance > max_distance ? distance : max_distance;

        // bottom right corner
        distance = abs(person_loc[i][0] - (N-1)) + abs(person_loc[i][1] - 0);
        max_distance = distance > max_distance ? distance : max_distance;

        // top left corner
        distance = abs(person_loc[i][0] - 0) + abs(person_loc[i][1] - (M-1));
        max_distance = distance > max_distance ? distance : max_distance;

        // top right corner
        distance = abs(person_loc[i][0] - (N-1)) + abs(person_loc[i][1] - (M-1));
        max_distance = distance > max_distance ? distance : max_distance;
    }

    printf("%d\n", max_distance);

    return 0;
}