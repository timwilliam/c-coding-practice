// Problem  : UVA 10050 - Hartals
// Author   : timwilliam
// Compiled : 05/29/2021

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b){
    return(*(int*) a - *(int*) b);
}

int is_in_list(int *list, int n, int hartal_count){
    int i, status = 0;

    for(i = 1; i <= hartal_count; i++){
        if(list[i] == n){
            //printf("--> Found %d in the list!\n", list[i]);
            status = 1;
            break;
        }
    }

    return status;
}

int main(void){
	int T, N, P, *hartal_param, **hartals, n_hartals, *list_of_hartals;
	int i, j, hartal_count, friday;

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

		// go through hartals of each party and store them
        n_hartals = 0;
        for(i = 0; i < P; i++)
            n_hartals += hartals[i][0];

        list_of_hartals = malloc(n_hartals * sizeof(int));
        hartal_count = 0;
        
		for(i = 0; i < P; i++){
            friday = 6;
            // store hartals in a list
			for(j = 1; j <= hartals[i][0]; j++){
                //printf("now at party %d, hartals = %d\n", i+1, hartals[i][j]);

                // hartals already exist in list
                if(is_in_list(list_of_hartals, hartals[i][j], hartal_count)){
                    //printf("--> Already in list, skip!\n");
                    continue;
                }
                else{
                    // check if it is Friday or Saturday
                    while(hartals[i][j] > friday)
                        friday += 7;

                    if(hartals[i][j] % friday == 0 || hartals[i][j] % 7 == 0){
                        //printf("--> It is Friday(%d)/Saturday, skip (%d)!\n", friday, hartals[i][j]);
                        continue;
                    }
                    else{
                        list_of_hartals[hartal_count] = hartals[i][j];
                        hartal_count++;             
                    }
                }
            }
		}
        
        qsort(list_of_hartals, hartal_count, sizeof(int), cmpfunc);
        /*
        for(i = 0; i < hartal_count; i++)
            printf("%d ", list_of_hartals[i]);
        printf("\n");
        */

        printf("%d\n", hartal_count);

        free(list_of_hartals);
        free(hartal_param);
        for(i = 0; i < P; i++){
            int *ptr = hartals[i];
            free(ptr);
        }   
	}	
}
