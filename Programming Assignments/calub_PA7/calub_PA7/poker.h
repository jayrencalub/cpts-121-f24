/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 7
* Date: 11/22/2024
* Description: This program runs a game of poker
*****************************************************************/

#ifndef POKER_H
#define POKER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FOUR_KIND 0
#define FULL_HOUSE 1
#define FLUSH 2
#define STRAIGHT 3
#define THREE_KIND 4
#define TWO_PAIRS 5
#define PAIR 6

typedef struct card {
	int face_index;
	int suit_index;
} Card;

typedef struct hand {
	Card h[5];
} Hand;

void menu_options(int);
int home_screen(void);
void print_game_rules(void);
void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], Hand* p_hand, Hand* d_hand);
void draw(const int wDeck[][13], Hand* hand, int* card_counter, int cards_to_replace[]);
int has_four_of_a_kind(const char* face[], Hand hand);
int has_full_house(const char* face[], Hand hand);
int has_flush(const char* face[], Hand hand);
int has_straight(Hand hand);
int has_three_of_a_kind(const char* face[], Hand hand);
int has_two_pairs(const char* face[], Hand hand);
int has_pair(const char* face[], Hand hand);
void get_hand_ranks(const char* face[], Hand hand, int hand_rank[]);
void determine_winner(int player_rank[], int dealer_rank[]);
void reset(int deck[][13], Hand* p_hand, Hand* d_hand);

#endif
