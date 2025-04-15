/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 5
* Date: October 25, 2024
* Description: This program runs a game of 2-player Yahtzee
*****************************************************************/

#include "yahtzee.h"

/*************************************************************
* Function: menu_options()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function prints out text based on user input
* Input parameters: option: integer value of the user's option
* Returns:
* Preconditions: the argument must be an integer
* Postconditions: text must be printed out
*************************************************************/
void menu_options(int option) {
	switch (option) {
	case 1: print_game_rules(); // print the rules
		break;
	case 2: printf("\nStarting game...\n\n");
		break;
	case 3: printf("\nGoodbye!\n"); // exit game
		break;
	default: printf("\nError in input\n");
		break;
	}
}

/*************************************************************
* Function: home_screen()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function prints out a home screen with options
*			   that the user picks by typing a number
* Input parameters:
* Returns: option: integer of what the user picked
* Preconditions:
* Postconditions: an integer is being returned
*************************************************************/
int home_screen(void) {
	int option;
	
	printf("**********************************************************\n");
	printf("********************WELCOME TO YAHTZEE********************\n");
	printf("**********************************************************\n\n");
	printf("Type a number from 1 to 3 depending on what you want:\n1: Game Rules\n2: Start Game\n3: Exit Game\n\n");

	scanf("%d", &option);
	
	return option;
}

/*************************************************************
* Function: print_game_rules()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function prints the game rules of yahtzee
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/
void print_game_rules(void) {
	char a = '\0';

	printf("\n**************************RULES**************************\n");
	printf("There are 2 players in this game, and your objective is to get more points\n");
	printf("There are 14 rounds, each round consists of rolling 5 dice\n");
	printf("You can choose to reroll dice of your choice up to 3 times\n");
	printf("\n*************************SCORING*************************\n");
	printf("There are 13 different scoring combos, once you pick one, you can't pick it again\n");
	printf("Be careful, if you select a combo you didn't get, you will get 0 points\n");
	printf("Scoring is divided into upper and lower sections\n");
	printf("UPPER SECTION\n1-6s: choose any face value, and sum the total of the dice that matches the value\n");
	printf("If you get at least 63 upper section points, you get 35 bonus points\n");
	printf("LOWER SECTION\n3 of a kind: 3 matching dice, sum of all 5 dice\n4 of a kind: 4 matching dice, sum of all 5 dice\nFull house: one pair and 3 of a kind, 25 points\nSmall straight: sequence of 4 dice, 30 points\nLarge straight: sequence of 5 dice, 40 points\nYahtzee: 5 of a kind, 50 points\nChance: any sequence of dice, sum of all 5 dice\n");
	printf("Whoever has more points is the winner!\n");
	printf("Enter any key to continue: ");

	scanf(" %c", &a);
}

/*************************************************************
* Function: roll_dice()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function generates 5 random numbers and stores them
*			   into an array, also increments roll count
* Input parameters: rolls[]: int array that stores the dice rolls
*					reroll[]: int array that indicates whether the current dice should be rolled
*					*num_rolls: int pointer that stores the number of rolls currently
* Returns: rolls[], num_rolls indirectly
* Preconditions: arguments must be int arrays or int pointers
* Postconditions: int array and int pointer is returned
*************************************************************/
void roll_dice(int rolls[], int reroll[], int* num_rolls) {
	char a = '\0';

	printf("Type and enter any key to roll dice: ");
	scanf(" %c", &a);
	printf("\n");
	
	for (int i = 0; i < NUM_DICE; i++) {
		if (reroll[i] == 1) { // player wants to reroll, elements should be defaulted to 1 on first roll
			rolls[i] = rand() % 6 + 1;
		}
	}

	(*num_rolls)++;
}

