/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 4 Task 1
* Date: September 18, 2024
* Description: This program calculates the amount of calories an
*			   individual needs to intake based on their gender,
*			   age, weight, height, and exercise level
*****************************************************************/

#include "CalorieCalculator.h"

double calculate_bmr(char gender, double weight, double height, double age){
	if (gender == 'W') {
		return 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
	}
	else {
		return 66 + (6.23 * weight) + (12.7 * height) - (6.8 * age);
	}
}

double calculate_calories(int exercise_level, double BMR){
	double constant = 0;

	if (exercise_level == 1) {
		constant = 1.2;
	}
	if (exercise_level == 2) {
		constant = 1.375;
	}
	if (exercise_level == 3) {
		constant = 1.55;
	}
	if (exercise_level == 4) {
		constant = 1.725;
	}
	if (exercise_level == 5) {
		constant = 1.9;
	}

	return BMR * constant;
}

void display(double bmr, double calories) {
	printf("BMR: %.2lf\n", bmr);
	printf("Your required calorie intake: %.2lf", calories);
}