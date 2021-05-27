// Problem	: UVA 10812 - Beat the Spread!
// Author	: timwilliam
// Compiled	: 04/22/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int s, d, a, b, T, temp;

	scanf("%d", &T);

	while(T--){
		scanf("%d %d", &s, &d);

		temp = s - d;
		if(temp < 0){
			printf("impossible\n");
			continue;
		}

		a = temp / 2;
		b = s - a;

		if(b >= a)
			printf("%d %d\n", b, a);
		else
			printf("%d %d\n", a, b);

	}
}