/*************************************************************
* Function: print_rolls()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function prints the value of each die
* Input parameters: rolls[]: int array that stores the dice rolls
* Returns:
* Preconditions: argument must be an int array
* Postconditions:
*************************************************************/
void print_rolls(int rolls[]) {
	printf("Dice values: ");

	for (int i = 0; i < NUM_DICE; i++) {
		printf("%d ", rolls[i]);
	}

	printf("\n");
}

/*************************************************************
* Function: get_freq()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function takes the array of dice rolls and
*			   modifies a frequency table based on the values
* Input parameters: dice[]: int array that stores the dice rolls
*					freq[]: int array that stores the frequency of each dice value
* Returns: freq[]
* Preconditions: arguments must be 2 int arrays
* Postconditions:
*************************************************************/
int get_freq(int dice[], int freq[]) {
	int count = 0;

	// 1st loop to iterate through frequency array, 2nd loop to iterate through dice array
	for (int i = 1; i < FREQUENCY_SIZE; i++) { // freq: [0 1 2 3 4 5 6]
		count = 0;
		for (int j = 0; j < NUM_DICE; j++) {
			if (i == dice[j]) {
				count++;
			}
		}
		freq[i] = count;
	}
	return freq;
}

/*************************************************************
* Function: calculate_scores
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function modifies an array of possible scores
*			   using a frequency table
* Input parameters: rolls[]: int array that stores the dice rolls
*					freq[]: int array that stores the frequency of each dice value
*					options[]: int array that stores the scores of each combination
* Returns: options[]
* Preconditions: all 3 arguments must be int arrays
* Postconditions:
*************************************************************/
int* calculate_scores(int rolls[], int freq[], int options[]) {
	// combo score variables
	int three_kind = 0, four_kind = 0, full_house = 0, s_straight = 0, l_straight = 0, yahtzee = 0, chance = 0;

	// other variables
	int pair = 0, three_of_a_kind = 0, count = 0;

	/* options = {null, 1s, 2s, 3s, 4s, 5s, 6s, 3 kind, 4 kind, full house, small straight, large straight, yahtzee, chance} */

	// upper scores
	options[1] = freq[1] * 1;
	options[2] = freq[2] * 2;
	options[3] = freq[3] * 3;
	options[4] = freq[4] * 4;
	options[5] = freq[5] * 5;
	options[6] = freq[6] * 6;

	// three or four of a kind
	for (int i = 1; i < FREQUENCY_SIZE; i++) {
		if (freq[i] == 3) {
			three_kind = sum_dice(rolls);
			break;
		}
	}
	for (int i = 1; i < FREQUENCY_SIZE; i++) {
		if (freq[i] == 4) {
			four_kind = sum_dice(rolls);
			break;
		}
	}
	options[7] = three_kind;
	options[8] = four_kind;

	// full house
	for (int i = 1; i < FREQUENCY_SIZE; i++) {
		if (freq[i] == 2) {
			pair = 1;
		}
		if (freq[i] == 3) {
			three_of_a_kind = 1;
		}
	}
	if (pair == 1 && three_of_a_kind == 1) { // if both are present
		full_house = FULL_HOUSE;
	}
	options[9] = full_house;

	// small or large straight 1 2 6 4 5 freq: 0 1 1 0 1 1 0
	for (int i = 1; i < FREQUENCY_SIZE; i++) {
		if (freq[i] > 0) {
			count++;
		}
		else {
			count = 0;
		}
	}
	if (count == 5) {
		s_straight = S_STRAIGHT;
		l_straight = L_STRAIGHT;
	}
	else if (count == 4) {
		s_straight = S_STRAIGHT;
	}
	options[10] = s_straight;
	options[11] = l_straight;

	// yahtzee
	for (int i = 1; i < FREQUENCY_SIZE; i++) {
		if (freq[i] == 5) {
			yahtzee = YAHTZEE;
			break;
		}
	}
	options[12] = yahtzee;

	// chance
	chance = sum_dice(rolls);
	options[13] = chance;

	return options;
}

