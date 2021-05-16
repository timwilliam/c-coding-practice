// Problem	: UVA 118 - Mutant Flatworld Explorers
// Author	: timwilliam
// Compiled	: 05/16/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int x_start, y_start, x_end, y_end, x_robot, y_robot, ins_len, x_curr, y_curr, **robot_scent, scent_flag, n_lost, lost_flag, n_scent, i, j;
	char robot_orient, robot_ins[100];

	scanf("%d %d", &x_end, &y_end);

	n_lost = 0;
	n_scent = 2 * (x_end + 1) + 2 * (y_end - 2 + 1);
	robot_scent = malloc(n_scent * sizeof(int*));
	
	for(i = 0; i < n_scent; i++){
		robot_scent[i] = malloc(2 * sizeof(int));
		robot_scent[i][0] = -1;
		robot_scent[i][1] = -1;
	}

	while(scanf("%d %d %c", &x_robot, &y_robot, &robot_orient) != EOF){
		// Orientation: N=1, E=2, S=3, W=4
		if(robot_orient == 'N')
			robot_orient = 1;
		else if(robot_orient == 'E')
			robot_orient = 2;
		else if(robot_orient == 'S')
			robot_orient = 3;
		else if(robot_orient == 'W')
			robot_orient = 4;
	
		memset(robot_ins, 0, sizeof(robot_ins));
		scanf("%s", robot_ins);

		ins_len = strlen(robot_ins);
		lost_flag = 0;
		scent_flag = 0;
		for(i = 0; i < ins_len; i++){
			//printf("[DBG] At ins %d now, instruction is %c\n", i, robot_ins[i]);

			if(lost_flag == 1){
				//printf("[DBG] Robot is LOST after executing previous instruction!\n");
				break;
			}

			if(scent_flag == 1){
				//printf("[DBG] Robot found previous scent, stand its ground at %d,%d!\n", x_robot, y_robot);
				scent_flag = 0;
			}
			
			// moving the robot forward
			if(robot_ins[i] == 'F'){
				x_curr = x_robot;
				y_curr = y_robot;
				
				if(robot_orient == 1)
					y_robot++;
				else if(robot_orient == 2)
					x_robot++;
				else if(robot_orient == 3)
					y_robot--;
				else if(robot_orient == 4)
					x_robot--;

				//printf("[DBG] Robot moving from %d,%d to %d,%d\n", x_curr, y_curr, x_robot, y_robot);

				// robot going of the world
				if(x_robot < 0 || x_robot > x_end || y_robot < 0 || y_robot > y_end){
					// see if there is a scent left before by LOST robot
					for(j = 0; j < n_lost; j++){
						//printf("[DBG] Found scent at current location (%d,%d)\n", robot_scent[j][0], robot_scent[j][1]);
						if(robot_scent[j][0] == x_curr && robot_scent[j][1] == y_curr){
							scent_flag = 1;
							break;		
						}
					}
					
					if(scent_flag != 1){
						//printf("[DBG] No robot scent found, saving current coordinate\n");

						robot_scent[n_lost][0] = x_curr;
						robot_scent[n_lost][1] = y_curr;
						
						lost_flag = 1;
						n_lost++;
					}
					else{
						scent_flag = 1;
					}
				
					x_robot = x_curr;
					y_robot = y_curr;
				}
			}
			// rotating the robot
			else{
				//printf("[DBG] Robot orientation from %d, to", robot_orient);

				if(robot_ins[i] == 'R')
					robot_orient++;
				else if(robot_ins[i] == 'L')
					robot_orient--;

				if(robot_orient > 4)
					robot_orient -= 4;
				else if(robot_orient == 0)
					robot_orient += 4;

				//printf(" %d\n", robot_orient);
			}
		}

		//printf("[DBG] Break at inst %d\n", i);

		if(robot_orient == 1)
			robot_orient = 'N';
		else if(robot_orient == 2)
			robot_orient = 'E';
		else if(robot_orient == 3)
			robot_orient = 'S';
		else if(robot_orient == 4)
			robot_orient = 'W';

		if(lost_flag == 1)
			printf("%d %d %c LOST\n", x_robot, y_robot, robot_orient);
		else
			printf("%d %d %c\n", x_robot, y_robot, robot_orient);
	}
}
