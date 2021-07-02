// Problem	: UVA 11005 - Cheapest Base
// Author	: timwilliam
// Compiled	: 05/04/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dec_to_base_n(int decimal, int n, char *result){
	char base_char[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", buffer[26];
	int remainder, i = 0, temp;

	while(decimal != 0){
		remainder = decimal % n;
		decimal = decimal / n;

		if(n >= 10 && remainder >= 10){
			temp = remainder - 10;
			result[i] = base_char[temp];
		}
		else
			result[i] = '0' + remainder; 
		
		i++;
	}

	// Note that the conversion result is stored in reverse order in the array!!!
}

int main(void){
	int X, Y, n_Y, i, j, k, l, cost[36], price[37], min_price;
	char result[36], total_price;

	scanf("%d", &X);
	for(j = 1; j <= X; j++){
		memset(cost, 0, sizeof(cost));

		// store each of the printing cost
		for(i = 0; i < 36; i++)
			scanf("%d", &cost[i]);

		scanf("%d", &n_Y);
		printf("Case %d:\n", j);
		
		while(n_Y--){
			memset(price, 0, sizeof(price));
			
			// get the number to be calculated
			scanf("%d", &Y);	

			if(Y == 0){
				printf("Cheapest base(s) for number %d: ", Y);
				for(k = 2; k <= 36; k++){
					printf("%d ", k);
				}
				printf("\n");
				continue;
			}

			// convert Y to every available base
			for(k = 2; k <= 36; k++){
				memset(result, 0, sizeof(result));	

				dec_to_base_n(Y, k, result);
				//printf("DBG: %d -> %s (base %d)\n", Y, result, k);

				// calculate price for each base
				for(i = 0; i < strlen(result); i++){
					//printf("	result[i]=%c\n", result[i]);

					if(result[i] >= 'A' && result[i] <= 'Z'){
						price[k] += cost[result[i] - 'A' + 10];
						//printf("	cost of %c is %d\n", result[i], cost[result[i] - 'A' + 10]);
						//printf("	price[%d] now is at %d\n", k, price[k]);
					}
					else{
						price[k] += cost[result[i] - '0'];
						//printf("	price base %d is %d\n", k, cost[result[i] - '0']);
						//printf("	price[%d] now is at %d\n", k, price[k]);
					}
				}
			}
		
			// get cheapest price	
			min_price = 129;
			for(k = 2; k <= 36; k++){
				//printf("|base %d price = %d| ", k, price[k]);
				if(min_price >= price[k] && price[k] != 0)
					min_price = price[k];
			}
			//printf("\n");

			//printf("	DBG: min_price is %d\n", min_price);
			//printf("	DBG: %d price = %d, %d price = %d\n", 13, price[13], 31, price[31]);

			// print all of the base with cheapest price
			printf("Cheapest base(s) for number %d: ", Y);
			for(k = 2; k <= 36; k++){
				if(price[k] == min_price )
					printf("%d ", k);
			}
			printf("\n");
		}
	}
}
