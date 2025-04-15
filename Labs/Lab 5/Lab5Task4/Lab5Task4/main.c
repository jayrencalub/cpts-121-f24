#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int main(void) {
	int high = INT_MIN, low = INT_MAX, num = 0;
	FILE* infile = NULL;

	infile = fopen("data.txt", "r");

	while (!feof(infile)) {
		fscanf(infile, "%d", &num);
		if (num > high) {
			high = num;
		}
		if (num < low) {
			low = num;
		}
	}

	fclose(infile);

	printf("high: %d", high);
	printf("\nlow: %d", low);

	return 0;
}