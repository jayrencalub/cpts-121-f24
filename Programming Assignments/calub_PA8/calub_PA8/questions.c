/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 8
* Date: 12/6/2024
* Description: This program runs a number of functions that may be
*			   required to do during an interview.
*****************************************************************/

#include "questions.h"

void my_str_n_cat(char* destination, char* source, int n) {
	int count = 0;
	char temp = '\0';

	while (*source != '\0' && count < n) {
		temp = *source;
		*destination = temp;

		destination++;
		source++;
		count++;
	}
}

int binary_search(int arr[], int target, int size) {
	int target_index = -1, left = 1, right = size, mid = 0, found = 0;

	while (found == 0 && left <= right) {
		mid = (left + right) / 2; // 1 2 3 5 10

		if (arr[mid] == target) {
			found = 1;
			target_index = mid;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return target_index;
}

void bubble_sort(char* arr[], int size) {
	int u = size, c = 0;

	while (u > 1) {
		c = 1;

		while (c < u) {
			if (strcmp(arr[c - 1], arr[c]) > 0) {
				char* temp = arr[c];
				arr[c] = arr[c - 1];
				arr[c - 1] = temp;
			}

			c++;
		}

		u--;
	}
}

int is_palindrome(char* str, int length) { // is_palindrome(str + 1, length - 2);
	int result = 0;
	char* end = str + length - 1;
	char start_char = *str, end_char = *end;

	if (length <= 1) {
		return result;
	}
	else {
		if (start_char == end_char) {
			result = 1;
		}
		else {
			result = 0;
		}
		result = is_palindrome(str + 1, length - 2);
	}
}

int sum_primes(unsigned int n) {
	int sum = 0, is_prime = 1;;

	if (n == 2) {
		return sum + 2;
	}
	else {
		for (unsigned int i = 2; i < n; i++) {
			if (n % i == 0) { // determining whether the number isn't prime
				is_prime = 0;
				break;
			}
		}
		
		if (is_prime == 1) { // n is a prime number
			sum = sum_primes(n - 1) + n;
		}
		else {
			sum = sum_primes(n - 1);
		}
	}

	return sum;
}

void maximum_occurences(char* str, Occurrences* occ, int* num, char* letter) {
	int num_chars = strlen(str), current_char = 0;

	// counting the number each number appears
	for (int i = 0; i < num_chars; i++) {
		current_char = (int)str[i];
		occ[current_char].num_occurrences++;
	}

	// calculating the frequency for each letter
	for (int i = 0; i < 127; i++) {
		occ[i].frequency = occ[i].num_occurrences / num_chars;
	}

	// getting the most used character
	int max_index = 32;
	for (int i = max_index + 1; i < 127; i++) { // 32: start of alphanumerical ascii codes
		if (occ[i].num_occurrences > occ[max_index].num_occurrences) {
			max_index = i;
		}
	}
	*num = occ[max_index].num_occurrences;
	*letter = (char)max_index;
}