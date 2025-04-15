/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Blackjack
* Date: October 16, 2024
* Description: This program runs a game of blackjack that the user
*			   can play.
*****************************************************************/

#include "blackjack.h"

int display_menu() {
	int option;
	printf("******************************************************\n");
	printf("*********************BLACKJACK************************\n");
	printf("******************************************************\n\n\n");
	printf("Type a number from 1 to 3 depending on what you want:\n1: Game Rules\n2: Start Game\n3: Exit Game\n\n");

	scanf("%d", &option);

	return option;
}

void menu_options(int option) {
	switch (option) {
	case 1: print_game_rules(); // print the rules
		break;
	case 2: printf("\nStarting game...\n\n");
		break;
	case 3: printf("\nExiting...\n"); // exit game
		break;
	default: printf("\nError in input\n");
		break;
	}
}

void print_game_rules(void) {
	printf("\n**************************RULES**************************\n");
	printf("The goal of this game is to get to 21, or close to it.\n");
	printf("If you go over 21, you bust, making you lose\n");
	printf("SCORING:\nAce: You get to choose between 1 or 11\n2-10: The value of that card\nFace cards: 10\n");
	printf("The dealer will give you 2 cards, and the scores of each card will be summed up\n");
	printf("The same goes for the dealer, and you want to get more points than the dealer without busting\n");
	printf("You can choose to hit (draw another card), or stand (stop drawing cards)\n");
	printf("If you stand, your cards will be compared to the dealer's\n");
	printf("If your have more points than the dealer, you win, otherwise you lose\n\n");
}

double get_bank_balance() {
	double balance;

	printf("Enter your bank balance: ");
	scanf("%lf", &balance);

	return balance;
}

double get_wager_amount() {
	double wager;

	printf("Enter your bet: ");
	scanf("%lf", &wager);

	return wager;
}

int check_wager_amount(double wager, double balance) {
	int result = 0; // wager exceeds balance

	if (wager <= balance) {
		result = 1; // wager is valid
	}

	return result;
}

int draw_card() {
	return rand() % 10 + 1;
}

void print_card(int card) {
	switch (card) {
	case ACE: printf("Ace\n");
		break;
	case 2: printf("Two\n");
		break;
	case 3: printf("Three\n");
		break;
	case 4: printf("Four\n");
		break;
	case 5: printf("Five\n");
		break;
	case 6: printf("Six\n");
		break;
	case 7: printf("Seven\n");
		break;
	case 8: printf("Eight\n");
		break;
	case 9: printf("Nine\n");
		break;
	case 10:
		switch (rand() % 4 + 1) {
		case 1: printf("Ten\n");
			break;
		case 2: printf("Jack\n");
			break;
		case 3: printf("Queen\n");
			break;
		case 4: printf("King\n");
			break;
		}
	case 11: printf("Ace\n");
	}
}

int choose_ace_score() {
	int choice = 0;

	printf("1 or 11? ");
	scanf("%d", &choice);

	return choice;
}

int sum_cards(int sum, int card_num) {
	return sum + card_num;
}

void display_sum(int sum) {
	printf("sum: %d\n", sum);
}

int check_sum(int sum) {
	int result = -1; // neither win nor loss

	if (sum > 21) {
		printf("Bust! You lose!\n");
		result = 0; // loss
	}
	else if (sum == 21) {
		printf("BLACKJACK! You win!\n");
		result = 1; // win
	}

	return result;
}

int compare_scores(int player_score, int dealer_score) {
	int result = -1; // tie, if player and dealer have same score
	printf("Player: %d\nDealer: %d\n", player_score, dealer_score);

	if (dealer_score > 21) {
		printf("Dealer busts! You win!\n");
		result = 1;
	}
	else if (player_score > dealer_score) {
		printf("You score higher! You win!\n");
		result = 1; // win
	}
	else if (player_score < dealer_score) {
		printf("Dealer wins! You lose!\n");
		result = 0; // loss
	}

	return result;
}

int hit_stand() {
	char choice = '\0';
	int result = -1;
	
	// checking for invalid responses
	while (result == -1) {
		printf("Press H to hit, or S to stand (CASE SENSITIVE): ");
		scanf(" %c", &choice);

		if (choice == 'H') {
			result = 1;
		}
		else if (choice == 'S') {
			result = 0;
		}
		else {
			printf("Invalid response, please try again\n");
		}
	}
	
	return result;
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
	if (add_or_subtract == 1) {
		bank_balance += 2 * wager_amount; // user wins double their wager
	}
	else if (add_or_subtract == 0) {
		bank_balance -= wager_amount;
	}

	return bank_balance;
}