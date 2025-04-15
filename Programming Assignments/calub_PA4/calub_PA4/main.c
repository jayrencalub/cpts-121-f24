/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 4
* Date: October 11, 2024
* Description: This program runs a game of craps that the user
*			   can play.
*****************************************************************/

#include "craps.h"

int main(void) {
	int input = 0, option = 0, dice1 = 0, dice2 = 0, sum_dice = 0, num_rolls = 0, point = 0,
		add_or_subtract = 0, player_status = -2 /*set to -2 because possible options after first roll is -1, 0, and 1*/;
	double initial_balance = 0, current_balance = 0, wager = 0;

	srand((unsigned int)time(NULL));

	do {
		// gets bank balance from user ONCE 
		if (input == 0) {
			// asks the user for initial input
			initial_balance = get_bank_balance();
			current_balance = initial_balance;

			input++;
		}

		option = 0;
		option = home_screen();
		menu_options(option);

		printf("\nYour balance: %.2lf\n", current_balance);

		if (option == 2) { // game starts

			// asks player for a wager
			wager = get_wager_amount();
			int wager_status = check_wager_amount(wager, current_balance);
			// makes sure wager isn't over bank balance
			while (wager_status == 0) {
				printf("\nInvalid wager, please try again\n");
				wager = get_wager_amount();
				wager_status = check_wager_amount(wager, initial_balance);
			}
			// initial roll
			int roll = 0, num_rolls = 0;

			chatter_messages(num_rolls, player_status, initial_balance, current_balance);
			printf("\nEnter any number to roll dice: ");
			scanf("%d", &roll);

			dice1 = roll_die();
			dice2 = roll_die();
			sum_dice = calculate_sum_dice(dice1, dice2);
			printf("\nRoll value: %d\n", sum_dice);

			player_status = is_win_loss_or_point(sum_dice);
			num_rolls++;

			// displays messages based on the player status (win, lose, point)
			if (player_status == -1) { // assign point value
				point = sum_dice;
				printf("\nYour point value: %d\n", point);

				// rolls after the first
				do {
					chatter_messages(num_rolls, player_status, initial_balance, current_balance);
					printf("Enter any number to roll dice: ");
					scanf("%d", &roll);

					dice1 = roll_die();
					dice2 = roll_die();
					sum_dice = calculate_sum_dice(dice1, dice2);
					printf("\nRoll value: %d\n", sum_dice);

					player_status = is_point_loss_or_neither(sum_dice, point);
					num_rolls++;
				} while (player_status == -1);
			}
			if (player_status == 0) { // lose
				add_or_subtract = 0;

				printf("\nHaha you lost, better luck next time\n");
				// player loses their bet
				current_balance = adjust_bank_balance(current_balance, wager, add_or_subtract);
				printf("Your new balance: %.2lf\n", current_balance);
			}
			else { // win
				add_or_subtract = 1;

				printf("\nCongrats! You won!\n");
				// player wins double of their bet
				current_balance = adjust_bank_balance(current_balance, wager, add_or_subtract);
				printf("Your new balance: %.2lf\n", current_balance);
			}

		}


	} while (option != 3); // close game

	return 0;
}