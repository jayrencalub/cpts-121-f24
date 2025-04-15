/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Date: August 30, 2024
* Description: This program calculates the user's GPA out of 3
*			   classes with user input.
*****************************************************************/

#include "ComputeGPA.h"

double get_grade_point(int class_num); // function declaration - function prototype
int get_credits(int class_num);
double compute_gpa(double w_gp, int sum_c);


int main(void) {
	double gp1 = 0.0, gp2 = 0.0, gp3 = 0.0, gpa = 0.0, weighted_gp = 0.0;
	int credits1 = 0, credits2 = 0, credits3 = 0, sum_credits = 0;

	//// 1. Prompt the user for grade point for class 1
	//printf("Enter the grade point for class 1: ");

	//// 2. Get the gp for class 1 from the user
	//scanf("%lf", &gp1);

	gp1 = get_grade_point(1);

	//// 3. Prompt the user for credits for class 1
	//printf("Enter the credits for class 1: ");

	//// 4. Get the credits for class 1
	//scanf("%d", &credits1);

	credits1 = get_credits(1);

	//// 5. Prompt the user for grade point for class 2
	//printf("Enter the grade point for class 2: ");

	//// 6. Get the gp for class 2 from the user
	//scanf("%lf", &gp2);

	gp2 = get_grade_point(2);

	//// 7. Prompt the user for credits for class 2
	//printf("Enter the credits for class 2: ");

	//// 8. Get the credits for class 2
	//scanf("%d", &credits2);

	credits2 = get_credits(2);

	//// 9. Prompt the user for grade point for class 3
	//printf("Enter the grade point for class 3: ");

	//// 10. Get the gp for class 3 from the user
	//scanf("%lf", &gp3);

	gp3 = get_grade_point(3);

	//// 11. Prompt the user for credits for class 3
	//printf("Enter the credits for class 3: ");

	//// 12. Get the credits for class 3
	//scanf("%d", &credits3);

	credits3 = get_credits(3);

	// 13. Sum up the credits for each class
	sum_credits = credits1 + credits2 + credits3;

	// 14. Compute the weighted grade point
	weighted_gp = (gp1 * credits1) + (gp2 * credits2) + (gp3 * credits3);

	return 0;
} // end of main