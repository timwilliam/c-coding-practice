// Problem	: UVA 12019 - Doom's Day Algorithm
// Author	: timwilliam
// Compiled	: 05/27/2021

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int T, M, D, days;
	int doom[12] = {10, 21, 7, 4, 9, 6, 11, 8, 5, 10, 7, 12};

	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &M, &D);

		if(D == doom[M-1]){
			days = D;
		}
		else if(D >= doom[M-1]){
			days = D - doom[M-1] + 1;
		}
		else{
			days = D - doom[M-1] + 7 + 1;
		}

		if(days > 7){
			days %= 7;
		}

		if(days == 1)
			printf("Monday\n");
		else if(days == 2)
			printf("Tuesday\n");
		else if(days == 3)
			printf("Wednesday\n");
		else if(days == 4)
			printf("Thursday\n");
		else if(days == 5)
			printf("Friday\n");
		else if(days == 6)
			printf("Saturday\n");
		else	
			printf("Sunday\n");
	}
}
