#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_fibonacci_num(int);

int main(void) {
	int term = 0, next_num = 0;

	printf("Enter the nth term: ");
	scanf("%d", &term);

	next_num = get_fibonacci_num(term);

	printf("%d", next_num);

	return 0;
}

int get_fibonacci_num(int term) {

	int next_num = 0, n1 = 0, n2 = 1, n3 = 0, counter = 1;
	while (counter <= term - 2) {
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		counter++;
	}
	next_num = n3;

	return next_num;
}