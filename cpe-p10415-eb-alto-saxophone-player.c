// Program	: CPE - p10415 EB Alto Saxophone Player
// Author	: Timothy William
// Compiled	: 02/23/2021

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// Dictionary for mapping note to finger position
// 	- Note c - b is on index 0 -  6
// 	- Note C - B is on index 7 - 13
int dict_finger[14][10] = {
   //1  2  3  4  5  6  7  8  9 10
	{0, 1, 1, 1, 0, 0, 1, 1, 1, 1}, // c
	{0, 1, 1, 1, 0, 0, 1, 1, 1, 0},	// d	
	{0, 1, 1, 1, 0, 0, 1, 1, 0, 0},	// e		
	{0, 1, 1, 1, 0, 0, 1, 0, 0, 0},	// f		
	{0, 1, 1, 1, 0, 0, 0, 0, 0, 0},	// g		
	{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},	// a		
	{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},	// b		
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},	// C	
	{1, 1, 1, 1, 0, 0, 1, 1, 1, 0},	// D		
	{1, 1, 1, 1, 0, 0, 1, 1, 0, 0},	// E		
	{1, 1, 1, 1, 0, 0, 1, 0, 0, 0},	// F
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0},	// G		
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 0},	// A		
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 0},	// B	
};

char dict_note[14] = "cdefgabCDEFGAB";

int main(void){
	int t, in_len, i, j, press_count[10], previous_finger[10], loc_int;
	char buffer[201], *loc;

	fgets(buffer, 200, stdin);
	t = atoi(buffer);

	while(t > 0){
		// Reset press_count
		memset(press_count, 0, sizeof(press_count));
		// Reset previous finger press memory
		memset(previous_finger, 0, sizeof(previous_finger));

		// Remove newline character
		if(fgets(buffer, 200, stdin) != NULL){
			buffer[strcspn(buffer, "\n")] = 0;
		}
	
		// Process the finger press one-by-one
		in_len = strlen(buffer);
		for(i = 0; i < in_len; i++){
			// Get the index of the dict_finger based on the input
			loc = strchr(dict_note, buffer[i]);
			loc_int = (int) (loc - dict_note);
			// Compare and check if there is new finger press
			for(j = 0; j < 10; j++){
				// New finger press
				if(dict_finger[loc_int][j] > previous_finger[j]){
					press_count[j] += 1;
				}

				// Update previous finger press memory
				previous_finger[j] = dict_finger[loc_int][j]; 
			}
		}
		
		// Print the result
		for(i = 0; i < 10; i++){
			printf("%d ", press_count[i]);
		}
		printf("\n");

		t--;
	}
}
