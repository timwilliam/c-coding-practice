// Program	: UVA 11063 - B2-Sequence
// Author	: timwilliam
// Compiled	: 04/28/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int N, sequence[100], i, j, result[1000], flag, n_case;

	n_case = 1;
	while(1){
		if(scanf("%d", &N) == EOF)
			break;

		memset(sequence, 0, sizeof(sequence));
		for(i = 0; i < N; i++)
			scanf("%d", &sequence[i]);

		getchar(); // To remove the trailing \n for the last input
		getchar(); // To get the \n as a break for each input

		memset(result, 0, sizeof(result));
		for(i = 0; i < N; i++){
			for(j = i; j < N; j++)
				result[sequence[i] + sequence[j]] += 1;
		}

		// check if there are duplicates for bi+bj
		flag = 0;
		for(i = 0; i < 100; i++){
			if(result[i] > 1){
				flag = 1;
				break;
			}
		}

		if(flag == 0)
			printf("Case #%d: It is a B2-Sequence\n", n_case);
		else
			printf("Case #%d: It is not a B2-Sequence\n", n_case);

		n_case++;
	}
}
