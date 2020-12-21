// Program	: CPE - p10530 Guessing Game
// Author	: timwilliam
// Compiled	: 12/21/2020

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int i, record[10], record_stats[10] , temp, n_record, lower_bound, upper_bound;
	char buffer[100];

	while(1){
		n_record = 0; lower_bound = 1; upper_bound = 10;
		memset(buffer, 0, 100);
		
		// Store each record in the transcript
		while(1){
			scanf("%d", &temp);
			if(temp == 0) exit(0);
			
			fflush(stdin);
			fgets(buffer, 100, stdin);
			buffer[strcspn(buffer, "\n")] = 0;
			
			// Store the transcript
			record[n_record] = temp;
			if(strcmp(buffer, "too high") == 0) record_stats[n_record] = 2;
			else if(strcmp(buffer, "too low") == 0) record_stats[n_record] = 1;
			else if(strcmp(buffer, "right on") == 0) record_stats[n_record] = 0;

			n_record++;
			
			// End of a transcript record
			if(strcmp(buffer, "right on") == 0) break;
		}

		// Analyze if Stan is dishonest or not
		int flag = 0;
		for(i = 0; i < n_record; i++){
			//printf("LB=%d, UB=%d\n", lower_bound, upper_bound);
			//printf("checking record: %d %d\n", record[i], record_stats[i]);
		
			if(record_stats[i] == 2 && upper_bound > record[i])
				upper_bound = record[i] - 1;
			else if(record_stats[i] == 1 && lower_bound < record[i])
				lower_bound = record[i] + 1;
			else if(record_stats[i] == 0){
				if(record[i] > upper_bound || record[i] < lower_bound) flag = 1;
			}

			//printf("New LB=%d, UB=%d\n", lower_bound, upper_bound);
		}

		if(lower_bound > upper_bound || flag == 1) 
			printf("Stan may be dishonest\n");
		else
			printf("Stan may be honest\n");
	}

}
