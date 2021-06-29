// Problem	: UVA 865 - Substitution Cipher
// Author	: timwilliam
// Compiled	: 06/29/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substitute(char *sub, char target_char){
	int i, ret;

	ret = -1;
	for(i = 0; i < strlen(sub); i++){
		if(sub[i] == target_char){
			ret = i;
			break;
		}
	}

	return ret;
}

int main(void){
	int t, i, sub_pos;
	char sub[66], plain[66], text[66];

	scanf("%d", &t);
	getchar();
	getchar();

	while(t--){
		memset(sub, 0, sizeof(sub));
		memset(plain, 0, sizeof(plain));
		memset(text, 0, sizeof(text));

		// get the plain alphabet
		fgets(plain, 66, stdin);
		plain[strcspn(plain, "\n")] = 0;

		// get the sub alphabet
		fgets(sub, 66, stdin);
		sub[strcspn(sub, "\n")] = 0;

		printf("%s\n", plain);
		printf("%s\n", sub);

		while(fgets(text, 66, stdin)){
			if(strlen(text) == 1)
				break;

			text[strcspn(text, "\n")] = 0;
		
			// perform substitution using the array index
			for(i = 0; i < strlen(text); i++){
				sub_pos = substitute(plain, text[i]);
				if(sub_pos >= 0)
					text[i] = sub[sub_pos];
			}

			printf("%s\n", text);
		}		

	}
}
