// Program	: CPE - p11678 Card's Exchange
// Author	: timwilliam
// Compiled	: 12/21/2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int A, B, A_card[100], B_card[100], i, A_count, B_count, j;
	char buffer[100], *token;

	while(1){
		scanf("%d %d", &A, &B);
		if(A == 0 && B == 0) break;
		
		// Reset the card array
		memset(A_card, 0, 100);
		memset(B_card, 0, 100);

		// Store A's card (without storing duplicates), using string parsing
		fflush(stdin);
		fgets(buffer, 100, stdin);
		buffer[strcspn(buffer, "\n")] = 0;

		i = 0;
		token = strtok(buffer, " ");
		while(token != NULL){
			if(i == 0 || atoi(token) > A_card[i-1]){
				A_card[i] = atoi(token);
				i++;
			}
			else A--;

			token = strtok(NULL, " ");
		}

		// Store B's card (without storing duplicates)
		fflush(stdin);
		fgets(buffer, 100, stdin);
		buffer[strcspn(buffer, "\n")] = 0;

		i = 0;
		token = strtok(buffer, " ");
		while(token != NULL){
			if(i == 0 || atoi(token) > B_card[i-1]){
				B_card[i] = atoi(token);
				i++;
			}
			else B--;

			token = strtok(NULL, " ");
		}

		// Find unique card from A, and B
		// 	- cards are always sorted ascendingly in the array, exploit this
		// 	- compare the A_card, and B_card side-by-side look for unique value
		//		and omit cards that both A, and B has while storing the rest
		i = 0; j = 0; A_count = A; B_count = B;
		while(i < A && j < B){
			if(A_card[i] < B_card[j]) i++;
			else if(A_card[i] == B_card[j]){
				i++; A_count--;
				j++; B_count--;
			}
			else if(A_card[i] > B_card[j]) j++;
		}

		if(A_count <= B_count) printf("%d\n", A_count);
		else printf("%d\n", B_count);
	}
}
