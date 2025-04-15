/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 4 Task 1
* Date: September 18, 2024
* Description: This program calculates the amount of calories an
*			   individual needs to intake based on their gender,
*			   age, weight, height, and exercise level
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double calculate_bmr(char gender, double weight, double height, double age);
double calculate_calories(int exercise_level, double BMR);
void display(double bmr, double calories);