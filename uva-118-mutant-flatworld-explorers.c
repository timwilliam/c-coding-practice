#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int x_start, y_start, x_end, y_end, x_robot, y_robot, i, ins_len;
	char robot_orient, robot_ins[100];

	while(scanf("%d %d", &x_end, &y_end) != EOF){
		scanf("%d %d %c", &x_robot, &y_robot, &robot_orient);
		
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
		for(i = 0; i < ins_len; i++){
			if(robot_ins[i] == 'F'){
				if(robot_orient == 1)
					y_robot++;
				else if(robot_orient == 2)
					y_robot--;
				else if(robot_orient == 3)
					x_robot++;
				else if(robot_orient == 4)
					x_robot--;
			}
			else{
				if(robot_ins[i] == 'R')
					robot_orient++;
				else if(robot_ins[i] == 'L')
					robot_orient--;

				if(robot_orient > 4)
					robot_orient -= 4;
				else if(robot_orient == 0)
					robot_orient += 4;
			}
		}

		if(robot_orient == 1)
			robot_orient = 'N';
		else if(robot_orient == 2)
			robot_orient = 'E';
		else if(robot_orient == 3)
			robot_orient = 'S';
		else if(robot_orient == 4)
			robot_orient = 'W';

		printf("%d %d %c\n", x_robot, y_robot, robot_orient);
	}
}
