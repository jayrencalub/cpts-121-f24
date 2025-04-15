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

#define _CRT_SECURE_NO_WARNINGS
#define G 32.17

#include <stdio.h>
#include <math.h>

double get_theta(void); // in radians
double get_distance(void); // in feet
double get_velocity(void); // ft/sec

double calculate_time(double, double, double);
double calculate_height(double, double, double);

void print_time(double);
void print_height(double);