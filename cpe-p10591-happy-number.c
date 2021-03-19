// Program	: CPE - p10591 Happy Number
// Author	: Timothy William
// Compiled	: 03/19/2021

#include<stdio.h>
#include<stdlib.h>

int main(void){
	int p, N, i;
	int flag, happy_flag, S, remainder, temp, checked_array[1000];

	scanf("%d", &p);
	getchar(); // Trim newline character
	
	i = 1;
	while(i <= p){
		scanf("%d", &N);
		getchar(); // Trim newline characterr

		// Reset variables
		flag = 0; happy_flag = 0; 
		temp = N; memset(checked_array, 0, 1000);

		while(flag != 1){

			S = 0; // Sum
			while(temp > 0){
				remainder = temp % 10;
				temp = temp / 10;

				// Square each digits, then add each squared digits
				S = S + remainder * remainder;
			}

			temp = S; // S1

			// checked_array is used to store previously checked number
			// - so that the program does not go into infinited loop
			// - stop whenever a number has already been in checked_array
			if(temp == N || checked_array[temp] == 1){
				flag = 1;
			}
			else if(temp == 1){
				flag = 1;
				happy_flag = 1; // happy number found !!!
			}
			else
				checked_array[temp] = 1; // remember that a number has been checked
		}

		if(happy_flag == 1) printf("Case #%d: %d is a Happy number.\n", i , N);
		else printf("Case #%d: %d is an Unhappy number.\n", i, N);

		i++;
	}
}
