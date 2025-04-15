#include "battleship.h"

int main(void) {
	int placement_method = 0, player_turn = 0, row_coord = 0, col_coord = 0, 
		hit_shot = 0, ship_sunk = 0, winner = 0;
	int p1_ship_cells[] = { 5, 4, 3, 3, 2 }, p2_ship_cells[] = { 5, 4, 3, 3, 2 }; // {c, b, r, s, d}
	char p1_board[MAX_ROWS][MAX_COLS], p2_board[MAX_ROWS][MAX_COLS], 
		p1_hidden[MAX_ROWS][MAX_COLS], p2_hidden[MAX_ROWS][MAX_COLS];
	FILE* outfile = fopen("battleship.log", "w");

	Stats p1 = { 0, 0, 0, 0, '\0' };
	Stats p2 = { 0, 0, 0, 0, '\0' };

	srand((unsigned int)time(NULL));

	home_screen();

	// initializing boards
	init_board(p1_board, MAX_ROWS, MAX_COLS, '-');
	init_board(p1_hidden, MAX_ROWS, MAX_COLS, '-');
	init_board(p2_board, MAX_ROWS, MAX_COLS, '-');
	init_board(p2_hidden, MAX_ROWS, MAX_COLS, '-');

	// ships get placed for both players
	placement_method = manual_or_random();
	if (placement_method == 1) {
		manual_placement(p1_board);
	}
	else {
		random_placement(p1_board);
	}
	random_placement(p2_board);

	player_turn = pick_first();

	print_board(p2_board, MAX_ROWS, MAX_COLS);
	// game runs until there is a winner
	do {
		if (player_turn == 1) { // player's turn
			printf("Your board\n");
			print_board(p1_board, MAX_ROWS, MAX_COLS);
			printf("\nOpponent's board\n");
			print_board(p2_hidden, MAX_ROWS, MAX_COLS);

			printf("Enter the row and column coords you want to hit: ");
			scanf("%d %d", &row_coord, &col_coord);
			hit_shot = check_shot(p2_board, p2_hidden, player_turn, p2_ship_cells, row_coord, col_coord);

			if (hit_shot == 1) {
				update_board(p2_hidden, row_coord, col_coord, '*');
				p1.num_hits++;
			}
			else {
				update_board(p2_hidden, row_coord, col_coord, 'm');
				p1.num_misses++;
			}

			ship_sunk = check_if_sunk_ship(p2_ship_cells);
			winner = is_winner(p2_ship_cells, player_turn);
			output_current_move(outfile, player_turn, row_coord, col_coord, hit_shot, ship_sunk);

			player_turn++;
			system("cls");
		}
		else { // computer's turn
			row_coord = rand() % 10;
			col_coord = rand() % 10;
			hit_shot = check_shot(p1_board, p1_hidden, player_turn, p1_ship_cells, row_coord, col_coord);

			if (hit_shot == 1) {
				update_board(p1_hidden, row_coord, col_coord, '*');
				p1.num_hits++;
			}
			else {
				update_board(p1_hidden, row_coord, col_coord, 'm');
				p1.num_misses++;
			}

			ship_sunk = check_if_sunk_ship(p1_ship_cells);
			winner = is_winner(p1_ship_cells, player_turn);
			output_current_move(outfile, player_turn, row_coord, col_coord, hit_shot, ship_sunk);

			player_turn--;
			system("cls");
		}

	} while (winner == 0);

	if (winner == 1) {
		p1.win_or_lose = 'W';
		p2.win_or_lose = 'L';
	}
	else {
		p2.win_or_lose = 'W';
		p1.win_or_lose = 'L';
	}

	p1.total_shots = p1.num_hits + p1.num_misses;
	p1.hit_percentage = p1.num_hits / p1.total_shots;

	output_stats(outfile, p1, p2);

	fclose(outfile);

	return 0;
}