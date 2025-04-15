#define _CRT_SECURE_NO_WARNINGS

#ifndef CONNECT4_H
#define CONNECT4_H

#define MAX_ROWS 6
#define MAX_COLS 7

// enumerated type 
typedef enum is_token {
	NONE,
	P1,
	P2
} Is_token;

typedef struct coord {
	int row, col;
} Coord;

typedef struct cell {
	Coord location;
	Is_token token;
} Cell;

typedef struct board {
	Cell game_board[MAX_ROWS][MAX_COLS];
	int num_rows, num_cols;
} Board;

#endif