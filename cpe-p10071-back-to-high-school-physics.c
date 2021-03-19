// Program	: CPE - p10071 Back to High School Physics
// Author	: Timothy William
// Compiled	: 03/19/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int v, t, x;

	// EOF terminates with Ctrl-D
	while(scanf("%d %d", &v, &t) != EOF){
		x = v * t * 2;
		printf("%d\n", x);
	}
}
