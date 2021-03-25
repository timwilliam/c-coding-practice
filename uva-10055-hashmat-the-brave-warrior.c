// Program	: UVA 10055 - Hashmat the Brave Warrior
// Author	: Timothy William
// Compiled	: 03/25/2021

#include <stdio.h>
#include <stdlib.h>

int main(void){
	long int n1, n2;

	while(scanf("%ld %ld", &n1, &n2) != EOF){
		printf("%ld\n", labs(n1 - n2));
	}

}
