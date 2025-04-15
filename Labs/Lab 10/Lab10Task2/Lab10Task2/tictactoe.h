#ifndef TICTACTOE_H
#define TICTACTOE_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_ROWS 3
#define MAX_COLS 3

// structs
typedef struct coordinate {
	int row;
	int column;
} Coordinate;

typedef struct cell {
	int occupied; // 1 if an X or O is in this cell; 0 otherwise
	char symbol; // X for one player, O for the other player
	Coordinate location; // A struct defined above, which represents the position of the cell within the game board
} Cell;

typedef struct game_info {
	int wins;
	int losses;
	int total_games_played;
} Game_info;

// functions
void init_board(char board[][MAX_COLS], int row_size, int col_size, char symbol);
void edit_board(char board[][MAX_COLS], int row_pos, int col_pos, char symbol);
void print_board(char board[][MAX_COLS], int row_size, int col_size);

int determine_winner(char board[][MAX_COLS], int row_size, int col_size);

#endif

