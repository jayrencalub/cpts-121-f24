#include "battleship.h"

void home_screen() {
	char enter;

	printf("******************WELCOME TO BATTLESHIP******************\n");
	printf("You are going against a computer in a 10x10 battleship game\n");
	printf("There are 5 different ships:\nCarrier (c, 5 cells long)\nBattleship (b, 4 cells long)\nCruiser (r, 3 cells long)\nSubmarine (s, 3 cells long)\nDestroyer (d, 2 cells long)\n");
	printf("You can choose to place your ships manually, or randomly\n");
	printf("If you manually place your ships, you are not allowed to overlap ships or go out of bounds\n");
	printf("Your goal is to destroy the computer's ships before it destroys yours\n");
	printf("Hits will be indicated with a '*', while misses will be indicated with an 'm'\n");
	printf("You win if you destroy all of your opponent's ships\n");
	printf("Press enter to begin playing!");
	scanf("%c", &enter);
	system("cls");
}

void init_board(char board[][MAX_COLS], int row_size, int col_size, char symbol) {
	for (int r = 0; r < row_size; r++) {
		for (int c = 0; c < col_size; c++) {
			board[r][c] = symbol;
		}
	}
}

void print_board(char board[][MAX_COLS], int row_size, int col_size) {
	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	printf("\n");

	for (int r = 0; r < row_size; r++) {
		printf("%d ", r);
		for (int c = 0; c < col_size; c++) {
			printf("%c ", board[r][c]);
		}
		printf("\n");
	}
}

void update_board(char board[][MAX_COLS], int row_coord, int col_coord, char symbol) {
	board[row_coord][col_coord] = symbol;
}

int pick_first() {
	int result = rand() % 2 + 1;

	if (result == 1) {
		printf("Player 1 goes first!\n");
	}
	else {
		printf("Player 2 goes first!\n");
	}

	return result;
}

int manual_or_random() {
	int option = 0;

	printf("Would you like to place your ships manually or randomly? Enter 1 for manual, 2 for random: ");
	scanf("%d", &option);

	while (option < 1 || option > 2) {
		printf("Invalid response, please try again: ");
		scanf("%d", &option);
	}

	return option;
}

