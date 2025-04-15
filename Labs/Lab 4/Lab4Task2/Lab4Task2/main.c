/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab 4 Task 2
* Date: September 18, 2024
* Description: This program calculates an MLB player's salary bonus
*			   at the end of the season
*****************************************************************/

#include "salary.h"

int main(void) {
	int total = 0;
	char answer = '\0';

	printf("Answer y for yes, or n for no to the following questions: \n");

	printf("Were you in the All-Star Game? ");
	scanf(" %c", &answer);
	total = calc_bonus(answer, total, 25000);

	printf("Were you the season MVP? ");
	scanf(" %c", &answer);
	total = calc_bonus(answer, total, 75000);

	printf("Were you the World Series MVP? ");
	scanf(" %c", &answer);
	total = calc_bonus(answer, total, 100000);

	printf("Did you win the Gold Glove? ");
	scanf(" %c", &answer);
	total = calc_bonus(answer, total, 50000);

	printf("Did you win the Silver Slugger? ");
	scanf(" %c", &answer);
	total = calc_bonus(answer, total, 35000);

	printf("Were you the home run champ? ");
	scanf(" %c", &answer);
	total = calc_bonus(answer, total, 25000);

	printf("Were you the batting average champ? ");
	scanf(" %c", &answer);
	total = calc_bonus(answer, total, 25000);

	printf("Your total bonus: $%d", total);

	return 0;
}
