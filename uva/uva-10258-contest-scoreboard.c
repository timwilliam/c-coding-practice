// Problem  : UVA 10258 - Contest Scoreboard
// Author   : timwilliam
// Compiled : 08/09/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N_CONTESTANTS 100
#define N_QUESTIONS 10

typedef struct _INPUT{
    int correct_time, n_incorrect, n_other, is_input, is_correct;
}INPUT;

typedef struct _SCOREBOARD{
    int id, q_answered, total_time, is_participating;
}SCOREBOARD;

INPUT individual_score[N_CONTESTANTS][N_QUESTIONS];
SCOREBOARD final_score[N_CONTESTANTS];

int is_empty(const char *buffer){
    while(*buffer != '\0'){
        if(isspace(*buffer) == 0)
            return 0;
        
        buffer++;
    }

    return 1;
}

int cmpfunc(const void *a, const void*b){
    // sort by q_answered (descending)
    if(((SCOREBOARD*)a)->q_answered > ((SCOREBOARD*)b)->q_answered)
        return -1;
    else if(((SCOREBOARD*)a)->q_answered < ((SCOREBOARD*)b)->q_answered)
        return 1;

    // then by penalty (increasing)
    if(((SCOREBOARD*)a)->total_time > ((SCOREBOARD*)b)->total_time)
        return 1;
    else if(((SCOREBOARD*)a)->total_time < ((SCOREBOARD*)b)->total_time)
        return -1;

    // then by id (increasing)
    if(((SCOREBOARD*)a)->id > ((SCOREBOARD*)b)->id)
        return 1;
    else if(((SCOREBOARD*)a)->id < ((SCOREBOARD*)b)->id)
        return -1;
    else
        return 0;
}

void print_scoreboard(){
    int i;

    // only prints the score for the contestant who participates in the test
    for(i = 0; i < N_CONTESTANTS; i++){
        if(final_score[i].q_answered > 0 || final_score[i].is_participating == 1)
            printf("%d %d %d\n", final_score[i].id, final_score[i].q_answered, final_score[i].total_time);
    }

    printf("\n");
    return;
}

void process_scoreboard(){
    int i, j;

    for(i = 0; i < N_CONTESTANTS; i++){
        for(j = 0; j < N_QUESTIONS; j++){
            if(individual_score[i][j].is_correct || individual_score[i][j].n_other > 0){
                final_score[i].id = i + 1;
                final_score[i].is_participating = 1;

                // for question that is answered correctly
                if(individual_score[i][j].correct_time > 0){
                    final_score[i].q_answered += 1;
                    
                    if(individual_score[i][j].n_incorrect > 0)
                        final_score[i].total_time += individual_score[i][j].correct_time + individual_score[i][j].n_incorrect * 20;
                    else
                        final_score[i].total_time += individual_score[i][j].correct_time;
                }
            }
        }
    }

    return;
}

void insert_input(int id, int q_number, int time, char status){
    if(status == 'C'){
        individual_score[id-1][q_number].is_correct = 1;

        // first correct answer
        if(individual_score[id-1][q_number].is_input == 0){
            individual_score[id-1][q_number].correct_time = time;
            individual_score[id-1][q_number].is_input = 1;
        }
        // update only if the new time is lower than previous time
        else if(time < individual_score[id-1][q_number].correct_time)
            individual_score[id-1][q_number].correct_time = time;
    }
    else{
        if(status == 'I')
            // don't mind it if there is a previously correct answer already present
            if(individual_score[id-1][q_number].is_correct == 0)
                individual_score[id-1][q_number].n_incorrect += 1;

        // note that other status is counted together with the 'I' status
        individual_score[id-1][q_number].n_other += 1;
    }
    
    return;
}

void reset(){
    int i, j;
    for(i = 0; i < N_CONTESTANTS; i++){
        for(j = 0; j < N_QUESTIONS; j++){
            individual_score[i][j].correct_time = 0;
            individual_score[i][j].n_incorrect = 0;
            individual_score[i][j].n_other = 0;
            individual_score[i][j].is_input = 0;
            individual_score[i][j].is_correct = 0;
        }
    }

    return;
}

int main(void){
    int i, T, id, q_number, time;
    char status, buffer[100];

    reset();

    scanf("%d", &T);
    getchar();
    getchar();
    while(T--){
        while((fgets(buffer, sizeof(buffer), stdin) != NULL) && (is_empty(buffer) == 0)){
            sscanf(buffer, "%d %d %d %c", &id, &q_number, &time, &status);
            insert_input(id, q_number, time, status);
        }
       
        process_scoreboard();
        qsort(final_score, N_CONTESTANTS, sizeof(*final_score), cmpfunc);
        print_scoreboard();
    }

    return 0;
}