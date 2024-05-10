#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_ALPHABET 26

bool compare(int *charCountS, int *charCountT){
	int i;

	for(i = 0; i < NUM_ALPHABET; i++) {
		if(charCountS[i] != charCountT[i]) {
			return false;
		}
	}

	return true;
}

void printCharCount(int *charCount){
	int i;

	for(i = 0; i < NUM_ALPHABET; i++) {
		printf("%d: %c = %d\n", i + 1, 'a' + i, charCount[i]);
	}
}

void countChar(char *arr, int arrLen, int *count){
	int i;

	for(i = 0; i < arrLen; i++) {
		count[arr[i] - 'a'] += 1;
	}
}

bool isAnagram(char* s, char* t) {
	int charCountS[NUM_ALPHABET] = {0};
	int charCountT[NUM_ALPHABET] = {0};

	// count the number of character occurences in a word
	countChar(s, strlen(s), charCountS);
	countChar(t, strlen(t), charCountT);

	// printCharCount(charCountS);
	// printCharCount(charCountT);

	// character count of two words should be equal for valid anagram
	return compare(charCountS, charCountT);
}

int main() {
	// char s[] = "anagram";
	// char t[] = "nagaram";
	char s[] = "rat";
	char t[] = "car";

	if(isAnagram(s, t) == true) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}

	return 0;
}
