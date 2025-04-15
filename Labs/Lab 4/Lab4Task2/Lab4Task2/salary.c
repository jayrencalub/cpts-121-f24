/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 4 Task 2
* Date: September 18, 2024
* Description: This program calculates an MLB player's salary bonus
*			   at the end of the season
*****************************************************************/

#include "salary.h"

int calc_bonus(char answer, int total, int bonus) {
	int total_salary = total;

	if (answer == 'y') {
		total_salary = total + bonus;
	}

	return total_salary;
}