void manual_placement(char board[][MAX_COLS]) {
	int row_start_pos = 0, col_start_pos = 0, orientation = 0, valid_placement = 0;

	// carrier
	while (valid_placement == 0) {
		print_board(board, MAX_ROWS, MAX_COLS);
		printf("Enter your starting coordinate for your carrier (row column): ");
		scanf("%d %d", &row_start_pos, &col_start_pos);
		printf("Enter the orientation you want (0 for vertical, 1 for horizontal): ");
		scanf("%d", &orientation);

		if (orientation == VERTICAL) {
			for (int i = row_start_pos; i < row_start_pos + 5; i++) {
				if (board[i][col_start_pos] == '-') {
					valid_placement = 1;
				}
				else {
					system("cls");
					printf("Invalid placement, please try again\n\n");
					valid_placement = 0;
					break;
				}
			}
		}
		else {
			for (int i = col_start_pos; i < col_start_pos + 5; i++) {
				if (board[row_start_pos][i] == '-') {
					valid_placement = 1;
				}
				else {
					system("cls");
					printf("Invalid placement, please try again\n\n");
					valid_placement = 0;
					break;
				}
			}
		}

		// placement
		if (orientation == VERTICAL && valid_placement == 1) {
			for (int i = row_start_pos; i < row_start_pos + 5; i++) {
				board[i][col_start_pos] = 'c';
			}
		}
		else if (orientation == HORIZONTAL && valid_placement == 1) {
			for (int i = col_start_pos; i < col_start_pos + 5; i++) {
				board[row_start_pos][i] = 'c';
			}
		}
		system("cls");
	}

	// battleship
	valid_placement = 0;
	while (valid_placement == 0) {
		print_board(board, MAX_ROWS, MAX_COLS);
		printf("Enter your starting coordinate for your battleship (row column): ");
		scanf("%d %d", &row_start_pos, &col_start_pos);
		printf("Enter the orientation you want (0 for vertical, 1 for horizontal): ");
		scanf("%d", &orientation);

		if (orientation == VERTICAL) {
			for (int i = row_start_pos; i < row_start_pos + 4; i++) {
				if (board[i][col_start_pos] == '-') {
					valid_placement = 1;
				}
				else {
					system("cls");
					printf("Invalid placement, please try again\n\n");
					valid_placement = 0;
					break;
				}
			}
		}
		else {
			for (int i = col_start_pos; i < col_start_pos + 4; i++) {
				if (board[row_start_pos][i] == '-') {
					valid_placement = 1;
				}
				else {
					system("cls");
					printf("Invalid placement, please try again\n\n");
					valid_placement = 0;
					break;
				}
			}
		}

		// placement
		if (orientation == VERTICAL && valid_placement == 1) {
			for (int i = row_start_pos; i < row_start_pos + 4; i++) {
				board[i][col_start_pos] = 'b';
			}
		}
		else if (orientation == HORIZONTAL && valid_placement == 1) {
			for (int i = col_start_pos; i < col_start_pos + 4; i++) {
				board[row_start_pos][i] = 'b';
			}
		}
		system("cls");
	}

	// cruiser
	valid_placement = 0;
	while (valid_placement == 0) {
		print_board(board, MAX_ROWS, MAX_COLS);
		printf("Enter your starting coordinate for your cruiser (row column): ");
		scanf("%d %d", &row_start_pos, &col_start_pos);
		printf("Enter the orientation you want (0 for vertical, 1 for horizontal): ");
		scanf("%d", &orientation);

		if (orientation == VERTICAL) {
			for (int i = row_start_pos; i < row_start_pos + 3; i++) {
				if (board[i][col_start_pos] == '-') {
					valid_placement = 1;
				}
				else {
					system("cls");
					printf("Invalid placement, please try again\n\n");
					valid_placement = 0;
					break;
				}
			}
		}
		else {
			for (int i = col_start_pos; i < col_start_pos + 3; i++) {
				if (board[row_start_pos][i] == '-') {
					valid_placement = 1;
				}
				else {
					system("cls");
					printf("Invalid placement, please try again\n\n");
					valid_placement = 0;
					break;
				}
			}
		}

		// placement
		if (orientation == VERTICAL && valid_placement == 1) {
			for (int i = row_start_pos; i < row_start_pos + 3; i++) {
				board[i][col_start_pos] = 'r';
			}
		}
		else if (orientation == HORIZONTAL && valid_placement == 1) {
			for (int i = col_start_pos; i < col_start_pos + 3; i++) {
				board[row_start_pos][i] = 'r';
			}
		}
		system("cls");
	}

	// submarine
	valid_placement = 0;
	while (valid_placement == 0) {
		print_board(board, MAX_ROWS, MAX_COLS);
		printf("Enter your starting coordinate for your submarine (row column): ");
		scanf("%d %d", &row_start_pos, &col_start_pos);
		printf("Enter the orientation you want (0 for vertical, 1 for horizontal): ");
		scanf("%d", &orientation);

		if (orientation == VERTICAL) {
			for (int i = row_start_pos; i < row_start_pos + 3; i++) {
				if (board[i][col_start_pos] == '-') {
					valid_placement = 1;
				}
				else {
					system("cls");
					printf("Invalid placement, please try again\n\n");
					valid_placement = 0;
					break;
				}
			}
		}
		else {
			for (int i = col_start_pos; i < col_start_pos + 3; i++) {
				if (board[row_start_pos][i] == '-') {
					valid_placement = 1;
				}
				else {
					system("cls");
					printf("Invalid placement, please try again\n\n");
					valid_placement = 0;
					break;
				}
			}
		}

		// placement
		if (orientation == VERTICAL && valid_placement == 1) {
			for (int i = row_start_pos; i < row_start_pos + 3; i++) {
				board[i][col_start_pos] = 's';
			}
		}
		else if (orientation == HORIZONTAL && valid_placement == 1) {
			for (int i = col_start_pos; i < col_start_pos + 3; i++) {
				board[row_start_pos][i] = 's';
			}
		}
		system("cls");
	}

	// destroyer
	valid_placement = 0;
	while (valid_placement == 0) {
		print_board(board, MAX_ROWS, MAX_COLS);
		printf("Enter your starting coordinate for your destroyer (row column): ");
		scanf("%d %d", &row_start_pos, &col_start_pos);
		printf("Enter the orientation you want (0 for vertical, 1 for horizontal): ");
		scanf("%d", &orientation);

		if (orientation == VERTICAL) {
			for (int i = row_start_pos; i < row_start_pos + 2; i++) {
				if (board[i][col_start_pos] == '-') {
					valid_placement = 1;
				}
				else {
					system("cls");
					printf("Invalid placement, please try again\n\n");
					valid_placement = 0;
					break;
				}
			}
		}
		else {
			for (int i = col_start_pos; i < col_start_pos + 2; i++) {
				if (board[row_start_pos][i] == '-') {
					valid_placement = 1;
				}
				else {
					system("cls");
					printf("Invalid placement, please try again\n\n");
					valid_placement = 0;
					break;
				}
			}
		}

		// placement
		if (orientation == VERTICAL && valid_placement == 1) {
			for (int i = row_start_pos; i < row_start_pos + 2; i++) {
				board[i][col_start_pos] = 'd';
			}
		}
		else if (orientation == HORIZONTAL && valid_placement == 1) {
			for (int i = col_start_pos; i < col_start_pos + 2; i++) {
				board[row_start_pos][i] = 'd';
			}
		}
		system("cls");
	}
}

