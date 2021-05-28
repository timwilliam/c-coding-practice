// Problem	: UVA 10071 - Back to High School Physics
// Author	: timwilliam
// Compiled	: 05/28/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int v, t, x;

	while(1){
		scanf("%d %d", &v, &t);

		if(v == 0 && t == 0)
			break;

		x = 2 * v * t;
		printf("%d\n", x);
	}
}
