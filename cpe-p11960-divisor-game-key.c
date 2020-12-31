#include<stdlib.h>
#include<stdio.h>

int Table[1000001], Ans[1000001];

void Create_Table(){
	int Max = 0, ans;

	for(int i=1; i <= 6; i++){
		printf("i=%d\n", i);
		for(int j=i; j <= 6; j=j+i){	
			Table[j] += 1;
			printf("	j=%d, Table[%d]=%d\n", j, j, Table[j]);
		}
	}

	printf("ANS:\n");
	for(int i=1; i <= 6; i++){
		if(Max <= Table[i]){
			Max = Table[i];
			ans = i;
			Ans[i] = ans;
		}
		else{
			Ans[i] = ans;
		}
		printf("- i=%d, Ans[%d]=%d\n", i, i, Ans[i]);
	}
}

int main(void){
	int n, m;
	Create_Table();
	//scanf("%d", &n);
	n = 1;
	while(n--){	
		//scanf("%d", &m);
		m = 6;
		printf("%d\n", Ans[m]);
	}
}
