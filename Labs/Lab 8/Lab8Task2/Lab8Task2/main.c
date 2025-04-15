#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int remove_whitespace(char arr[], int length);

int main(void) {
	int count = 0;
	char list[] = { 'C', 'p', 't', 'S', ' ', '1', '2', '1', ' ', 'i', 's', ' ', 'f', 'u', 'n' };
	//char list[] = { 'C', 'p', 't', 'S', '1', '2', '1', 'i', 's', ' ', 'f', 'u', 'n' };

	count = remove_whitespace(list, 15);

	printf("\n%d", count);

	return 0;
}

int remove_whitespace(char arr[], int length) {
	int count = 0, temp = 0;

	for (int i = 0; i < length; i++) {
		// ascii value of whitespace is 32
		if (arr[i] == 32) {
			for (int j = i; j < length; j++) {
				temp = arr[i];
				arr[j] = arr[j + 1];
			}

			count++;
		}
	}

	for (int i = 0; i < length; i++) {
		printf("%c ", arr[i]);
	}

	return count;
}