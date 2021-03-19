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

struct Path{
	int xy[2];
	struct Path *link;
};

struct Path *path_history = NULL; // To store all of the path taken

void push(int path[], struct Path **stack){
	struct Path *temp = malloc(sizeof(struct Path));

	temp->xy[0] = path[0];
	temp->xy[1] = path[1];

	printf("ptr now %p, temp %p\n", stack, temp);
	temp->link = *stack;
	*stack = temp;

	printf("ptr then %p\n", stack);
}

void pop(struct Path **stack){
	struct Path *temp;
	if(*stack == NULL) return;
	temp = *stack;
	(*stack) = temp->link;
	free(temp);
}

int get_path(int current_pos[], int prev_pos[], struct Path *avail_path){
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
	
	//TODO Store all the avail_path in a stack
	int n_avail_path = 0;
	for(i = 0; i < 4; i++){
		// Create a stack to store the avail_path
		if(valid_path[i] == 1){
			push(path_candidate[i], &avail_path);
			printf("cek %d\n", avail_path->xy[0]);
			n_avail_path++;
		}
	}

	struct Path *tes = avail_path;
	while(tes != NULL){
		printf("xy coor %d,%d\n", tes->xy[0], tes->xy[1]);
		tes = tes->link;
	}

	return n_avail_path;
}

void find_path(int current_pos[], int prev_pos[]){
	//TODO Check if end of maze is reached
	if(current_pos[0] == END[0] && current_pos[1] == END[1]){
		printf("Hit end!\n");
		return;
	}

	//TODO Get available path from current_pos
	
	//TODO Check if there is available path to go
	struct Path *avail_path = NULL; // To store all of the available path
	int n_avail_path;
	n_avail_path = get_path(current_pos, prev_pos, avail_path);
	printf("n %d\n", n_avail_path);

	//TODO Traverse all available path
	while(n_avail_path > 0){
		printf("a %d\n", avail_path->xy[0]);
		printf("* find_path go to %d,%d from %d,%d\n", avail_path->xy[0], avail_path->xy[1], current_pos[0], current_pos[1]);
		find_path(avail_path->xy, current_pos);
		pop(&avail_path);
		n_avail_path--;
	}
}

int main(void){
	int current_pos[2] = {2, 0}; // Same as START

	find_path(current_pos, current_pos);
}
