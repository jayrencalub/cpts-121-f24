/* comment block */

#include "LetterGrade.h"


// >= 90 --> A, <90 AND >= 80 --> B
char determine_letter_grade(int score) {
	char letter_grade = '\0';

	if (score >= 90) { // condition evaluates --> T
		// body is executed if the condition is true
		letter_grade = 'A';
	}
	else if (score >= 80) { // logical AND
		letter_grade = 'B';
	}
	else if (score >= 70) {
		letter_grade = 'C';
	}
	else if (score >= 60) {
		letter_grade = 'D';
	}
	else {
		letter_grade = 'F';
	}

	return letter_grade;
}