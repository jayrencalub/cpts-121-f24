#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// * == [] for arrays
int *selection_sort(int array[], int size);
void print_array(int array[], int size);

int main(void) {
	int ids[] = { 3333, 1111, 4444, 2222, 0001 };
	int two_d[5][5] = { {1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10} };
	printf("%d", two_d[0][4]);
	/*char str[4] = { 'a', 'b', 'c', '\0'}, str2[100] = "cat", str3[10] = "Hel\0lo!";
	printf("%s", &str3[4]);*/

	//for (int i = 0; i < sizeof(str3); i++) {
	//	printf("%c ", str3[i]);
	//}

	//printf("Original list: ");
	//print_array(ids, 5);

	//selection_sort(ids, 5);

	//printf("\nSorted list: ");
	//print_array(ids, 5);

	return 0;
}

int *selection_sort(int array[], int size) {
	int temp = 0, index = 0, max_index = 0, passes = 0;

	for (; passes < size - 1; ++passes) { // controlling the number of passes to make thru the list
		for (index = 1, max_index = 0; index < size - passes; ++index) { // resetting to the beginning and iterating thru the list
			if (array[index] > array[max_index]) {
				max_index = index; // found a new max
			}
		}

		// swap items since the location of the max is known
		temp = array[max_index];
		array[max_index] = array[index - 1]; // array[size - passes - 1];
		array[index - 1] = temp;
	}

	return array;
}

void print_array(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
}