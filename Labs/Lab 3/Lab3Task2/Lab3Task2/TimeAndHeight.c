/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 3 Task 2
* Date: September 11, 2024
* Description: This program computes the duration of a projectile's
*			   flight and its height above the ground when it reaches
*			   the target.
* Relevant Formulas: time = (distance) / (velocity * cos(theta))
*					 height = velocity * sin(theta) * time - ((G * time^2) / 2)
*****************************************************************/

#include "TimeAndHeight.h"

double get_theta(void) {
	double theta = 0.0;

	printf("Enter the value of theta (in radians): ");
	scanf("%lf", &theta);
	
	return theta;
}

double get_distance(void) {
	double distance = 0.0;

	printf("Enter the distance (in feet) to target: ");
	scanf("%lf", &distance);

	return distance;
}

double get_velocity(void) {
	double velocity = 0.0;

	printf("Enter the velocity (in ft/sec): ");
	scanf("%lf", &velocity);

	return velocity;
}

double calculate_time(double distance, double velocity, double theta) {
	return distance / (velocity * cos(theta));
}

double calculate_height(double time, double velocity, double theta) {
	return velocity * sin(theta) * time - ((G * pow(time, 2)) / 2);
}

void print_time(double time) {
	printf("Time: %lf", time);
}

void print_height(double height) {
	printf("\nHeight: %lf", height);
}