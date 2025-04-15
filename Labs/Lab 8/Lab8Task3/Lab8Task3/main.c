#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void) {
	int numbers[20] = { 0 };
	int frequency[101] = { 0 };
	int count = 0;

	srand((unsigned int)time(NULL));

	// getting the 20 numbers
	printf("Numbers: ");
	for (int i = 0; i < 20; i++) {
		numbers[i] = rand() % 100 + 1;
		printf("%d ", numbers[i]);
	}
	printf("\n\n");

	// getting the frequency
	for (int i = 0; i < 101; i++) {
		count = 0;
		for (int j = 0; j < 20; j++) {
			if (i == numbers[j]) {
				count++;
			}
		}
		frequency[i] = count;
	}

	for (int i = 0; i < 101; i++) {
		printf("%d ", frequency[i]);
	}

	return 0;
}