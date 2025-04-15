#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum_digits(int num);

int main(void) {
	int number = 1234, sum = 0;

	sum = sum_digits(number);
	printf("%d", sum);

	return 0;
}

int sum_digits(int num) {
	int sum = 0, temp = 0;

	if (num == 0) {
		sum = num;
	}
	else {
		temp = num % 10;
		num /= 10;

		sum = sum_digits(num) + temp;
	}

	return sum;
}