void random_placement(char board[][MAX_COLS]) {
	int row_start_pos = 0, col_start_pos = 0, orientation = 0, valid_placement = 0;

	// carrier
	row_start_pos = rand() % 6;
	col_start_pos = rand() % 6;
	orientation = rand() % 2;

	// placement
	if (orientation == VERTICAL) {
		for (int i = row_start_pos; i < row_start_pos + 5; i++) {
			board[i][col_start_pos] = 'c';
		}
	}
	else {
		for (int i = col_start_pos; i < col_start_pos + 5; i++) {
			board[row_start_pos][i] = 'c';
		}
	}

	// battleship
	while (valid_placement == 0) {
		row_start_pos = rand() % 7;
		col_start_pos = rand() % 7;
		orientation = rand() % 2;

		// overlap check
		if (orientation == VERTICAL) {
			for (int i = row_start_pos; i < row_start_pos + 4; i++) {
				if (board[i][col_start_pos] == '-') {
					valid_placement = 1;
				}
				else {
					valid_placement = 0;
					break;
				}
			}
		}
		else {
			for (int i = col_start_pos; i < col_start_pos + 4; i++) {
				if (board[row_start_pos][i] == '-') {
					valid_placement = 1;
				}
				else {
					valid_placement = 0;
					break;
				}
			}
		}

		// placement
		if (orientation == VERTICAL && valid_placement == 1) {
			for (int i = row_start_pos; i < row_start_pos + 4; i++) {
				board[i][col_start_pos] = 'b';
			}
		}
		else if (orientation == HORIZONTAL && valid_placement == 1) {
			for (int i = col_start_pos; i < col_start_pos + 4; i++) {
				board[row_start_pos][i] = 'b';
			}
		}
	}

	// cruiser r
	valid_placement = 0;

	while (valid_placement == 0) {
		row_start_pos = rand() % 8;
		col_start_pos = rand() % 8;
		orientation = rand() % 2;

		// overlap check
		if (orientation == VERTICAL) {
			for (int i = row_start_pos; i < row_start_pos + 3; i++) {
				if (board[i][col_start_pos] == '-') {
					valid_placement = 1;
				}
				else {
					valid_placement = 0;
					break;
				}
			}
		}
		else {
			for (int i = col_start_pos; i < col_start_pos + 3; i++) {
				if (board[row_start_pos][i] == '-') {
					valid_placement = 1;
				}
				else {
					valid_placement = 0;
					break;
				}
			}
		}

		// placement
		if (orientation == VERTICAL && valid_placement == 1) {
			for (int i = row_start_pos; i < row_start_pos + 3; i++) {
				board[i][col_start_pos] = 'r';
			}
		}
		else if (orientation == HORIZONTAL && valid_placement == 1) {
			for (int i = col_start_pos; i < col_start_pos + 3; i++) {
				board[row_start_pos][i] = 'r';
			}
		}
	}

	// sub s 
	valid_placement = 0;

	while (valid_placement == 0) {
		row_start_pos = rand() % 8;
		col_start_pos = rand() % 8;
		orientation = rand() % 2;

		// overlap check
		if (orientation == VERTICAL) {
			for (int i = row_start_pos; i < row_start_pos + 3; i++) {
				if (board[i][col_start_pos] == '-') {
					valid_placement = 1;
				}
				else {
					valid_placement = 0;
					break;
				}
			}
		}
		else {
			for (int i = col_start_pos; i < col_start_pos + 3; i++) {
				if (board[row_start_pos][i] == '-') {
					valid_placement = 1;
				}
				else {
					valid_placement = 0;
					break;
				}
			}
		}

		// placement
		if (orientation == VERTICAL && valid_placement == 1) {
			for (int i = row_start_pos; i < row_start_pos + 3; i++) {
				board[i][col_start_pos] = 's';
			}
		}
		else if (orientation == HORIZONTAL && valid_placement == 1) {
			for (int i = col_start_pos; i < col_start_pos + 3; i++) {
				board[row_start_pos][i] = 's';
			}
		}
	}

	// destroyer d
	valid_placement = 0;

	while (valid_placement == 0) {
		row_start_pos = rand() % 9;
		col_start_pos = rand() % 9;
		orientation = rand() % 2;

		// overlap check
		if (orientation == VERTICAL) {
			for (int i = row_start_pos; i < row_start_pos + 2; i++) {
				if (board[i][col_start_pos] == '-') {
					valid_placement = 1;
				}
				else {
					valid_placement = 0;
					break;
				}
			}
		}
		else {
			for (int i = col_start_pos; i < col_start_pos + 2; i++) {
				if (board[row_start_pos][i] == '-') {
					valid_placement = 1;
				}
				else {
					valid_placement = 0;
					break;
				}
			}
		}

		// placement
		if (orientation == VERTICAL && valid_placement == 1) {
			for (int i = row_start_pos; i < row_start_pos + 2; i++) {
				board[i][col_start_pos] = 'd';
			}
		}
		else if (orientation == HORIZONTAL && valid_placement == 1) {
			for (int i = col_start_pos; i < col_start_pos + 2; i++) {
				board[row_start_pos][i] = 'd';
			}
		}
	}
}

