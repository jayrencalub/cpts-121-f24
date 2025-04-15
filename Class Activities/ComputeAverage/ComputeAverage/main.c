/*
	Name: Jayren
	Date: 8/26/2024

	Description: This program prompts the user for 3 exam scores, computes the average of the 3 exam
				 scores, and displays the average to the screen.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // printf(), scanf()
#define NUM_SCORES 3 // no semicolon here

int main(void) // starting point of execution of all C programs
{
	int score1 = 0, score2 = 0, score3 = 0, sum_scores = 0; //avg_score = 0;
	// int score2 = 0;
	// float average = 0.0
	double avg_score = 0.0;
	
	// 1. Prompt the user for exam score 1
	printf("Please enter exam score 1: ");

	// 2. Get the score for exam 1 from the user
	scanf("%d", &score1); // &: address of operator
	
	// 3. Prompt the user for exam score 2
	printf("Please enter exam score 2: ");

	// 4. Get the score for exam 2 from the user
	scanf("%d", &score2);

	// 5. Prompt the user for exam score 3
	printf("Pleaes enter exam score 3: ");

	// 6. Get the score for exam 3 from the user
	scanf("%d", &score3);

	// 7. Sum up the scores
	sum_scores = score1 + score2 + score3;

	// 8. Compute the average
	avg_score = (double) sum_scores / NUM_SCORES; // integer division

	// 9. Display the average to the screen
	// printf("Exam average: %d\n", avg_score);
	printf("Exam average: %lf\n", avg_score);
	printf("%d", -19 - 3 / 7 %2 +1);
	return 0; //indicate the program ran successfully
}