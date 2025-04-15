#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int array[] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; i++) {
		printf("%d\n", array[i]);
	}

	return 0;
}