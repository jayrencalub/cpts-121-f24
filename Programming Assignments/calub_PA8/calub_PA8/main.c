/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 8
* Date: 12/6/2024
* Description: This program runs a group of functions that may be
			   asked during an interview.
*****************************************************************/

#include "questions.h"

int main(void) {
	// Question 1
	//char destination[50] = "", * source = "Hello!";

	//my_str_n_cat(destination, source, 3);
	//printf("copied word: %s\n", destination);

	// Question 2
	//int abc[5] = {1, 2, 3, 5, 10}, target = 10;
	//printf("index: %d\n", binary_search(abc, target, 5));

	// Question 3
	char* def[5] = { "water", "car", "dog", "cat", "tree" };
	bubble_sort(def, 5);

	// expected result: car, cat, dog, tree, water
	printf("sorted list: ");
	for (int i = 0; i < 5; i++) {
		printf("%s ", def[i]);
	}

	// Question 4
	//char* ghi = "race car";
	//printf("palindrome test for \'%s\': %d", ghi, is_palindrome(ghi, 8));

	// Question 5
	//unsigned int num = 30;
	//printf("%d", sum_primes(num));

	// Question 6
	//Occurrences occ[127] = { "0, 0" };
	//int max_num = 0;
	//char* jkl = "         abcd", max_letter = '\0';
	//maximum_occurences(jkl, occ, &max_num, &max_letter);
	//printf("most occuring character: %c\ncount: %d", max_letter, max_num);

	return 0;
}