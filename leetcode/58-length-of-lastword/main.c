#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
	char *pch = strtok(s, " ");
	int len = 0;

	while(1){
		// printf("%s\n", pch);
		
		len = strlen(pch);
		pch = strtok(NULL, " ");

		if(pch == NULL) {
			return len;
		}
	}
}

int main(void) {
	// char s[] = "Hello World";
	// char s[] = "   fly me   to   the moon  "; 
	char s[] = "luffy is still joyboy"; 

	printf("%d\n", lengthOfLastWord(s));

	return 0;
}
