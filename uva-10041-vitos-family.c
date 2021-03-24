// Problem	: UVA 10041 - Vito's Family
// Author	: Timothy William
// Compiled	: 03/24/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int fcmp(const void *a, const void*b){
	return (*(int*) a - *(int*) b);
}

int main(void){
	int T, r, s[30000], i, vito, sum, count;

	scanf("%d", &T);
	while(T--){
		memset(s, 0, 30000);
		
		scanf("%d", &r);
		
		for(i = 0; i < r; i++){
			scanf("%d", &s[i]);
		}
		count = i;

		// Sort the array
		qsort(s, i + 1, sizeof(int), fcmp);

		// Count the median
		if(count % 2 == 0) vito = count / 2;
		else vito = (count + 1) / 2;

		sum = 0;
		for(i = 0; i < r; i++){
			sum += abs(s[vito - 1] - s[i]);
		}

		printf("%d\n", sum);
	}
}
