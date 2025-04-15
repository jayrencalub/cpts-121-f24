#include "recursion.h"

// using iteration
int mult_thru_addition(int m, int n) {
	int sum = 0;

	while (n > 0) {
		sum += m;
		n--;
	}

	return sum;
}

// using recursion
int recursion_m_t_a(int m, int n) {
	int sum = 0;

	if (n == 1) { // base case
		sum = m;
	}
	else { // recursive step
		sum = recursion_m_t_a(m, n - 1) + m;
	}

	return sum;
}

int factorial_rec(int n) {
	int product = 0;

	if (n == 0) {
		product = 1;
	}
	else {
		product = factorial_rec(n - 1) * n;
	}

	return product;
}