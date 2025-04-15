#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_sum(FILE*);
int is_prime(int);
int sum_digits(int);

int main(void) {
	int sum = 0, s_digits = 0;
	FILE* infile = fopen("numbers.txt", "r");

	sum = get_sum(infile);
	printf("%d\n", sum);
	
	s_digits = sum_digits(sum);
	
	printf("%d", is_prime(s_digits));

	return 0;
}

int get_sum(FILE* infile) {
	int num = 0, sum = 0;
	while (!feof(infile)) {
		fscanf(infile, "%d", &num);
		sum += num;
	}
	return sum;
}

int is_prime(int num) {
	int result = 1; // not a prime unless proven otherwise
	for (int i = 2; !(num == i); i++) {
		if (num % i == 0) {
			result = 0;
		}
	}
	return result;
}

int sum_digits(int num) {
	int sum = 0, temp = 0;
	while (num > 0) {
		temp = num % 10;
		sum += temp;
		num = num / 10;
	}
	return sum;
}
