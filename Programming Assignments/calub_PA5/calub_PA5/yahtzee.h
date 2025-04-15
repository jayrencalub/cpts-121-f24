/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 5
* Date: October 25, 2024
* Description: This program runs a game of 2-player Yahtzee
*****************************************************************/

#ifndef YAHTZEE_H
#define YAHTZEE_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 5
#define FREQUENCY_SIZE 7
#define NUM_COMBOS 13
#define FULL_HOUSE 25
#define S_STRAIGHT 30
#define L_STRAIGHT 40
#define YAHTZEE 50
#define UPPER_LOWER_CUTOFF 6
#define BONUS_THRESHOLD 63
#define BONUS_SCORE 35

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
void menu_options(int);

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
int home_screen(void);

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
void print_game_rules(void);

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
void roll_dice(int[], int[], int*);

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
void print_rolls(int[]);

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
int get_freq(int [], int []);

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
int* calculate_scores(int[], int[], int[]);

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
void display_scores(int[], int[]);

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
int* select_combo(int[], int[]);

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
int sum_dice(int[]);

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
int* reset(int[], int*, int*);

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
int* ask_to_reroll(int[], int, int*);

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
void calc_upper_score(int[], int[], int*, int*);

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
void has_bonus(int, int, int*, int*);

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
void calc_score(int[], int[], int, int, int*, int*);

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
void determine_winner(int, int);

#endif
