#include<stdlib.h>
#include<stdio.h>

int Table[1000001], Ans[1000001];

void Create_Table(){
	int Max = 0, ans;

	for(int i=1; i <= 1000000; i++){
		for(int j=i; j <= 1000000; j=j+i){	
			Table[j] += 1;
		}
	}

	for(int i=1; i <= 1000000; i++){
		if(Max <= Table[i]){
			Max = Table[i];
			ans = i;
			Ans[i] = ans;
		}
		else{
			Ans[i] = ans;
		}
	}
}

int main(void){
	int n, m;
	Create_Table();
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);	
		printf("%d\n", Ans[m]);
	}
}
