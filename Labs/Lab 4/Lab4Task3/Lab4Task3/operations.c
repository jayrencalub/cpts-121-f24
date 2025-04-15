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

double calc_average(double n1, double n2, double n3, double n4, double n5) {
	return (n1 + n2 + n3 + n4 + n5) / 5;
}

double find_high(double n1, double n2, double n3, double n4, double n5) {
	double high = n1;

	if (n2 > high) {
		high = n2;
	}
	if (n3 > high) {
		high = n3;
	}
	if (n4 > high) {
		high = n4;
	}
	if (n5 > high) {
		high = n5;
	}

	return high;
}

double find_low(double n1, double n2, double n3, double n4, double n5) {
	double low = n1;

	if (n2 < low) {
		low = n2;
	}
	if (n3 < low) {
		low = n3;
	}
	if (n4 < low) {
		low = n4;
	}
	if (n5 < low) {
		low = n5;
	}

	return low;
}
