#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_FAILURES 7

int main(void) {
	char word[] = { 'f', 'o', 'r', 't', 'n', 'i', 't', 'e' };
	char word_tracker[] = { '*', '*', '*', '*', '*', '*', '*', '*' };

	char guess = '\0';
	int success = 0, failures = 0, guessed_word = 0;

	while (failures <= MAX_FAILURES && guessed_word == 0) {
		printf("Word status: ");
		for (int i = 0; i < 8; i++) {
			printf("%c", word_tracker[i]);
		}

		printf("\nEnter a letter! (lower case only)\n");
		scanf(" %c", &guess);

		success = 0;

		// check if word is a success
		for (int i = 0; i < 8; i++) {
			if (guess == word[i]) {
				word_tracker[i] = guess;
				success = 1;
			}
		}

		if (success == 0) {
			failures++;
		}

		guessed_word = 1;
		// check if arrays are equal
		for (int i = 0; i < 8; i++) {
			if (word[i] != word_tracker[i]) {
				guessed_word = 0;
				break;
			}
		}

		printf("\n");
	}

	printf("You found the word!\n");

	return 0;
}