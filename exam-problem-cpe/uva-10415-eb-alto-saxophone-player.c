// Problem  : UVA 10415 - Eb Alto Saxophone Player
// Author   : timwilliam
// Compiled : 07/09/2021 (v2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char note_list[14] = "cdefgabCDEFGAB";

                    //   1  2  3  4  5  6  7  8  9  10
int finger[14][10] = {  {0, 1, 1, 1, 0, 0, 1, 1, 1, 1}, // c
                        {0, 1, 1, 1, 0, 0, 1, 1, 1, 0}, // d
                        {0, 1, 1, 1, 0, 0, 1, 1, 0, 0}, // e
                        {0, 1, 1, 1, 0, 0, 1, 0, 0, 0}, // f
                        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // g
                        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // a
                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // b
                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // C
                        {1, 1, 1, 1, 0, 0, 1, 1, 1, 0}, // D    
                        {1, 1, 1, 1, 0, 0, 1, 1, 0, 0}, // E
                        {1, 1, 1, 1, 0, 0, 1, 0, 0, 0}, // F
                        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // G
                        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // A
                        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}};// B

int get_finger(char note){
    char *pch;
    pch = strchr(note_list, note);
    return pch - note_list;
}

int main(void){
    int i, j, k, t, notes_len, press_count[10], prev_note[10];
    char notes[202];

    scanf("%d", &t);
    getchar();

    while(t--){
        memset(notes, 0, sizeof(notes));
        memset(press_count, 0, sizeof(press_count));
        memset(prev_note, 0, sizeof(prev_note));
    
        fgets(notes, 202, stdin);
        notes[strcspn(notes, "\n")] = 0;
        notes_len = strlen(notes);

        // go through each note
        for(i = 0; i < notes_len; i++){
            // go through each finger
            for(j = 0; j < 10; j++){
                if(finger[get_finger(notes[i])][j] > prev_note[j])
                    press_count[j]++;
            }

            // save current note as previous note and continue
            for(k = 0; k < 10; k++)
                prev_note[k] = finger[get_finger(notes[i])][k];
        }

        for(k = 0; k < 9; k++)
            printf("%d ", press_count[k]);
        printf("%d\n", press_count[9]);
    }

    return 0;
}