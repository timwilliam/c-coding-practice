// Program	: UVA - 10642
// Author	: timwilliam
// Compiled	: 05/07/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n, x, y, x_path[1000000], y_path[1000000], i, j, k, n_step, counter, limit, x_des, y_des;

	memset(x_path, 0, sizeof(x_path));
	memset(y_path, 0, sizeof(y_path));

	// generate y_path
	limit = 1;
	counter = limit;
	for(i = 0; i < 1000000; i++){
		if(i == 0){
			y_path[i] = 0;
			continue;
		}

		if(counter >= 0 && counter <= limit){
			y_path[i] = counter;
			counter--;
		}
		else{
			limit++;
			y_path[i] = limit;
			counter = limit - 1;
		}

	}	

	// NOTE: Algorithm works, but might not cover the entire possible input space, need a better way
	//printf("limit %d, counter %d\n", limit, counter);

	// generate x_path
	limit = 1;
	counter = 0;
	for(i = 0; i < 1000000; i++){
		if(i == 0){
			x_path[i] = 0;
			continue;
		}

		if(counter <= limit){
			x_path[i] = counter;
			counter++;
		}
		else{
			limit++;
			x_path[i] = 0;
			counter = 1;
		}

	}	
	
	scanf("%d", &n);
	for(k = 1; k <= n; k++){
		scanf("%d %d %d %d", &x, &y, &x_des, &y_des);
		n_step = 0;

		// get the starting point
		for(i = 0; i < 1000000; i++){
			if(x == x_path[i] && y == y_path[i]){
				n_step = i;
				break;
			}
		}

		// calculate steps taken
		for(i = i; i < 1000000; i++){
			if(x_des == x_path[i] && y_des == y_path[i]){
				n_step = i - n_step;
				break;
			}
		}

		printf("Case %d: %d\n", k, n_step);
	}
}
