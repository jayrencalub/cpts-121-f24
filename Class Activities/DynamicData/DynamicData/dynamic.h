#ifndef DYNAMIC_H
#define DYNAMIC_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include <string.h>

typedef struct node {
	char grocery_item[50];
	struct node* link_btr; // self-referential struct
} Node;

Node* create_node(char* item);

// Node** indicates we're in an address of a pointer: head_btr from main()
int insert_at_front(Node** list_btr, char* item); // list operation

// precondition: list must not be empty
char* delete_at_front(Node** list_btr);

void print_list(Node* list_btr);

#endif