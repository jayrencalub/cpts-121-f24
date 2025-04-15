/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 3 Task 1
* Date: September 11, 2024
* Description: This program calculates the BMI of a user using the
*			   user's input.
* Relevant formula: BMI = ((weight in pounds) / (height in inches)^2 ) * 703
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// function definitions
double get_weight(void);
double get_height(void);
double convert_feet_to_inches(double height_in_feet);
double calculate_bmi(double weight_in_pounds, double height_in_feet);
void display_bmi(double bmi);

int main(void) {
	// variables
	double weight = 0.0, height_feet = 0.0, bmi = 0.0;

	weight = get_weight();
	height_feet = get_height();
	bmi = calculate_bmi(weight, height_feet);

	display_bmi(bmi);

	return 0;
}

double get_weight(void) {
	double weight = 0;

	printf("Please enter your weight in pounds: ");
	scanf("%lf", &weight);

	return weight;
}

double get_height(void) {
	double height_feet = 0;

	printf("Please enter your height in feet: ");
	scanf("%lf", &height_feet);

	return height_feet;
}

double convert_feet_to_inches(double height_in_feet) {
	return height_in_feet * 12;
}

double calculate_bmi(double weight_in_pounds, double height_in_feet) {
	double height_in_inches = convert_feet_to_inches(height_in_feet);
	return (weight_in_pounds / (height_in_inches * height_in_inches)) * 703;
}

void display_bmi(double bmi) {
	printf("Your BMI is: %.1lf", bmi);
}