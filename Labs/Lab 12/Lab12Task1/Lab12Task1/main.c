#include "reverse.h"

int main(void) {
	char str[100] = "Hello!";
	int right = strlen(str) - 1;

	recursion_reverse_string(str, 0, right);
	puts(str);

	return 0;
}