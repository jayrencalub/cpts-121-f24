/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 2 Task 1
* Date: September 4, 2024
* Description: This program computes the perpendicular bisector
*			   a line segment between two points inputted by a user.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// variables
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	double slope = 0, bisector_slope = 0, x_mid = 0, y_mid = 0, y_intercept = 0;

	// prompt the user for the first point
	printf("Enter the x and y coordinates for the first point: ");
	scanf("%d%d", &x1, &y1);

	// prompt the user for the second point
	printf("Enter the x and y coordinates for the second point: ");
	scanf("%d%d", &x2, &y2);

	// compute the slopes and midpoints
	slope = (double)(y2 - y1) / (double)(x2 - x1);
	x_mid = (double)(x1 + x2) / 2;
	y_mid = (double)(y1 + y2) / 2;
	bisector_slope = -1 / slope;
	
	// compute the y-intercept
	y_intercept = y_mid - bisector_slope * x_mid;

	// print out the points
	printf("Point 1: (%d, %d)\n", x1, y1);
	printf("Point 2: (%d, %d)\n", x2, y2);

	// print the output of the  y = mx + b equation
	printf("y = %lfx + %lf", bisector_slope, y_intercept);

	return 0; // shows the program ran successfully
}
