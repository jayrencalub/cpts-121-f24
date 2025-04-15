#include "recursion.h"

int main(void) {
	int num = 0 , m = 3, n = 5;

	num = recursion_m_t_a(m, 5);
	printf("%d*%d: %d\n", m, n, num);

	n = 5;
	num = factorial_rec(n);
	printf("%d!: %d\n", n, num);

	return 0;
}