/*************************************************************
* Function: display_scores()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function prints a list of each combination and 
*			   the scores that the player currently has
* Input parameters: options[]: int array that stores the scores of each combination
*					scores[]: int array that scores the player's scores
* Returns:
* Preconditions: both arguments must be int arrays
* Postconditions:
*************************************************************/
void display_scores(int options[], int scores[]) {
	printf("\n1)  Sum of 1s\n2)  Sum of 2s\n3)  Sum of 3s\n4)  Sum of 4s\n5)  Sum of 5s\n6)  Sum of 6s\n7)  3 of a kind\n8)  4 of a kind\n9)  Full house\n10) Small straight\n11) Large straight\n12) Yahtzee\n13) Chance\n\n");
	
	printf("Options: ");
	for (int i = 1; i < NUM_COMBOS + 1; i++) {
		printf("%d ", options[i]);
	}

	printf("\n\nYour scores (-1 means you haven't selected the combo yet)\n");
	for (int i = 0; i < NUM_COMBOS; i++) {
		printf("%d ", scores[i]);
	}
}

/*************************************************************
* Function: select_combo()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function prompts the player to select the combination
*			   they want to get points for
* Input parameters: options[]: int array that stores the scores of each combination
*					scores[]: int array that scores the player's scores
* Returns: options[], scores[]
* Preconditions: both arguments must be int arrays
* Postconditions:
*************************************************************/
int* select_combo(int options[], int scores[]) {
	int choice = 0, has_selected = 0;

	while (has_selected == 0) { // runs until user selects a valid option
		printf("\n\nChoose your combo (you cannot choose the same combo twice): ");
		scanf("%d", &choice);

		if (choice < 1 || choice > 13) {
			printf("Invalid option, please try again");
		}
		else if (scores[choice - 1] != -1) {
			printf("You have already selected this combo, please try again");
		}
		else {
			scores[choice - 1] = options[choice];
			has_selected++;
		}
	}
	
	return scores;
}

/*************************************************************
* Function: sum_dice()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function takes the sum of the 5 dice from the array
* Input parameters: rolls[]: int array that stores the dice rolls
* Returns: sum: the sum of the dice
* Preconditions: parameter must be int array
* Postconditions:
*************************************************************/
int sum_dice(int rolls[]) {
	int sum = 0;

	for (int i = 0; i < NUM_DICE; i++) {
		sum = sum + rolls[i];
	}

	return sum;
}

/*************************************************************
* Function: reset()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function resets the reroll checkers and number of rolls
* Input parameters: reroll[]: the reroll checker used before rolling the dice
*					*num_rolls: the number of rolls the player has taken
*					*reroll_status: int that checks if player is rerolling
* Returns: reroll[], num_rolls, reroll_status
* Preconditions:
* Postconditions:
*************************************************************/
int* reset(int reroll[], int *num_rolls, int* reroll_status) {
	for (int i = 0; i < NUM_DICE; i++) {
		reroll[i] = 1;
	}

	*num_rolls = 0;
	*reroll_status = 1;
}

/*************************************************************
* Function: ask_to_reroll()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function asks the reader if they want to reroll
* Input parameters: reroll[]: the reroll checker used before rolling the dice
*					num_rolls: the number of rolls
*					*reroll_status: int that checks if player is rerolling
* Returns: reroll[], reroll_status
* Preconditions:
* Postconditions:
*************************************************************/
int* ask_to_reroll(int reroll[], int num_rolls, int *reroll_status) {
	int choice = 0, status = 0, current_die = 0;

	printf("\n\nNumber of rolls: %d", num_rolls);

	while (status == 0 && num_rolls < 3) {
		printf("\nDo you want to reroll? Enter 1 for yes, 0 for no: ");
		scanf("%d", &choice);

		if (choice == 1) {
			for (current_die = 0; current_die < NUM_DICE; current_die++) {
				printf("Reroll die %d? Enter 1 for yes, 0 for no: ", current_die + 1); // this is to display current_die as 1 instead of 0 and so on
				scanf("%d", &choice);

				reroll[current_die] = choice;
			}

			*reroll_status = 1;
			status = 1;
		}
		else if (choice == 0) {
			printf("Moving on...\n");
			*reroll_status = 0;

			status = 1;
		}
		else {
			printf("Invalid response, please try again\n");
		}
	}
}

