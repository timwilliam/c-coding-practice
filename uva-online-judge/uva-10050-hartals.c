#include <stdio.h>
#include <stdlib.h>

int main(void){
	int T, N, P, *hartal_param, **hartals, n_hartals, *list_of_hartals;
	int i, j;

	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		scanf("%d", &P);

		hartal_param = malloc(P * sizeof(int));
		for(i = 0; i < P; i++)
			scanf("%d", &hartal_param[i]);

		// get the hartals of each party
		hartals = malloc(P * sizeof(int*));
		for(i = 0; i < P; i++){
			n_hartals = N / hartal_param[i];
			hartals[i] = malloc((1 + n_hartals) * sizeof(int));

			hartals[i][0] = n_hartals;
			for(j = 1; j <= n_hartals; j++)
				hartals[i][j] = j  * hartal_param[i];
		}

		/*
		for(i = 0; i < P; i++){
			n_hartals = hartals[i][0];
			printf("n_hartals %d\n", n_hartals);
			for(j = 1; j <= n_hartals; j++)
				printf("%d ", hartals[i][j]);

			printf("\n");
		}*/

		// store the hartals
		for(i = 0; i < P; i++){
			for(j = 0; j )
		}
	}	
}
