#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void divide(int, int, int*, int*);
void get_discount(double cost, int num_people, int *discount_btr, double *amount_btr);
void init_array(int arr[], int size);
void print_array(int arr[], int size);
int sequential_search(int arr[], int size, int target);
// precondition: the array has to be in numerical order
int binary_search(int arr[], int size, int target);

int main(void) {

	int n = 1;
	int* btr = &n; // btr -> address of n

	int n1 = 7, n2 = 3, quotient = 0, remainder = 0, discount = 0;
	double amount = 0;

	int array[] = { 1, 2, 3, 4, 5 };
	int found = sequential_search(array, 5, 100);
	printf("%d", found);

	/*print_array(array, 5);
	init_array(array, 5);
	print_array(array, 5);*/

	/*divide(n1, n2, &quotient, &remainder);
	printf("address of quotient: %d, %p, remainder: %d, %p\n", quotient, &quotient, remainder, &remainder);
	printf("%d\n%d\n", quotient, remainder);
	
	get_discount(5000, 5, &discount, &amount);
	printf("discount: %d\namount: %lf", discount, amount);*/

	return 0;
}

// function that divides 2 ints, returns quotient and remainder
void divide(int n1, int n2, int *q_btr, int* rem_btr) {
	printf("Inside divide: n1: %d, n2: %d, q_btr: %p, rem_btr: %p\n",
		n1, n2, q_btr, rem_btr);
;	*q_btr = n1 / n2; // * indirection operator - dereference operator
	*rem_btr = n1 % n2;
}

void get_discount(double cost, int num_people, int* discount_btr, double* amount_btr) {
	if (cost >= 2000) {
		*discount_btr = 10; // 10 percent
		*amount_btr = cost * ((double)*discount_btr / 100);
	}
	else if (cost >= 1000) {
		*discount_btr = 5; // 5 percent
		*amount_btr = cost * ((double)*discount_btr / 100);
	}
}

void init_array(int arr[], int size) {
	int i = 0;

	while (i < size) {
		printf("Enter an integrer: ");
		scanf("%d", &arr[i]);
		i++;
	}
}

void print_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}
}

int sequential_search(int arr[], int size, int target) {
	int i = 0, found = 0;

	while (i <= size && found == 0) {
		if (arr[i] == target) {
			found = 1;
		}
		else {
			i++;
		}
	}

	return found;
}

int binary_search(int arr[], int size, int target) {
	int i = 0, found = 0, temp = arr[size/2];

	while (found == 0) {
		if (temp > target) {
			
		}
		else if (temp < target) {

		}
		else {
			found = 1;
		}
	}

	return found;
}