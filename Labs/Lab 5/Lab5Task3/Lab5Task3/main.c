#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int greatest_common_divisor(int, int);

int main(void) {
	int num1 = 0, num2 = 0, gcd = 0;
	FILE* infile = NULL;
	FILE* outfile = NULL;

	infile = fopen("data.txt", "r");
	outfile = fopen("output.txt", "w");

	fscanf(infile, "%d", &num1);
	fscanf(infile, "%d", &num2);

	gcd = greatest_common_divisor(num1, num2);

	fprintf(outfile, "%d", gcd);

	fclose(infile);
	fclose(outfile);

	return 0;
}

int greatest_common_divisor(int num1, int num2) {
	num1 = abs(num1);
	num2 = abs(num2);
	int gcd = 0;
	int remainder = num1 % num2;

	for (remainder; remainder != 0; remainder = num1 % num2) {
		num1 = num2;
		num2 = remainder;
	}

	gcd = num2;

	return gcd;
}