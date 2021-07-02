// Program	: UVA 10008 - What's Cryptanalysis?
// Author	: Timothy William
// Compiled	: 03/31/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b){
	return(*(int*) b - *(int*) a);
}

int main(void){
	int n, i, j, count[26], temp;
	char buffer[1000], ascii_code;

	scanf("%d", &n);
	getchar();

	memset(count, 0, sizeof(count));

	while(n--){
		memset(buffer, 0, sizeof(buffer));
		fgets(buffer, 1000, stdin);

		// Count each character occurence
		for(i = 0; i < strlen(buffer); i++){
			if(buffer[i] >= 65 && buffer[i] <= 90)
				count[(buffer[i] - 65)]++;
			else if(buffer[i] >= 97 && buffer[i] <= 122)
				count[(buffer[i] - 97)]++;
		}
	}

	// weight so that character that appears first in alphabet can be printed first
	j = 25;

	// hashing(?) the count so that it can be sorted based on count
	// e.g.:
	// 	a	count[0] = 6	-> 6 * 100 + (25 - 0)
	// 	b	count[1] = 3	-> 3 * 100 + (25 - 1)
	// 	c 	count[2] = 4	-> 4 * 100 + (25 - 2)
	// with this, character with highest count will be on top
	// then character whose alphabet appears first will be on top
	for(i = 0; i < 26; i++)
		count[i] = count[i] * 100 + (j - i);
	
	// Sort the count array
	qsort(count, 26, sizeof(int), cmpfunc);

	// Print the results
	for(i = 0; i < 26; i++){
		ascii_code = j - count[i] % 100 + 65;
		temp = count[i] / 100;

		if(temp == 0) continue;
		printf("%c %d\n", ascii_code, temp);
	}
}
