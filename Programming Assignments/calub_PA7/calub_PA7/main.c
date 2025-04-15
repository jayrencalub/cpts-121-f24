/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 7
* Date: 11/22/2024
* Description: This program runs a game of poker
*****************************************************************/

#include "poker.h"

int main(void) {
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 }/*, replace[3] = { -1, -1, -1 }*/;
	int	player_hand_rank[7] = { 0 }, dealer_hand_rank[7] = { 0 }; // {has a 4 of a kind, ... , has a pair}
	int replace[3] = { 0 };

	int card_counter = 0, option = 0;

	Hand player_hand = { .h = {{0, 0}, // {face, suit}
							   {0, 0},
							   {0, 0}, 
							   {0, 0}, 
							   {0, 0}} };

	Hand dealer_hand = { .h = {{0, 0}} };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	do {
		option = 0;
		option = home_screen();
		menu_options(option);

		if (option == 2) { // game starts
			system("cls");

			replace[0] = 0;
			replace[1] = 0;
			replace[2] = 0;

			reset(deck, &player_hand, &dealer_hand);

			shuffle(deck);
			deal(deck, &player_hand, &dealer_hand);
			card_counter = 11;

			// player's turn
			printf("YOUR HAND\n");
			for (int i = 0; i < 5; i++) {
				printf("Card %d: %s of %s\n", i + 1, face[player_hand.h[i].face_index], suit[player_hand.h[i].suit_index]);
			}

			option = -1;
			while (option > 1 || option < 0) {
				printf("Would you like to redraw some cards? Enter 1 for yes, 0 for no: ");
				scanf("%d", &option);

				if (option > 1 || option < 0) {
					printf("Error in input, please try again\n");
				}
			}
			
			if (option == 1) {
				int num_cards = 0;

				while (num_cards < 1 || num_cards > 3) {
					printf("Enter the number of cards you want to redraw from 1 to 3: ");
					scanf("%d", &num_cards);
				}

				printf("Enter the number(s) of the card(s) you want to withdraw from 1 to 5 (Cards 1 and 2 would be 1 2): ");
				for (int i = 0; i < num_cards; i++) {
					scanf("%d", &replace[i]);
				}
				
				draw(deck, &player_hand, &card_counter, replace);
			}

			printf("\nYOUR HAND\n");
			for (int i = 0; i < 5; i++) {
				printf("Card %d: %s of %s\n", i + 1, face[player_hand.h[i].face_index], suit[player_hand.h[i].suit_index]);
			}

			get_hand_ranks(face, player_hand, player_hand_rank);

			// resetting the replace array
			replace[0] = 0;
			replace[1] = 0;
			replace[2] = 0;

			// automatic dealer simulation
			get_hand_ranks(face, dealer_hand, dealer_hand_rank);
			int highest_tier = 0;

			for (int i = 0; i < 7; i++) {
				if (dealer_hand_rank[i] == 1) {
					highest_tier = i;
					break;
				}
			}

			if (highest_tier == FOUR_KIND || highest_tier == FULL_HOUSE || highest_tier == FLUSH) {} // the dealer has a high rank, their hand stays the same
			else if (highest_tier == STRAIGHT || highest_tier == THREE_KIND) {
				replace[0] = rand() % 5 + 1;

				draw(deck, &dealer_hand, &card_counter, replace);
			}
			else if (highest_tier == TWO_PAIRS || highest_tier == PAIR) {
				replace[0] = rand() % 5 + 1;
				replace[1] = rand() % 5 + 1;

				draw(deck, &dealer_hand, &card_counter, replace);
			}
			else {
				replace[0] = 1;
				replace[1] = 2;
				replace[2] = 3;

				draw(deck, &dealer_hand, &card_counter, replace);
			}

			// compares the two hands
			printf("\nYOUR HAND\n");
			for (int i = 0; i < 5; i++) {
				printf("Card %d: %s of %s\n", i + 1, face[player_hand.h[i].face_index], suit[player_hand.h[i].suit_index]);
			}
			printf("\n");

			printf("DEALER'S HAND\n");
			for (int i = 0; i < 5; i++) {
				printf("Card %d: %s of %s\n", i + 1, face[dealer_hand.h[i].face_index], suit[dealer_hand.h[i].suit_index]);
			}

			get_hand_ranks(face, player_hand, player_hand_rank);
			get_hand_ranks(face, dealer_hand, dealer_hand_rank);

			printf("\n");
			determine_winner(player_hand_rank, dealer_hand_rank);
			
		}



	} while (option != 3); // close game

	return 0;
}