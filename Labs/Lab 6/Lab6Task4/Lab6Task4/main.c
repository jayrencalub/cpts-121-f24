#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

int random();
void run_game(int);

int main(void) {

	srand((unsigned int) time(NULL));
	run_game(random());

	return 0;
}

int random() {
	return rand() % 200 - 100;
}

void run_game(int mystery) {
	int guess = 0, attempts = 0;
	printf("Guess a random number from -100 to 100!\n");
	scanf("%d", &guess);

	while (!(guess == mystery)) {
		if (guess < mystery) {
			printf("Too low! Try again: ");
			scanf("%d", &guess);
		}
		else {
			printf("Too high! Try again: ");
			scanf("%d", &guess);
		}
		attempts++;
	}

	printf("\nYou guessed it! The number was: %d\nIt took you %d attempts to guess the number",
		mystery, attempts);
}