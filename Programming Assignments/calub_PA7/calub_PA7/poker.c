/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 7
* Date: 11/22/2024
* Description: This program runs a game of poker
*****************************************************************/

#include "poker.h"

// prints a phrase depending on what the user chooses
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

// welcomes the user, asks for an input based on what the user wants
int home_screen(void) {
	int option;

	printf("**********************************************************\n");
	printf("*********************WELCOME TO POKER*********************\n");
	printf("**********************************************************\n\n");
	printf("Type a number from 1 to 3 depending on what you want:\n1: Game Rules\n2: Start Game\n3: Exit Game\n\n");

	scanf("%d", &option);

	return option;
}

// prints the game rules
void print_game_rules(void) {
	char a = '\0';

	printf("\n**************************RULES**************************\n");
	printf("You are against a computer/dealer in 5-draw poker\n");
	printf("Each of you are given 5 cards in your hand, and you want to have a better hand than the dealer\n");
	printf("The ranking of each hands are as follows, from best to worst:\n");
	printf("Four of a kind: 4 cards of the same face\nFull house: 3 of a kind and a pair\nFlush: all cards are the same suit\nStraight: cards are in consecutive order\nThree of a kind: 3 cards of the same face\nTwo pairs: two different pairs of the same face\nPair: one pair of cards of the same face");
	printf("You may replace up to 3 cards in your hand if you want to\n");
	printf("The computer will do the same thing automatically\n");
	printf("Once each hand is set, they will be compared and the winner will be determined\n\n");

	printf("Enter any key to continue: ");
	scanf(" %c", &a);
}

/* shuffle cards in deck */
void shuffle(int wDeck[][13]) {
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++) {
		/* choose new random location until unoccupied slot found */
		do {
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], Hand* p_hand, Hand* d_hand) {
	int row = 0;    /* row number */
	int column = 0; /* column number */
	int card = 0; /* card counter */
	int p_index = 0, d_index = 0;

	for (card = 1; card <= 10; card++) {
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++) {
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++) {
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card) {
					//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					if (card % 2 == 1) {
						(*p_hand).h[p_index].face_index = column;
						(*p_hand).h[p_index].suit_index = row;
						p_index++;
					}
					else {
						(*d_hand).h[d_index].face_index = column;
						(*d_hand).h[d_index].suit_index = row;
						d_index++;
					}
				}
			}
		}
	}
}

// replaces cards in the hand
void draw(const int wDeck[][13], Hand* hand, int* card_counter, int cards_to_replace[]) {
	int row = 0, column = 0, num_cards = 0, replace_index = 0, card_found = 0;

	for (int i = 0; i < 3; i++) {
		if (cards_to_replace[i] != 0) { // add a check for negatives and > 5 before this function gets called
			num_cards++;
		}
	}

	for (int i = 0; i < num_cards; i++) {
		replace_index = cards_to_replace[i];

		for (row = 0; row < 4; row++) {
			for (column = 0; column < 13; column++) {
				if (wDeck[row][column] == *card_counter) {
					(*hand).h[replace_index - 1].face_index = column;
					(*hand).h[replace_index - 1].suit_index = row;

					(*card_counter)++;
					break;
				}
			}
			if (wDeck[row][column] == *card_counter - 1) {
				break;
			}
		}
	}
}

// hand checker functions are ranked from best to worst already
int has_four_of_a_kind(const char* face[], Hand hand) {
	int result = 0, index1 = 0, index2 = 0, count = 0;

	for (int i = 0; i < 4; i++) {
		index1 = hand.h[i].face_index;

		for (int j = i + 1; j < 5; j++) {
			index2 = hand.h[j].face_index;

			if (strcmp(face[index1], face[index2]) == 0) {
				count++;

				if (count == 4) {
					result = 1;
					break;
				}
			}
		}
	}

	return result;
}

int has_full_house(const char* face[], Hand hand) {
	int result = 0, index = 0, two_kind = 0, three_kind = 0, freq_table[13] = { 0 };

	for (int i = 0; i < 5; i++) {
	index = hand.h[i].face_index;
		freq_table[index]++;
	}

	for (int i = 0; i < 13; i++) {
		if (freq_table[i] == 3) {
			three_kind = 1;
		}
		else if (freq_table[i] == 2) {
			two_kind = 1;
		}
	}

	if (two_kind == 1 && three_kind == 1) {
		result = 1;
	}

	return result;
}

