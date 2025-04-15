#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int length = 0, temp = 0, left = 0, right = 0;
	int arr[3] = { 1 };
	FILE* infile = NULL;

	infile = fopen("numbers.txt", "r");

	while (fscanf(infile, "%d", &temp) != EOF) {
		length++;
	}

	fclose(infile);
	infile = fopen("numbers.txt", "r");

	// getting the normal array
	for (int i = 0; i < length; i++) {
		fscanf(infile, "%d", &temp);
		arr[i] = temp;
	}

	// swapping the array
	int right_index = length - 1;
	for (int i = 0; i < length / 2; i++) {
		left = arr[i];
		right = arr[right_index]; // arr = {1, 2, 3}
		arr[i] = right;
		arr[right_index] = left;
		right_index--;
	}

	// printing the reversed array
	for (int i = 0; i < length; i++) {
		printf("%d\n", arr[i]);
	}
	
	return 0;
}