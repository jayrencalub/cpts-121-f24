#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int count = 1, sum_scores = 0, score = 0;
	FILE* infile = NULL, * outfile = NULL;
	infile = fopen("scores.txt", "r");

	while (!feof(infile)) {
		fscanf(infile, "%d", &score);
		sum_scores += score;
	}
	printf("sum: %d\n", sum_scores);

	while (count <= 10) { // counting loop
		printf("%d\n", count);

		// count = count + 1;
		// count++;
		count += 1;
	}

	for (int i = 1 /*initial expression*/; i <= 10/*repitition condition*/; i++/*update expression*/) {
		printf("%d\n", i);
	}

	// count's value is 11
	count = 1;
	do {
		printf("%d\n", count);
		count++;
	} while (count <= 10);

	return 0;
}