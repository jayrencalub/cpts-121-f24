#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int);

int main(void) {
	printf("%d", factorial(10));

	return 0;
}

int factorial(int n) {
	int result = 1;
	if (n == 0) {
		result = 1;
	}
	else {
		for (int i = n; i > 0; i--) {
			result *= i;
		}
	}
	return result;
}