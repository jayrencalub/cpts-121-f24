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

int main(void) {

	// variables
	double theta = 0.0, distance = 0.0, velocity = 0.0, time = 0.0, height = 0.0;

	theta = get_theta();
	distance = get_distance();
	velocity = get_velocity();
	time = calculate_time(distance, velocity, theta);
	height = calculate_height(time, velocity, theta);

	print_time(time);
	print_height(height);

	return 0;
}
