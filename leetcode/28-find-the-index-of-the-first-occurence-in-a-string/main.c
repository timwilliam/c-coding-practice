#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
	char *temp = strstr(haystack, needle);

	if(temp == NULL) {
		return -1;
	}
	else {
		return (int) (temp - haystack);
	}
}

int main(void) {
	// char haystack[] = "sadbutsad";
	// char needle [] = "but";

	char haystack[] = "leetcode";
	char needle[] = "leeto";

	printf("%d\n", strStr(haystack, needle));

	return 0;
}
