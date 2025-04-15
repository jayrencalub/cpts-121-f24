/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 3 Task 3
* Date: September 11, 2024
* Description: This program computes the weighted average of 2 exams,
*			   2 labs, and 2 projects in a certain class.
*****************************************************************/

#include "WeightedAverage.h"

double get_score(void) {
	double score = 0;

	printf("Enter your score: ");
	scanf("%lf", &score);

	return score;
}

double get_weight(void) {
	double weight = 0;

	printf("Enter the weight: ");
	scanf("%lf", &weight);

	return weight;
}

double compute_weighted_grade(double grade1, double grade2, double weight) {
	return (grade1 + grade2) * weight;
}

double compute_average(double exam_score, double lab_score, double project_score) {
	return exam_score + lab_score + project_score;
}