/*************************************************************
* Function: calc_upper_score
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function calculates the upper score of the player
* Input parameters: p1_scores[]: int array that scores player 1's scores
*					p2_scores[]: int array that scores player 2's scores
*					*p1_upper: player 1's upper score
*					*p2_upper: player 2's upper score
* Returns: p1_upper, p2_upper
* Preconditions: 
* Postconditions:
*************************************************************/
void calc_upper_score(int p1_scores[], int p2_scores[], int* p1_upper, int* p2_upper) {
	for (int i = 0; i < UPPER_LOWER_CUTOFF; i++) {
		*p1_upper = *p1_upper + p1_scores[i];
	}
	for (int i = 0; i < UPPER_LOWER_CUTOFF; i++) {
		*p2_upper = *p2_upper + p2_scores[i];
	}

	printf("\n\nPlayer 1's upper score: %d\n", *p1_upper);
	printf("Player 2's upper score: %d\n\n", *p2_upper);
}

/*************************************************************
* Function: has_bonus()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function determines whether each player gets the bonus
* Input parameters: p1_upper: player 1's upper score
*					p2_upper: player 2's upper score
*					p1_bonus: whether or not player 1 gets the bonus
*					p2_bonus: whether or not player 2 gets the bonus
* Returns: p1_bonus, p2_bonus
* Preconditions:
* Postconditions:
*************************************************************/
void has_bonus(int p1_upper, int p2_upper, int* p1_bonus, int* p2_bonus) {
	*p1_bonus = 0, * p2_bonus = 0;

	if (p1_upper >= BONUS_THRESHOLD) {
		*p1_bonus = 1; // gets the bonus
	}
	if (p2_upper >= BONUS_THRESHOLD) {
		*p2_bonus = 1;
	}
}

/*************************************************************
* Function: calc_score()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function calculates the total score of each player
* Input parameters: p1_scores[]: int array that scores player 1's scores
*					p2_scores[]: int array that scores player 2's scores
*					p1_bonus: whether or not player 1 gets the bonus
*					p2_bonus: whether or not player 2 gets the bonus
*					*p1_score: player 1's total score
*					*p2_score: player 2's total score
* Returns:p1_score, p2_score
* Preconditions:
* Postconditions:
*************************************************************/
void calc_score(int p1_scores[], int p2_scores[], int p1_bonus, int p2_bonus, int* p1_score, int* p2_score) {
	// player 1
	for (int i = 0; i < NUM_COMBOS; i++) {
		*p1_score = *p1_score + p1_scores[i];
	}
	if (p1_bonus == 1) {
		(*p1_score) += BONUS_SCORE;
	}

	// player 2
	for (int i = 0; i < NUM_COMBOS; i++) {
		*p2_score = *p2_score + p2_scores[i];
	}
	if (p2_bonus == 1) {
		(*p2_score) += BONUS_SCORE;
	}
}

/*************************************************************
* Function: determine_winner()
* Date Created: 10/25/2024
* Date Last Modified:
* Description: This function determines the winner of the game
* Input parameters: p1_score: player 1's total score
*					p2_score: player 2's total score
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/
void determine_winner(int p1_score, int p2_score) {
	printf("\nPlayer 1 score: %d\nPlayer 2 score: %d\n\n", p1_score, p2_score);

	if (p1_score > p2_score) {
		printf("Player 1 wins!\n");
	}
	else if (p1_score < p2_score) {
		printf("Player 2 wins!\n");
	}
	else {
		printf("It's a draw!\n");
	}
}