/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 3 Task 3
* Date: September 11, 2024
* Description: This program computes the weighted average of 2 exams,
*			   2 labs, and 2 projects in a certain class.
*****************************************************************/

#include "WeightedAverage.h"

int main(void) {
	double exam1 = 0, exam2 = 0, lab1 = 0, lab2 = 0, project1 = 0, 
		   project2 = 0, exam_weight = 0, lab_weight = 0, project_weight = 0, weighted_average = 0;
	
	exam1 = get_score();
	exam2 = get_score();
	exam_weight = get_weight();

	lab1 = get_score();
	lab2 = get_score();
	lab_weight = get_weight();

	project1 = get_score();
	project2 = get_score();
	project_weight = get_weight();

	//weighted_average = compute_average;
					   
	return 0;
}