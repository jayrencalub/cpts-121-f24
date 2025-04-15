/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 4
* Date: October 11, 2024
* Description: This program runs a game of craps that the user
*			   can play.
*****************************************************************/

#include "craps.h"

/*************************************************************
* Function: menu_options()
* Date Created: 10/11/2024
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
	case 3: printf("\nExiting...\n"); // exit game
		break;
	default: printf("\nError in input\n");
		break;
	}
}

/*************************************************************
* Function: home_screen()
* Date Created: 10/11/2024
* Date Last Modified:
* Description: This program prints out a home screen with options
*			   that the user picks by typing a number
* Input parameters:
* Returns: option: integer of what the user picked
* Preconditions:
* Postconditions: an integer is being returned
*************************************************************/
int home_screen(void) {
	int option;

	printf("\n**********************************************************\n");
	printf("*********************WELCOME TO CRAPS*********************\n");
	printf("**********************************************************\n\n");
	printf("Type a number from 1 to 3 depending on what you want:\n1: Game Rules\n2: Start Game\n3: Exit Game\n\n");

	scanf("%d", &option);

	return option;
}

/*************************************************************
* Function: print_game_rules()
* Date Created: 10/11/2024
* Date Last Modified:
* Description: This function prints the game rules of craps
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/
void print_game_rules(void) {
	printf("\n**************************RULES**************************\n");
	printf("You roll two standard dice, then the face values of the two dice get added together\n");
	printf("If you roll a 7 or 11 on the first roll, you win\n");
	printf("If you roll a 2, 3, or 12 on the first roll, you lose\n");
	printf("Otherwise, that number becomes your \"point\", and you keep rolling the dice\n");
	printf("You win if you get that number again, but lose if you roll a 7\n\n");
}

/*************************************************************
* Function: get_bank_balance()
* Date Created: 10/11/2024
* Date Last Modified:
* Description: This function gets the bank balance of the user
*			   from their input
* Input parameters:
* Returns: balance: double value of the user's balance
* Preconditions:
* Postconditions: a double is returned
*************************************************************/
double get_bank_balance(void) {
	double balance;

	printf("Enter your bank balance: ");
	scanf("%lf", &balance);

	return balance;
}

/*************************************************************
* Function: get_wager_amount()
* Date Created: 10/11/24
* Date Last Modified:
* Description: This function gets the user's wager from their 
			   input
* Input parameters:
* Returns: wager: double value of the user's wager
* Preconditions:
* Postconditions: a wager is returned
*************************************************************/
double get_wager_amount(void) {
	double wager;

	printf("Enter your bet: ");
	scanf("%lf", &wager);

	return wager;
}

/*************************************************************
* Function: check_wager_amount()
* Date Created: 10/11/2024
* Date Last Modified:
* Description: This function determines whether the user's wager
*			   exceeds their balance
* Input parameters: wager: double of the user's wager
*					balance: double of the user's balance
* Returns: result: integer value of the result 
* Preconditions: 
* Postconditions: an integer is returned
*************************************************************/
int check_wager_amount(double wager, double balance) {
	int result = 0; // wager exceeds balance

	if (wager <= balance) {
		result = 1; // wager is valid
	}

	return result;
}

/*************************************************************
* Function: roll_die()
* Date Created: 10/11/2024
* Date Last Modified:
* Description: This function "rolls" a standard die and returns
*			   the result
* Input parameters:
* Returns: integer of a random number bounded between 1-6 inclusive
* Preconditions:
* Postconditions: an integer is returned
*************************************************************/
int roll_die(void) {
	return rand() % 6 + 1;
}

/*************************************************************
* Function: calculate_sum_dice()
* Date Created: 10/11/2024
* Date Last Modified:
* Description: This function adds together two integer values
* Input parameters: die1_value: int of the first die's number
*					die2_value: int of the second die's number
* Returns: the sum of die1_value and die2_value
* Preconditions: the arguments must be integers
* Postconditions: an int is returned
*************************************************************/
int calculate_sum_dice(int die1_value, int die2_value) {
	return die1_value + die2_value;
}

