/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Blackjack
* Date: October 16, 2024
* Description: This program runs a game of blackjack that the user
*			   can play.
*****************************************************************/

#include "blackjack.h"

int main(void) {
	int input = 0, option = 0, card1 = 0, card2 = 0, player_sum = 0, dealer_sum = 0, add_or_sub = 0,
		hit_or_stand = 0, wager_status = 0, player_status = -1 /*player has not won or lost yet*/;
	double initial_balance = 0, current_balance = 0, wager = 0;

	srand((unsigned int) time(NULL));

	do {
		// gets bank balance from user ONCE 
		if (input == 0) {
			// asks the user for initial input
			initial_balance = get_bank_balance();
			current_balance = initial_balance;

			input++;
		}

		option = 0;
		option = display_menu();
		menu_options(option);

		printf("\nYour balance: %.2lf\n", current_balance);

		if (option == 2 && current_balance > 0) { // game starts
			wager_status = 0;
			
			// asks player for a wager
			wager = get_wager_amount();
			wager_status = check_wager_amount(wager, current_balance);

			while (wager_status == 0 || wager < 0) {
				printf("\nInvalid wager, please try again\n");
				wager = get_wager_amount();
				wager_status = check_wager_amount(wager, initial_balance);
			}

			// resetting values
			card1 = 0, card2 = 0, player_sum = 0, dealer_sum = 0;

			// player's first draw
			card1 = draw_card();
			card2 = draw_card();

			if (card1 == ACE) {
				card1 = choose_ace_score();
			}
			if (card2 == ACE) {
				card2 = choose_ace_score();
			}

			player_sum = sum_cards(card1, card2);
			print_card(card1);
			print_card(card2);
			printf("Player's ");
			display_sum(player_sum);

			// dealer's first draw
			card1 = draw_card();
			card2 = draw_card();

			dealer_sum = sum_cards(card1, card2);
			print_card(card1);
			print_card(card2);
			printf("Dealer's ");
			display_sum(dealer_sum);

			// dealer draws again
			card1 = draw_card();

			dealer_sum = sum_cards(dealer_sum, card1);

			// checking if player won and if they want to hit or stand
			player_status = check_sum(player_sum);
			hit_or_stand = hit_stand();

			if (hit_or_stand == 0) {
				player_status = compare_scores(player_sum, dealer_sum);
			}

			do {
				card1 = draw_card();

				if (card1 == ACE) {
					card1 = choose_ace_score();
				}

				// player's cards
				player_sum = sum_cards(player_sum, card1);
				print_card(card1);
				display_sum(player_sum);
				player_status = check_sum(player_sum);

				if (player_status == -1) {
					hit_or_stand = hit_stand();
				}
			} while (player_status == -1 && hit_or_stand == 1);

			if (hit_or_stand == 0) {
				player_status = compare_scores(player_sum, dealer_sum);
			}

			if (player_status == 0) { // lose
				add_or_sub = 0;
				// player loses their bet
				current_balance = adjust_bank_balance(current_balance, wager, add_or_sub);
				printf("Your new balance: %.2lf\n", current_balance);
			}
			else { // WIN
				add_or_sub = 1;
				// player wins double of their bet
				current_balance = adjust_bank_balance(current_balance, wager, add_or_sub);
				printf("Your new balance: %.2lf\n", current_balance);
			}
		}

	} while (option != 3 && current_balance > 0);
	
	return 0;
}