/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 2 Task 2
* Date: September 4, 2024
* Description: This program computes the BMI of the user
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// variables
	double bmi = 0, height_foot = 0, height_inch = 0, weight = 0;
	char health = '\0';
	
	// prompt the user for their height and weight
	printf("Enter your height (in feet) and weight (in pounds): ");
	scanf("%lf%lf", &height_foot, &weight);

	// converts height from feet to inches
	height_inch = height_foot * 12;

	// calculates and prints out BMI
	bmi = ((weight) / (height_inch * height_inch)) * 703;
	printf("Your BMI is: %lf\n", bmi);

	// determines whether you are underweight, healthy, overweight, or obese
	if (bmi < 18) {
		// health = "underweight";
		printf("You are underweight");
	} 
	else if (bmi >= 18 & bmi < 25) {
		// health = "healthy";
		printf("You are healthy");
	}
	else if (bmi >= 25 & bmi < 30) {
		// health = "overweight";
		printf("You are overweight");
	}
	else {
		// health = "obese";
		printf("You are obese");
	}

	return 0;
}