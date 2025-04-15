#ifndef SEARCHES_SORTS_H
#define SEARCHES_SORTS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h> // strlen (), strcpy (), strncpy (), strcat (), strncat (),
                    // strcmp (), strtok ()

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct student
{
    char name[100];
    int id;
    double gpa;
}Student;

// sequentially accesses each element
// and sets it to a value entered by the user
void init_array(int arr[], int size);
// sequentially accesses each element
// and prints the value
void print_array(int arr[], int size);

// precondtion: size <= MAX_SIZE
int sequential_search(int list[], int size, int target);
// precondtion: size <= MAX_SIZE; list must be ascending order
int binary_search(int list[], int size, int target);

// returns the address of the first element in the sorted array or list
// orders from smallest to largest
int* selection_sort(int list[], int size);

char* my_strcpy(char* dest, const char* src);

// the below declarations help w/ PA 6 - Battleship
void init_board(char board[][MAX_COLS], int row_size, int col_size, char symbol);
void print_board(char board[][MAX_COLS], int row_size, int col_size);

#endif