/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 4
* Date: October 11, 2024
* Description: This program runs a game of craps that the user
*			   can play.
*****************************************************************/

#ifndef CRAPS_H
#define CRAPS_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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
void menu_options(int);

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
int home_screen(void);

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
void print_game_rules(void);

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
double get_bank_balance(void);

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
double get_wager_amount(void);

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
int check_wager_amount(double wager, double balance);

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
int roll_die(void);

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
int calculate_sum_dice(int die1_value, int die2_value);

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
int is_win_loss_or_point(int);

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
int is_point_loss_or_neither(int sum_dice, int point_value);

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
double adjust_bank_balance(double bank_balance, double
	wager_amount, int add_or_subtract);

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
void chatter_messages(int number_rolls, int win_loss_neither, double
	initial_bank_balance, double current_bank_balance);

#endif