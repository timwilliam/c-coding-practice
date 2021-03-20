#include <stdio.h>
#include <stdlib.h>

int main(void){
	int T, N, A, B, C, max_profit, i, j, l_floor, h_floor;

	scanf("%d", &T);
	getchar();
	
	for(i = 0; i < T; i++){
		scanf("%d", &N);
		getchar();

		A = B = C = max_profit = 0;
		l_floor = h_floor = 0;
		for(j = 0; j < N; j++){
			scanf("%d %d %d", &A, &B, &C);	
			getchar();

			// Assuming only 1 offer is taken, this logic will work
			// TODO: To be able to accept multiple offer and is not overlapping with one another
			if((A >= l_floor && A <= h_floor) || ((A + B) >= l_floor && (A + B) <= h_floor) || (l_floor == 0 && h_floor == 0)){
				if(C > max_profit){
					l_floor = A;
					h_floor = A + B;
					max_profit = C;
				}
			}	
		}
		
		printf("Case %d: %d\n", i + 1, max_profit);
	}
}