int check_shot(char board[][MAX_COLS], char board_hidden[][MAX_COLS], int player, int ship_cells[], int row_coord, int col_coord) {
	int result = -1;
	
	if (player == 1) {
		while (board_hidden[row_coord][col_coord] != '-') {
			printf("You've hit this cell already, please try again: ");
			scanf("%d %d", &row_coord, &col_coord);
		}
	}
	else {
		while (board_hidden[row_coord][col_coord] != '-') {
			row_coord = rand() % 10;
			col_coord = rand() % 10;
		}
	}

	if (board[row_coord][col_coord] == 'c') {
		printf("%d %d is a hit!\n", row_coord, col_coord);
		ship_cells[0]--;
		result = 1; 
	}
	else if (board[row_coord][col_coord] == 'b') {
		printf("%d %d is a hit!\n", row_coord, col_coord);
		ship_cells[1]--;
		result = 1;
	}
	else if (board[row_coord][col_coord] == 'r') {
		printf("%d %d is a hit!\n", row_coord, col_coord);
		ship_cells[2]--;
		result = 1;
	}
	else if (board[row_coord][col_coord] == 's') {
		printf("%d %d is a hit!\n", row_coord, col_coord);
		ship_cells[3]--;
		result = 1;
	}
	else if (board[row_coord][col_coord] == 'd') {
		printf("%d %d is a hit!\n", row_coord, col_coord);
		ship_cells[4]--;
		result = 1;
	}
	else if (board[row_coord][col_coord] == '-') {
		printf("%d %d is a miss!\n", row_coord, col_coord);
		result = 0;
	} 

	return result;
}

void output_current_move(FILE* outfile, int player, int row_coord, int col_coord, int hit_or_miss, int ship_sunk) {
	if (hit_or_miss == 0) {
		fprintf(outfile, "Player %d shoots row %d column %d, misses\n", player, row_coord, col_coord);
	}
	else {
		fprintf(outfile, "Player %d shoots row %d column %d, hits a ship\n", player, row_coord, col_coord);
	}
	if (ship_sunk == 1) {
		if (player == 1) {
			fprintf(outfile, "PLAYER 2 SHIP SUNK\n");
		}
		else {
			fprintf(outfile, "PLAYER 1 SHIP SUNK\n");
		}
	}
}

int check_if_sunk_ship(int ship_cells[]) {
	int result = 0;

	for (int i = 0; i < 5; i++) {
		if (ship_cells[i] == 0) {
			result = 1;
			break;
		}
	}

	return result;
}

int is_winner(int ship_cells[], int player) {
	int winner = player;

	for (int i = 0; i < 5; i++) {
		if (ship_cells[i] != 0) {
			winner = 0;
			break;
		}
	}

	if (winner > 0) {
		printf("Player %d wins!", winner);
	}

	return winner;
}

void output_stats(FILE* outfile, Stats p1, Stats p2) {
	fprintf(outfile, "Player 1's Stats\n");
	fprintf(outfile, "%d\n", &p1.num_hits);
	fprintf(outfile, "%d\n", &p1.num_misses);
	fprintf(outfile, "%d\n", &p1.total_shots);
	fprintf(outfile, "%.2lf\n", &p1.hit_percentage);
	fprintf(outfile, "%c\n\n", &p1.win_or_lose);
	fprintf(outfile, "Player 2's Stats\n");
	fprintf(outfile, "%d\n", &p2.num_hits);
	fprintf(outfile, "%d\n", &p2.num_misses);
	fprintf(outfile, "%d\n", &p2.total_shots);
	fprintf(outfile, "%.2lf\n", &p2.hit_percentage);
	fprintf(outfile, "%c\n", &p2.win_or_lose);

}