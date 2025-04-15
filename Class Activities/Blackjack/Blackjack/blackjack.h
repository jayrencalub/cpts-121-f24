/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Blackjack 
* Date: October 16, 2024
* Description: This program runs a game of blackjack that the user
*			   can play.
*****************************************************************/

#ifndef BLACKJACK_H


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

#define ACE 1

int display_menu();
void menu_options(int);
void print_game_rules();
double get_bank_balance();
double get_wager_amount();
int check_wager_amount(double, double);
int draw_card();
void print_card(int);
int choose_ace_score();
int sum_cards(int, int);
void display_sum(int);
int check_sum(int);
int compare_scores(int, int);
int	hit_stand();
double adjust_bank_balance(double, double, int);


#endif