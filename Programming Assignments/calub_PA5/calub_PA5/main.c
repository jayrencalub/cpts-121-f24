/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 5
* Date: October 25, 2024
* Description: This program runs a game of 2-player Yahtzee
*****************************************************************/

#include "yahtzee.h"

int main(void) {
	// roll: [3 5 2 4 6], freq: [0 0 1 1 1 1 1]
	int dice[NUM_DICE] = { 0 }, freq[FREQUENCY_SIZE] = { 0 }, options[NUM_COMBOS + 1] = { 0 }, reroll[NUM_DICE] = { 1,1,1,1,1 },
		p1_scores[NUM_COMBOS] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }, p2_scores[NUM_COMBOS] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
		p1_upper = 0, p2_upper = 0, p1_bonus = 0, p2_bonus = 0, p1_total = 0, p2_total = 0, num_rolls = 0, round_num = 1, option = 0, reroll_status = 1;

	srand((unsigned int)time(NULL));

	do {
		option = 0;
		option = home_screen();
		menu_options(option);

		system("cls"); // clear terminal

		if (option == 2) { // game starts

			while (round_num < 14) { // 13 rounds
				printf("\n*******ROUND %d*******\n\n", round_num);

				// player 1's turn
				printf("Player 1\n");
				
				while (num_rolls < 3 && reroll_status == 1) {
					roll_dice(dice, reroll, &num_rolls);
					print_rolls(dice);
					get_freq(dice, freq);
					calculate_scores(dice, freq, options);
					display_scores(options, p1_scores);
					ask_to_reroll(reroll, num_rolls, &reroll_status);
				}

				select_combo(options, p1_scores);
				display_scores(options, p1_scores);

				reset(reroll, &num_rolls, &reroll_status);

				// player 2's turn
				printf("\n\nPlayer 2\n");

				while (num_rolls < 3 && reroll_status == 1) {
					roll_dice(dice, reroll, &num_rolls);
					print_rolls(dice);
					get_freq(dice, freq);
					calculate_scores(dice, freq, options);
					display_scores(options, p2_scores);
					ask_to_reroll(reroll, num_rolls, &reroll_status);
				}

				select_combo(options, p2_scores);
				display_scores(options, p2_scores);

				reset(reroll, &num_rolls, &reroll_status);

				round_num++;
			}

			// calculate upper score for each player
			calc_upper_score(p1_scores, p2_scores, &p1_upper, &p2_upper);

			// determine if each player gets the bonus
			has_bonus(p1_upper, p2_upper, &p1_bonus, &p2_bonus);

			// calculate each player's total score
			calc_score(p1_scores, p2_scores, p1_bonus, p2_bonus, &p1_total, &p2_total);

			// determines the winner
			determine_winner(p1_total, p2_total);
		}



	} while (option != 3); // close game

	printf("\nGoodbye!");

	return 0;
}