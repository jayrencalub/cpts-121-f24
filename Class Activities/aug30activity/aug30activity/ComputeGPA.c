/* comment block */

#include "ComputeGPA.h"

double get_grade_point(int class_num) {
	double gp = 0.0;

	// Prompt the user for grade point for a class
	printf("Enter the grade point for class %d: ", class_num);

	// Get the gp for the class 
	scanf("%lf", &gp);

	return gp;
}

int get_credits(int class_num) {
	int credits = 0;

	// Prompt the user for credits for a class
	printf("Enter the number of credits for class %d: ", class_num);

	// Get the credits for the class
	scanf("%d", &credits);

	return credits;
}

double compute_gpa(double w_gp, int sum_c) {
	double gp = 0.0;

	return gp;
}