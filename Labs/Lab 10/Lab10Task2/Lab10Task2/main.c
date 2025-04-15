#include "tictactoe.h"

int main(void) {
	char board[MAX_ROWS][MAX_COLS];

	// printf("%d", determine_winner(board, 3, 3));

	Coordinate c = { 0,0 };
	Cell cell = { 0, '\0', c.row, c.column };
	Game_info p1 = { 0,0,0 };
	Game_info p2 = { 0,0,0 };

	init_board(board, MAX_ROWS, MAX_COLS, '-');
	print_board(board, MAX_ROWS, MAX_COLS);


	
	// initial board is printed

	// X goes first, then O goes next
	// after being prompted, player inputs the row and column

	// the coordinate is checked to see if it is occupied already
	// if yes, the player is prompted to enter another coordinate
	// if not, the row and column gets put into the cell struct, then the board gets modified
	// program checks whether a player wins or if the board is full

	// before next turn, board is printed
	
	// when game ends, p1 and p2 info gets modified
}