// Problem	: UVA 1587 - Box
// Author	: timwilliam
// Compiled	: 06/28/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_func(const void *a, const void *b){
	return *(int*) a - *(int*) b;
}

int main(void){
	int i, j, w[6], l[6], temp, flag;

	while(1){
		memset(w, 0, sizeof(w));
		memset(l, 0, sizeof(l));
		flag = 0;

		for(i = 0; i < 6; i++){
			scanf("%d %d", &w[i], &l[i]);

			// swap
			if(w[i] > l[i]){
				temp = w[i];
				w[i] = l[i];
				l[i] = temp;
			}	
		}

		qsort(w, 6, sizeof(int), cmp_func);
		qsort(l, 6, sizeof(int), cmp_func);

		// check for the properties of a parallelepiped
		if(w[0] == w[1] && l[0] == l[1] && w[2] == w[3] && l[2] == l[3] &&\
				w[4] == w[5] && l[4] == l[5]){
			if(w[0] == w[2] && w[4] == l[0] && l[2] == l[4])
				flag = 1;
			else
				flag = 0;
		}
		else
			flag = 0;

		if(flag == 1)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
}
