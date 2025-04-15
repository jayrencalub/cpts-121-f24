/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 4 Task 3
* Date: September 18, 2024
* Description: This program reads 5 numbers from a text file and
*			   performs 1 of the following 3 operations:
*			   average, high value, and low value
*****************************************************************/

#include "operations.h"

int main(void) {
	int option = 0;
	double n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, average = 0, high = 0, low = 0;
	FILE* input_stream = NULL, * output_stream;

	fopen("numbers.txt", "r");

	fscanf(input_stream, "%lf", &n1);
	fscanf(input_stream, "%lf", &n2);
	fscanf(input_stream, "%lf", &n3);
	fscanf(input_stream, "%lf", &n4);
	fscanf(input_stream, "%lf", &n5);

	fclose(input_stream);

	printf("Operations:\n1. Average\n2. High value\n3. Low value");
	prinf("Enter the number of your desired operation");

	scanf("%d", &option);
	if (option == 1) {
		calc_average(n1, n2, n3, n4, n5);
	}
	if (option == 2) {
		find_high(n1, n2, n3, n4, n5);
	}
	if (option == 3) {
		find_low(n1, n2, n3, n4, n5);
	}

	return 0;
}
