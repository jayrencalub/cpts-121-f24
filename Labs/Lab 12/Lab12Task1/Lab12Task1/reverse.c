#include "reverse.h"

char* recursion_reverse_string(char str[], int left, int right) {
	// "Hello!" to "!olleH"
	if (left > right) {
		return str;
	}
	char temp = str[left];
	str[left] = str[right];
	str[right] = temp;

	left++;
	right--;

	recursion_reverse_string(str, left, right);
}