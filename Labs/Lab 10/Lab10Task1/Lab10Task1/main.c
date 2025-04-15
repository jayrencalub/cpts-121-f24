#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void) {
	char* article[] = { "The", "A", "One", "Some", "Any" },
		* noun[] = { "boy", "girl", "dog", "town", "car" },
		* verb[] = { "drove", "jumped", "ran", "walked", "skipped" },
		* preposition[] = { "to", "from", "over", "under", "on" };

	int index = 0;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 20; i++) {
		char sentence[10000] = "\0";

		index = rand() % 5;
		strcat(sentence, article[index]);
		strcat(sentence, " ");

		index = rand() % 5;
		strcat(sentence, noun[index]);
		strcat(sentence, " ");

		index = rand() % 5;
		strcat(sentence, verb[index]);
		strcat(sentence, " ");

		index = rand() % 5;
		strcat(sentence, preposition[index]);
		strcat(sentence, " ");

		puts(sentence);
	}

	

	return 0;
}