int has_flush(const char* suit[], Hand hand) {
	int result = 1;
	char first_suit[10];

	strcpy(first_suit, suit[hand.h[0].suit_index]);

	for (int i = 1; i < 5; i++) {
		if (strcmp(first_suit, suit[hand.h[i].suit_index]) != 0) {
			result = 0;
			break;
		}
	}

	return result;
}

int has_straight(Hand hand) {
	int result = 1, temp = 0, indices[5];

	for (int i = 0; i < 5; i++) {
		indices[i] = hand.h[i].face_index;
	}

	for (int i = 0; i < 5 - 1; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (indices[i] > indices[j]) {
				temp = indices[i];
				indices[i] = indices[j];
				indices[j] = temp;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (indices[i + 1] != indices[i] + 1) {
			result = 0;
			break;
		}
	}

	return result;
}

int has_three_of_a_kind(const char* face[], Hand hand) {
	int result = 0, index1 = 0, index2 = 0, count = 0;

	for (int i = 0; i < 4; i++) {
		index1 = hand.h[i].face_index;

		for (int j = i + 1; j < 5; j++) {
			index2 = hand.h[j].face_index;

			if (strcmp(face[index1], face[index2]) == 0) {
				count++;

				if (count == 3) {
					result = 1;
					break;
				}
			}
		}
	}

	return result;
}

int has_two_pairs(const char* face[], Hand hand) {
	int result = 0, pairs_found = 0, used_card[5] = { 0 };

	for (int i = 0; i < 4; i++) {
		if (used_card[i] == 0) {
			int index1 = hand.h[i].face_index;

			for (int j = i + 1; j < 5; j++) {
				if (used_card[j] == 0) { 
					int index2 = hand.h[j].face_index;

					if (strcmp(face[index1], face[index2]) == 0) {
						pairs_found++;
						used_card[i] = 1;
						used_card[j] = 1;
						break;
					}
				}
			}
		}
	}

	if (pairs_found == 2) {
		result = 1;
	}

	return result;
}

int has_pair(const char* face[], Hand hand) {
	int result = 0, index1 = 0, index2 = 0;

	for (int i = 0; i < 4; i++) {
		index1 = hand.h[i].face_index;

		for (int j = i + 1; j < 5; j++) {
			index2 = hand.h[j].face_index;

			if (strcmp(face[index1], face[index2]) == 0) {
				result = 1;
				break;
			}
		}
	}

	return result;
}

// keeps track of the ranks that each player has
void get_hand_ranks(const char* face[], Hand hand, int hand_rank[]) {
	hand_rank[0] = has_four_of_a_kind(face, hand);
	hand_rank[1] = has_full_house(face, hand);
	hand_rank[2] = has_flush(face, hand);
	hand_rank[3] = has_straight(hand);
	hand_rank[4] = has_three_of_a_kind(face, hand);
	hand_rank[5] = has_two_pairs(face, hand);
	hand_rank[6] = has_pair(face, hand);
}

// determines who wins the game
void determine_winner(int player_rank[], int dealer_rank[]) {
	int player_tier = 0, dealer_tier = 0;

	// gets the highest rank for the player
	for (int i = 0; i < 7; i++) {
		if (player_rank[i] == 1) {
			player_tier = i;
			break;
		}
	}

	// gets the highest rank for the dealer
	for (int i = 0; i < 7; i++) {
		if (dealer_rank[i] == 1) {
			dealer_tier = i;
			break;
		}
	}

	// compares the two tiers (which number is smaller)
	if (player_tier < dealer_tier) {
		printf("You win!\n\n");
	}
	else if (player_tier == dealer_tier) {
		printf("It's a draw!\n\n");
	}
	else {
		printf("You lose!\n\n");
	}
}

// resets the deck and hands for the next game
void reset(int deck[][13], Hand* p_hand, Hand* d_hand) {
	// reset the deck
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 13; c++) {
			deck[r][c] = 0;
		}
	}

	// reset both hands
	for (int i = 0; i < 5; i++) {
		(*p_hand).h[i].face_index = 0;
		(*p_hand).h[i].suit_index = 0;
		(*d_hand).h[i].face_index = 0;
		(*d_hand).h[i].suit_index = 0;
	}
}