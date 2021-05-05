// Problem	: UVA 10190 - Divide But Not Quite Conquer!
// Author	: timwilliam
// Compiled	: 05/05/2021

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
	int n, m, k, a[1000], temp, boring_flag, i;

	while(1){
		memset(a, 0, sizeof(a));

		// get input n, and m
		if(scanf("%d", &n) == EOF)
			break;
		scanf("%d", &m);

		if(n == 0 && m == 0 || n == 0 || m == 0 || n % m != 0){
			printf("Boring!\n");
			continue;
		}

		// get the sequence
		k = 0;
		while(1){
			a[k] = n;
			k++;

			if(k == 0)
				continue;

			n = n / m;

			if(n == 0)
				break;
		}

		// Determine if the sequence is boring or not
		// 	Check for restriction 2
		boring_flag = 0;
		for(i = 0; i < k - 1; i++){
			if(a[i] % m != 0){
				boring_flag = 1;
				break;
			}
		}

		if(boring_flag == 1)
			printf("Boring!\n");
		else{
			for(i = 0; i < k; i++)
				printf("%d ", a[i]);

			printf("\n");
		}
		
	}
}
