// In this project, we'll explore arrays. We'll also learn about the following algorithms:
// - sequential search
// - binary search
// - bubble sort
// - selection sort
// - insertion sort (if we have time)

// History: 10/28/24 - Discussed 2-D arrays in detail. Started to help with PA 6.
//                     The functions init_board () and print_board () can be used
//                     in PA 6. We also review some basics of structs. We defined
//                     a Student struct to represent 3 attributes: name, ID, and
//                     GPA. We declared an array of Student structs.
// 
//          10/23/24 - Discussed strcmp () and how to deal with comparing strings in
//                     C. We implemented our own version of strcpy (i.e. my_strcpy ())
//                     that follows the same parameters as the <string.h> version.
// 
//          10/21/24 - Discussed C strings. Discussed and implemented 3 ways
//                     to declare strings. Discussed 2 ways to read strings from
//                     the keyboard: scanf () and fgets (). We discussed 2 ways
//                     to print strings to the screen: printf () and puts ().
//                     We worked with strcpy () and strcat ().
// 
//          10/18/24 - Completed implementing selection_sort (). Started discussing
//                     two dimensional (2-D) arrays and strings.
// 
//          10/16/24 - Started implementing selection sort (selection_sort()).
//                     We'll complete the algorithm on Fri, 10/18.
// 
//          10/11/24 - Implemented the binary search algorithm (binary_search ()). We discussed
//                     frequency tables/counting arrays for use with PA 5 Yahtzee.
// 
//          10/9/24 - Implemented the sequential search algorithm in the function 
//                    sequential_search (). We started implementing the algorithm for
//                    binary search.

#include "SearchesAndSorts.h"

int main(void)
{

	//srand((unsigned int)time(NULL));

	int id_numbers[100] = { 1111, 2222, 4444, 3333, 0001 }, found = 0, target = 4444,
		id_numbers2[50] = { 1111, 2222, 3333, 4444 };

	int matrix[3][5] = { {'~', '~'}, {'~'}};

	
	struct student s1;
	Student s2;
	Student arrStudents[100]; // an array of 100 student structs
	strcpy(arrStudents[0].name, "jane doe"); // intializes the name field
	                                        // of the first student in the array

	// the below 3 lines help with PA 6 - Battleship
	char p1_board[MAX_ROWS][MAX_COLS];
	init_board(p1_board, MAX_ROWS, MAX_COLS, '~');
	print_board(p1_board, MAX_ROWS, MAX_COLS);

	char str[5] = { 'a', 'b', 'c', 'd', '\0' } /* mutable memory */, 
		str2[100] = "cat" /* mutable memory */,
		* str3 = "dog" /* this is placed in immutable memory; it's a literal string	 */;

	//str2 = str; // pointer assignment - this is not copying strings
	strcpy(str2, "this is a string!"); // copies the right argument into the buffer
	                                   // identified by the left argument
	puts(str2); // show the string on the screen - places \n in the stream

	// first + last
	strcat(str2, str); // appends the right argument string to the end of the left
	                   // argument string
	puts(str2);

	printf("result of strcmp: %d\n", strcmp("catch", "dog"));
	printf("result of strcmp: %d\n", strcmp("dog", "cat"));
	printf("result of strcmp: %d\n", strcmp("cat", "cat"));

	puts(my_strcpy(str2, "a different string")); // added this call after class 10/23

	/*printf("str: %s\n", &str[1]); // we can start printing from a different position in the string!!!
	puts(str3); */// append stdout stream

	//printf("Enter a name: ");
	////scanf("%s", str2);
	//fgets(str2, 100, stdin);
	//puts(str2);

	//if (str2 == str3) // can't do; it's address comparison

	/*printf("Before selection sort:\n");
	print_array(id_numbers, 5);
	selection_sort(id_numbers, 5);
	printf("After selection sort:\n");
	print_array(id_numbers, 5);*/


	//printf("MEssage1\n");
	//system("pause");
	//system("cls");
	//printf("MEssage2\n");


	// Recall: we we pass arrays to functions by passing the address of the first element
	// in the array. The syntax array_name <==> &array_name[0]. Hence, arrays are not
	// copied when passed to functions. This means if we make a change to an array
	// that is a parameter, the changes are retained!!!
	//found = sequential_search(id_numbers, 5, target); 

	//printf("target sequential searched for %d reslt: %d\n", target, found);

	//found = binary_search(&id_numbers2[0] /*id_numbers2*/, 4, target);

	//printf("target binary searched for %d reslt: %d\n", target, found);
	
	return 0;
}