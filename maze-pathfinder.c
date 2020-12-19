#include<stdio.h>
#include<stdlib.h>

/*int maze[4][7] = {
	{1, 0, 1, 1, 1, 1, 0},
	{1, 0, 1, 1, 0, 0, 0},
	{1, 0, 0, 0, 0, 1, 1},
	{0, 0, 1, 0, 1, 1, 0}
};*/

int maze[3][3] = {
	{1, 0, 0},
	{1, 0, 1},
	{0, 0, 1}
};

int START[2] = {2, 0}; // Starts at bottom left
int END[2] = {0, 2}; // Ends at top right

void get_path(int current_pos[], int avail_path[]){

	//TODO Get 4 directions coordinates
	//TODO Check if any of the 4 directions is out of bounds (maze)
	//TODO Check if any of the 4 directions is going backwards
	//TODO Return the avail_path
}

void find_path(int current_pos[]){
	//TODO Check if end of maze is reached
	if(current_pos[0] == END[0] && current_pos[1] == END[1])
		return;
	
	//TODO Get available path from current_pos
	int avail_path[2];
	//TODO Check if there is available path to go
	get_path(current_pos, avail_path); 
	//TODO Traverse all available path
	
	//printf("cur %d\n", maze[current_pos[0]][current_pos[1]]);
}

int main(void){
	int current_pos[2] = {2, 0}; // Same as START
	
	find_path(current_pos);
}
