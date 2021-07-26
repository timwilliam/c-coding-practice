// Problem	: UVA 11364 - Parking
// Author	: timwilliam
// Compiled : 06/29/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int t, n, i, max, min, temp;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);

		max = -1;
		min = 100;

		for(i = 0; i < n; i++){
			scanf("%d", &temp);

			if(temp > max)
				max = temp;
			
			if(temp < min)
				min = temp;
		}
		
		printf("%d\n", (max-min) * 2);
	}
}
