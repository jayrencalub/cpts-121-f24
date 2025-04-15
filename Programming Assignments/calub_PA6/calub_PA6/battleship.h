#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define VERTICAL 0
#define HORIZONTAL 1

typedef struct stats {
	int num_hits;
	int num_misses;
	int total_shots;
	double hit_percentage;
	char win_or_lose;
} Stats;

// greets the player and prints the rules
void home_screen();

// creates the board
void init_board(char board[][MAX_COLS], int row_size, int col_size, char symbol);

// prints the board
void print_board(char board[][MAX_COLS], int row_size, int col_size);

// modifies a specific cell on the board
void update_board(char board[][MAX_COLS], int row_coord, int col_coord, char symbol);

// picks who goes first
int pick_first();

// lets the user choose between manual and random placement
int manual_or_random();

// user places ships manually
void manual_placement(char board[][MAX_COLS]);

// ships are randomly placed
void random_placement(char board[][MAX_COLS]);

// checks whether the player got a hit
int check_shot(char board[][MAX_COLS], char board_hidden[][MAX_COLS], int player, int ship_cells[], int row_coord, int col_coord);

// prints the result of the current turn
void output_current_move(FILE* outfile, int player, int row_coord, int col_coord, int hit_or_miss, int ship_sunk);

// checks if a ship got sunk
int check_if_sunk_ship(int ship_cells[]);

// checks if there is a winner
int is_winner(int ship_cells[], int player);

// prints the final stats of the player and computer
void output_stats(FILE* outfile, Stats p1, Stats p2);

#endif