/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Class Activity
* Date: September 11, 2024
* Description: This program takes in a percent grade and converts
*			   it into a letter grade.
*****************************************************************/

#include "LetterGrade.h"

int main(void) {
	
	/* communiication channel stream, data flows from the 
	text file into the program memory, EOF = end of file */
	FILE* input_stream = NULL, *output_stream; 
	int score1 = 0, score2 = 0, score3 = 0;
	char letter_grade1 = '\0', letter_grade2 = '\0', letter_grade3 = '\0';

	// fopen(file name, mode): fopen reqires the file name to open ("scores.txt") and the 
	// mode in which to open the file "r" means read the file, "w" means write to the file.
	input_stream = fopen("scores.txt", "r");
	
	// assuming the file is opened successfully
	fscanf(input_stream, "%d", &score1);
	fscanf(input_stream, "%d", &score2);
	fscanf(input_stream, "%d", &score3);

	fclose(input_stream);

	printf("score1: %d\nscore2: %d\nscore3: %d\n", score1, score2, score3);
	
	letter_grade1 = determine_letter_grade(score1);
	letter_grade2 = determine_letter_grade(score2);
	letter_grade3 = determine_letter_grade(score3);

	output_stream = fopen("results.txt", "w");

	fprintf(output_stream, "score: %d, grade: %c\n", score1, letter_grade1);
	fprintf(output_stream, "score: %d, grade: %c\n", score2, letter_grade2);
	fprintf(output_stream, "score: %d, grade: %c\n", score3, letter_grade3);

	fclose(output_stream);

	return 0;
}
