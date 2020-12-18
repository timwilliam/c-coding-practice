// Program	: CPE - p299 Train Swapping
// Author	: timwilliam
// Compiled	: 12/18/2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void){
	int N, L, train_order[50], i, j, k, len, swap_count, pos;
	char buffer[100];

	//TODO 1. Get the number of test cases
	scanf("%d", &N);

	for(i=0; i < N; i++){
		//TODO 2. Get the number of train in a test case
		scanf("%d", &L);
	
		//TODO 3. Get the order of trai
		// Store the input string into a string buffer
		fflush(stdin);
		fgets(buffer, 100, stdin);
		buffer[strcspn(buffer, "\n")] = 0;
		len = strlen(buffer);
	
		// Store the number in the string into the train_order array
		j = 0; k = 0;
		for(j=0; j < len; j++){
			if(buffer[j] != ' '){
				train_order[k] = buffer[j] - '0';
				k++;
			}
		}

		//TODO 4. Perform train sorting
		swap_count = 0;
		k = 1;
		while(k <= L){
			if(train_order[k-1] == k){
				k++;
				continue;
			}

			// Find the location of the right sequence in train_order
			pos = k;
			for(j = k; j <= L; j++){
				if(train_order[j] != k) pos++;
				else break;
			}
		
			// Swap the order to the right position
			for(j = pos; j >= k; j--){
				swap(&train_order[j], &train_order[j-1]);
				swap_count++;
			}

			k++;
		}
	 	
		printf("Optimal train swapping takes %d swaps.\n", swap_count);
	}
}
