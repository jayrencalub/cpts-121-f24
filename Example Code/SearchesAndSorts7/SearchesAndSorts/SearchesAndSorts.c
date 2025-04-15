#include "SearchesAndSorts.h"

// sequentially accesses each element
// and sets it to a value entered by the user
void init_array(int arr[], int size)
{
	int index = 0;

	// we start at index 0 and move sequentially
	// through the array by simply using a counting loop
	// and updating index by for each iteration of the loop
	while (index < size)
	{
		printf("Enter an integer: ");
		scanf("%d", &arr[index]);
		++index;
	}
}

// sequentially accesses each element
// and prints the value
void print_array(int arr[], int size)
{
	int index = 0;

	// we start at index 0 and move sequentially
	// through the array by simply using a counting loop
	// and updating index by for each iteration of the loop
	for (; index < size; ++index)
	{
		printf("arr[%d]: %d\n", index, arr[index]);
	}
}

// precondtion: size <= MAX_SIZE
int sequential_search(int list[], int size, int target)
{
	int index = 0, found = 0;

	for (index = 0, found = 0 /* yes, we can have multiple initializatizers */; 
		!found && index < size; ++index)
	{
		if (list[index] == target)
		{
			// we found the target 
			found = 1;
		}
	}

	return found;
}

// precondtion: size <= MAX_SIZE; list must be ascending order
int binary_search(int list[], int size, int target)
{
	int left_index = 0, right_index = size - 1, mid_index = -1, found = 0;

	while (!found && left_index <= right_index)
	{
		mid_index = (left_index + right_index) / 2; // integer division

		if (target == list[mid_index])
		{
			found = 1; // we found the target at the mid_index
		}
		else if (target < list[mid_index])
		{
			right_index = mid_index - 1;
		}
		else
		{
			left_index = mid_index + 1;
		}
	}

	return found;
}

// returns the address of the first element in the sorted array or list
// orders from smallest to largest
int* selection_sort(int list[], int size)
{
	int temp = 0, index = 0, max_index = 0, passes = 0;

	for (; passes < size - 1; ++passes) // controlling the number of passes to make through the list
	{
		for (index = 1, max_index = 0; index < size - passes; ++index) // reseting to the beginning and iterating through the list
		{
			if (list[index] > list[max_index])
			{
				// we found a new max
				max_index = index;
			}
		}
		
		//we know where the max is in the list - so let's swap items
		temp = list[max_index];
		list[max_index] = list[index - 1]; //list[size - passes - 1];
		list[index - 1] = temp;
	}

	return list;
}

// this function mirrors the standard library function: strcpy ()
// the characters from src are copied into dest - both dest and src
// store the address of the first location in an array
char* my_strcpy(char *dest, const char* src)
{
	int index = 0;

	for (; src[index] != '\0'; ++index)
	{
		dest[index] = src[index];
	}

	dest[index] = '\0';

	return dest; // return the address of the first character in dest - it's
	             // safe to do because the address is referring to an array
	             // that's declared outside of my_strcpy (i.e. main ())
}

// initializes the 2-D game board for PA 6 to the symbol passed in as a parameter
// the symbol is the water symbol ('~') in this case.
void init_board(char board[][MAX_COLS], int row_size, int col_size, char symbol)
{
	int row_index = 0, col_index = 0;

	for (; row_index < row_size; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < col_size; ++col_index) // controls the column
		{
			board[row_index][col_index] = symbol;
		}
	}
}

// shows a way to print out the the game board for Battleship
void print_board(char board[][MAX_COLS], int row_size, int col_size)
{
	int row_index = 0, col_index = 0;

	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (; row_index < row_size; ++row_index) // controls the row
	{
		printf("%-2d", row_index);
		for (col_index = 0; col_index < col_size; ++col_index) // controls the column
		{
			printf ("%-2c", board[row_index][col_index]);
		}
		putchar('\n');
	}
}