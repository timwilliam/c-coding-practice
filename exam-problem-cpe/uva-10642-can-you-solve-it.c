// Problem	: UVA 10642 - Can You Solve It
// Author	: timwilliam
// Compiled : 05/07/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_location_index(int x, int y){
	if(x == 0 && y == 0){
		return 0;
	}

	int i, j, counter, lim,index;

	index = 0; i = 0; j = 0; lim = 1; counter = 0;

	while(1){
		index++;
		printf("idx %d\n", index);
		i = lim - counter;
		j = counter;

		printf("i, j %d, %d; x,y %d,%d\n", i, j, x, y);
		
		if(i == x && j == y){
			break;
		}
		
		if(i >= 0 && j <= lim){
			counter++;
		}
		
		if(i == 0 && j == lim){
			lim++;
			counter = 0;
			i = lim;
			j = 0;
		}
	}

	return index;
}

int main(void){
	int n, x, y, x_des, y_des, i, start, end;

	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		scanf("%d %d %d %d", &x, &y, &x_des, &y_des);

		start = get_location_index(y, x);
		end = get_location_index(y_des, x_des);
		printf("Case %d: %d\n", i, end - start);		
	}
}
