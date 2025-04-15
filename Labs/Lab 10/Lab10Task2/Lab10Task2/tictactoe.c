#include "tictactoe.h"

void init_board(char board[][MAX_COLS], int row_size, int col_size, char symbol) {
	for (int r = 0; r < row_size; r++) {
		for (int c = 0; c < col_size; c++) {
			board[r][c] = symbol;
		}
	}
}

void edit_board(char board[][MAX_COLS], int row_pos, int col_pos, char symbol) {
	board[row_pos][col_pos] = symbol;
}

void print_board(char board[][MAX_COLS], int row_size, int col_size) {
	printf("%3d%2d%2d", 1, 2, 3);
	printf("\n");

	for (int r = 0; r < row_size; r++) {
		printf("%d ", r + 1);
		for (int c = 0; c < col_size; c++) {
			printf("%c ", board[r][c]);
		}
		printf("\n");
	}
}

int determine_winner(char board[][MAX_COLS], int row_size, int col_size) {
	int winner = -1; // -1: scratch, 0: player O wins, 1: player X wins
	int count = 1; // looking for 3 in a row
	char first_letter = '\0';

	// check for across
	for (int r = 0; r < row_size; r++) {
		first_letter = board[r][0];
		count = 1;

		// check for 3 in a row
		for (int c = 1; c < col_size; c++) {
			if (board[r][c] == first_letter) {
				count++;
			}
		}

		if (count == 3 && first_letter == 'X') {
			winner = 1;
			break;
		}
		else if (count == 3 && first_letter == 'O') {
			winner = 0;
			break;
		}
	}

	// check for down
	count = 1;
	for (int c = 0; c < col_size; c++) {
		first_letter = board[0][c];
		count = 1;

		for (int r = 1; r < row_size; r++) {

		}
	}

	if (count == 3 && first_letter == 'X') {
		winner = 1;
	}
	else if (count == 3 && first_letter == 'O') {
		winner = 0;
	}

	// check for diagonal

	// top left to bottom right
	first_letter = board[0][0];
	for (int r = 1, c = 1; r < row_size; r++, c++) {
		count = 1;
		if (board[r][c] == first_letter) {
			count++;
		}
	}

	if (count == 3 && first_letter == 'X') {
		winner = 1;
	}
	else if (count == 3 && first_letter == 'O') {
		winner = 0;
	}

	// bottom left to top right
	first_letter = board[2][0];

	return winner;
}