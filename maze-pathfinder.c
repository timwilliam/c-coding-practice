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
int X_MAX = 2;
int Y_MAX = 2;

void get_path(int current_pos[], int prev_pos[], int avail_path[]){
	int i, j, k;
	int path_candidate[4][2]; // Up=0, Right=1, Down=2, Left=3
	int valid_path[4] = {0}; // Set to 1 if a direction is valid, else 0

	//TODO Get 4 directions coordinates
	// Up
	path_candidate[0][0] = current_pos[0] - 1;
	path_candidate[0][1] = current_pos[1];
	// Right
	path_candidate[1][0] = current_pos[0];
	path_candidate[1][1] = current_pos[1] + 1;
	// Down
	path_candidate[2][0] = current_pos[0] + 1;
	path_candidate[2][1] = current_pos[1];
	// Left
	path_candidate[3][0] = current_pos[0];
	path_candidate[3][1] = current_pos[1] - 1;

	//printf("Up:%d,%d Down:%d,%d Right:%d,%d Left:%d,%d\n", path_candidate[0][0], path_candidate[0][1], path_candidate[1][0], path_candidate[1][1], path_candidate[2][0], path_candidate[2][1], path_candidate[3][0], path_candidate[3][1]);

	//TODO Check if any of the 4 directions is out of bounds (maze)
	for(i = 0; i < 4; i++){
		if(path_candidate[i][0] >= 0 && path_candidate[i][0] <= X_MAX 
				&& path_candidate[i][1] >= 0 && path_candidate[i][1] <= Y_MAX) valid_path[i] = 1;	
	}

	//TODO Check if any of the 4 directions is going backwards
	for(i = 0; i < 4; i++){
		if(path_candidate[i][0] == prev_pos[0] && path_candidate[i][1] == prev_pos[1]) 
			valid_path[i] = 0;
	}

	//TODO Check if any of the 4 directions is hitting a wall
	for(i = 0; i < 4; i++){
		if(maze[path_candidate[i][0]][path_candidate[i][1]] == 1)
			valid_path[i] = 0;
	}
	
	for(i = 0; i < 4; i++){
		//if(valid_path[i] == 1) printf("Valid %d,%d\n", path_candidate[i][0], path_candidate[i][1]);
		if(valid_path[i] == 1) break;
	}

	//TODO Return the avail_path
	// for now, assume that only 1 available path
	avail_path[0] = path_candidate[i][0];
	avail_path[1] = path_candidate[i][1];
}

void find_path(int current_pos[], int prev_pos[]){
	//TODO Check if end of maze is reached
	if(current_pos[0] == END[0] && current_pos[1] == END[1]){
		printf("Hit end!\n");
		return;
	}

	//TODO Get available path from current_pos
	int avail_path[2];
	
	//TODO Check if there is available path to go
	get_path(current_pos, prev_pos, avail_path);
	
	//TODO Traverse all available path
	printf("From %d,%d. Goint to %d,%d\n", current_pos[0], current_pos[1], avail_path[0], avail_path[1]);
	find_path(avail_path, current_pos);
}

int main(void){
	int current_pos[2] = {2, 0}; // Same as START

	find_path(current_pos, current_pos);
}
