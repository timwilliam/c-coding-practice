// Program	: CPE - p11455 Behold My Quadrangle
// Author	: Timothy William
// Compiled	: 03/19/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *elem1, const void *elem2){
	return (*(int*)elem1 - *(int*)elem2);
}

int main(void){
	int i, n, in[4];

	scanf("%d", &n);
	getchar();

	while(n--){
		scanf("%d %d %d %d", &in[0], &in[1], &in[2], &in[3]);
		getchar();

		qsort(in, 4, sizeof(int), cmpfunc);

		if(in[0] == in[1] && in[1] == in[2] && in[2] == in[3]) printf("square\n");
		else if(in[0] == in[1] && in[2] == in[3]) printf("rectangle\n");
		else if(in[0] + in [1] + in [2] > in[3]) printf("quadrangle\n");
		else printf("banana\n");
	}
}
