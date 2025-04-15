#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void examples();
void task1();
void print_binary(unsigned int decimal_num);

int main() {
	unsigned int a = 201;

	//examples();
	//task1();

	printf("Binary number of %d: ", a);
	print_binary(a);

	return 0;
}

void examples() {
	unsigned int a = 8;  // 0000000000000101

	unsigned int b = 2; // 0010

	unsigned int c = 10;  // 0000000000000110

	unsigned int d = 5;

	// Left shifting 
	/*printf("%d\n", a);
	int c = b >> 2;
	printf("%d\n", c);*/

	// bitwise and
	printf("%d\n", a & c);

	// bitwise or
	printf("%d\n", a | c);

	// bitwise xor
	printf("%d\n", a ^ c);

	// not operator
	printf("%u\n", d); // 0000000000000101
	printf("%u\n", ~d); // 1111111111111010
}

void task1() {
	unsigned int decimal = 32;

	print_binary(decimal);

	printf("%d\n", decimal);

	decimal = decimal >> 4;
	print_binary(decimal);

	printf("%d\n", decimal);
}

void print_binary(unsigned int decimal_num) {
	for (int i = 7; i >= 0; i--) {
		if (pow(2, i) <= decimal_num) {
			printf("%d", 1);
			decimal_num -= pow(2, i);
		}
		else {
			printf("%d", 0);
		}
	}
	
	printf("\n");
}