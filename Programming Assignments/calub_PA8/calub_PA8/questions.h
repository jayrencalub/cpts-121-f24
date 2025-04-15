/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 8
* Date: 12/6/2024
* Description: This program runs a group of functions that may be 
			   on an interview question.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#ifndef QUESTIONS_H
#define QUESTIONS_H

typedef struct occurrences {
	int num_occurrences;
	double frequency;
} Occurrences;

void my_str_n_cat(char* destination, char* source, int n);
int binary_search(int arr[], int target, int size);
void bubble_sort(char* arr[], int size);
int is_palindrome(char* str, int length); // recursive step: (str + 1, length - 2);
int sum_primes(unsigned int n);
void maximum_occurences(char* str, Occurrences* occ, int* num, char* letter); // array size 127, use each index for index of ascii value

#endif

