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

int main(void) {
	char gender = '\0';
	int age = 0, exercise_level = 0;
	double weight = 0, height = 0, bmr = 0, calories = 0;
	FILE* input_stream = NULL, * output_stream;

	input_stream = fopen("data.txt", "r");
	fscanf(input_stream, "%c", &gender);
	fscanf(input_stream, "%d", &age);
	fscanf(input_stream, "%d", &exercise_level);
	fscanf(input_stream, "%lf", &weight);
	fscanf(input_stream, "%lf", &height);
	fclose(input_stream);

	printf("Activity Levels:\n1: Sedentary (little to no exercise)\n2: Low activity\n3: Moderate activity\n4: High activity\n5: Extra activity\n\n");
	printf("Your activity level: %d\n", exercise_level);

	bmr = calculate_bmr(gender, weight, height, age);
	calories = calculate_calories(exercise_level, bmr);

	display(bmr, calories);

	return 0;
}