/*************************************************************
* Function: is_win_loss_or_point()
* Date Created: 10/11/2024
* Date Last Modified:
* Description: This function determins whether the player wins,
*			   loses, or gets a point value on the first roll
* Input parameters: sum_dice: int of the sum of the two dice
* Returns: result: int of the result
* Preconditions: argument must be an integer
* Postconditions: an int is returned
*************************************************************/
int is_win_loss_or_point(int sum_dice) {
	int result = 0; // loss

	if (sum_dice == 7 || sum_dice == 11) {
		result = 1; // win
	}
	else if (sum_dice == 4 || sum_dice == 5 || sum_dice == 6 ||
		sum_dice == 8 || sum_dice == 9 || sum_dice == 10) {
		result = -1; // point
	}

	return result;
}

/*************************************************************
* Function: is_point_loss_or_neither()
* Date Created: 10/11/2024
* Date Last Modified:
* Description: This function determines whether the player wins
*			   or loses on rolls beyond the first roll
* Input parameters: sum_dice: int of the sum of dice
*					point_value: int of the point value the 
*								 user is trying to get
* Returns: result: int of the result
* Preconditions: arguments must be integers
* Postconditions: int is returned
*************************************************************/
int is_point_loss_or_neither(int sum_dice, int point_value) {
	int result = -1; // neither win nor loss

	if (sum_dice == point_value) {
		result = 1; // win
	}
	else if (sum_dice == 7) {
		result = 0; // loss
	}

	return result;
}

/*************************************************************
* Function: adjust_bank_balance()
* Date Created: 10/11/2024
* Date Last Modified:
* Description: This function changes the value of the balance
* Input parameters: bank_balance: double of the bank balance
					wager_amount: double of the user's wager
					add_or_subtract: int that determines whether
									 to add or subtract from balance
* Returns: bank_balance: the new balance 
* Preconditions: first 2 arguments must be double, 3rd one must be int
* Postconditions: a double is returned
*************************************************************/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
	if (add_or_subtract == 1) {
		bank_balance += 2 * wager_amount; // user wins double
	}
	else if (add_or_subtract == 0) {
		bank_balance -= wager_amount;
	}
	
	return bank_balance;
}

/*************************************************************
* Function: chatter_messages()
* Date Created: 10/11/2024
* Date Last Modified:
* Description: This function puts a random message based on
*			   a random variable before each roll
* Input parameters: number_rolls: int of the number of rolls in the current game
*					win_loss_neither: int on whether the user won or lost
*					initial_bank_balance: double of the user's bank balance at the start
*					current_bank_balance: double of the user's current bank balance
* Returns:
* Preconditions: first 2 arugments must be int, last 2 must be double
* Postconditions: 
*************************************************************/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
	int message_type = rand() % 2 + 1;

	switch (message_type) {
		case 1: // chatter based on number of rolls
			if (number_rolls == 0) {
				printf("\nIt's your first roll, you better not lose!\n");
			}
			else if (number_rolls <= 5) {
				printf("Hurry up, let's make this quick!\n");
			}
			else {
				printf("Dang you are taking way too long, finish NOW\n");
			}
			break;
		case 2: // chatter based on the player's current bank balance
			if (current_bank_balance == 0) {
				printf("Lol you're so broke, time to give up\n");
			}
			else if (current_bank_balance < initial_bank_balance) {
				printf("You're at a loss rn, time to bet more!\n");
			}
			else if (current_bank_balance > initial_bank_balance) {
				printf("You've made a profit! Time to cash in\n");
			}
			else {
				printf("Your balance hasn't changed! Get betting!\n");
			}
			break;
	}

	// chatter based on whether the player won or lost
	switch (win_loss_neither) {
		case -1: // point value or neutral result
			if (number_rolls == 1) { // point
				printf("Got a point? Let's go!\n");
			}
			else {
				printf("Keep going, you'll eventually finish\n");
			}
			break;
		case 0: // lose
			printf("You lost??? you SUCK\n");
			break;
		case 1: // win
			printf("Congrats, you actually won something for once\n");
			break;
	}

}