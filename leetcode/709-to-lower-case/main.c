#include <ctype.h>
#include <stdio.h>
#include <string.h>

char* toLowerCase(char* s) {
	int i = 0;
	int len = strlen(s);

	for(i = 0; i < len; i++) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = tolower(s[i]);
		}
	}

	return s;
}

int main(void) {
	// char str[] = "Hello";
	// char str[] = "here";
	char str[] = "LOVELY";

	printf("%s\n", toLowerCase(str));

	return 0;
}
