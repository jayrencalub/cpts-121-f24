#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char* string_reverse(char str[]);
void pointer_reverse(char* string);

int main(void) {
	char str[] = "Hello!";

	string_reverse(str);
	puts(str);

	pointer_reverse(str);
	puts(str);

	return 0;
}

// part a - array style
char* string_reverse(char str[]) {
	int index = 0, left = 0, right = 0, right_index = 0, length = 0;

	// find the length of the string
	while (str[index] != '\0') {
		length++;
		index++;
	}

	right_index = length - 1;
	for (index = 0; index < right_index; index++) {
		left = str[index];
		right = str[right_index];
		str[index] = right;
		str[right_index] = left;
		right_index--;
	}

	return str;
}

// part b - pointer style
void pointer_reverse(char* str) {
	int length = 5;
	char* start = str, *end = str, temp = '\0';

	while (*end != '\0') {
		end++;
	}
	end--;

	while (start < end) { // hello
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}