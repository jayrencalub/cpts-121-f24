/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 3 Task 3
* Date: September 11, 2024
* Description: This program computes the weighted average of 2 exams,
*			   2 labs, and 2 projects in a certain class.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double get_score(void);
double get_weight(void);
double compute_weighted_grade(double, double, double);
double compute_average(double, double, double);