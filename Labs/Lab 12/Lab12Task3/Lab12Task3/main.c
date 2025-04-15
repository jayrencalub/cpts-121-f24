#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 8
#define MAX_COLS 8

void print_maze(char maze[][MAX_COLS], int row_size, int col_size);
int check_for_path(char maze[][MAX_COLS], int, int);

int main(void) {
	char maze[MAX_ROWS][MAX_COLS] = { // hard coding to test code
		{'X', 'A', 'X', 'X', 'X', 'X', 'X', 'X'},
		{'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X'},
		{'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X'},
		{'X', ' ', ' ', ' ', ' ', 'X', 'X', 'X'},
		{'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X'},
		{'X', 'X', 'X', 'X', ' ', 'X', 'X', 'X'},
		{'X', 'X', 'X', 'X', ' ', ' ', 'X', 'X'},
		{'X', 'X', 'X', 'X', 'X', ' ', ' ', 'B'}};
	int result = 0;

	//print_maze(maze, MAX_ROWS, MAX_COLS);

	result = check_for_path(maze, 0, 1);
	printf("%d", result);

	return 0;
}

void print_maze(char maze[][MAX_COLS], int row_size, int col_size) {
	printf("%3d%2d%2d%2d%2d%2d%2d%2d", 0, 1, 2, 3, 4, 5, 6, 7);
	printf("\n");

	for (int r = 0; r < row_size; r++) {
		printf("%d ", r);
		for (int c = 0; c < col_size; c++) {
			printf("%c ", maze[r][c]);
		}
		printf("\n");
	}
}

int check_for_path(char maze[][MAX_COLS], int row_coord, int col_coord) {
	char current_cell = maze[row_coord][col_coord],
		temp_cell = '\0',
		up_cell = maze[row_coord - 1][col_coord],
		right_cell = maze[row_coord][col_coord + 1],
		down_cell = maze[row_coord + 1][col_coord],
		left_cell = maze[row_coord][col_coord - 1];
	int can_move_up = 0, can_move_down = 0, can_move_left = 0, can_move_right = 0;

	// checks if destination has been reached
	if (row_coord == 7 && col_coord == 7) {
		return 1;
	}
	else {
		// check up
		if (up_cell == ' ') {
			/*temp_cell = up_cell;
			up_cell = current_cell;
			current_cell = temp_cell;*/
			row_coord--;
			can_move_up = 1;
		}

		// check right
		if (right_cell == ' ') {
			/*temp_cell = right_cell;
			right_cell = current_cell;
			current_cell = temp_cell;*/
			col_coord++;
			can_move_right = 1;
		}

		// check down
		if (down_cell == ' ') {
			/*temp_cell = down_cell;
			down_cell = current_cell;
			current_cell = temp_cell;*/
			row_coord++;
			can_move_down = 1;
		}

		// check left
		if (left_cell == ' ') {
			/*temp_cell = left_cell;
			left_cell = current_cell;
			current_cell = temp_cell;*/
			col_coord--;
			can_move_left = 1;
		}

		if (!(can_move_up == 0 && can_move_down == 0 && can_move_left == 0 && can_move_right == 0)) {
			check_for_path(maze, row_coord, col_coord);
		}
		else {
			return 0;
		}
	}
}