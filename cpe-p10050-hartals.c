// Program	: CPE - p10050 Hartals
// Author	: Timothy William
// Compiled	: 12/15/2020

#include<stdio.h>
#include<stdlib.h>

int main(void){
	int n_test, n_days, n_party, hartal_param[100], i, j;
	int hartal_days[3650], lost_days, fri, sat;

	scanf("%d", &n_test);
	while(n_test > 0){
		memset(hartal_days, 0, 3650); lost_days = 0; fri = 6; sat = 7;

		scanf("%d", &n_days);	
		scanf("%d", &n_party);
		for(i = 0; i < n_party; i++) scanf("%d", &hartal_param[i]);

		// Go through all party and mark the hartal days, skipping duplicate
		for(i = 0; i < n_party; i++){
			for(j = 1; j < n_days; j++){
				// Skip Friday, and Saturday
				if(j == fri){
				   	fri += 7;
					continue;
				}
				else if(j == sat){
					sat += 7;
					continue;
				}
				
				// Mark the days that have hartals
				if(j % hartal_param[i] == 0) hartal_days[j - 1] = 1;
			}
		}	

		// Calculate number of working days lose
		for(i = 0; i < n_days; i++){
			if(hartal_days[i] == 1) lost_days += 1;
		}

		printf("%d\n", lost_days);

		n_test--;
	}
}
