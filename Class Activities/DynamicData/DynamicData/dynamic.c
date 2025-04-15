#include "dynamic.h"

Node* create_node(char* item) {
	Node* mem_btr = malloc(sizeof(Node));

	if (mem_btr != NULL) {
		// we allocated space for a Node successfully
		strcpy(mem_btr->grocery_item, item);
		mem_btr->link_btr = NULL;
	}

	return mem_btr;
}

// Node** indicates we're in an address of a pointer: head_btr from main()
int insert_at_front(Node** list_btr, char* item) {
	Node* mem_btr = create_node(item);
	int success = 0;

	if (mem_btr != NULL) {
		// we allocated space successfully
		success = 1;
		if (*list_btr == NULL) { // the list is empty
			*list_btr = mem_btr;
		}
		else { // list is not empty
			mem_btr->link_btr = *list_btr;
			*list_btr = mem_btr;
		}
	}

	return success;
}

char* delete_at_front(Node** list_btr) {
	Node* temp_btr = *list_btr;  // temp_btr is referring to the first node in the list
	char data[50] = "";

	strcpy(data, (*list_btr)->grocery_item);

	// update head_btr through list_btr - set it to next node in sequence
	*list_btr = temp_btr->link_btr;

	free(temp_btr);
}

void print_list(Node* list_btr) {
	printf("-->");
	while (list_btr != NULL) {
		printf("%s --> ", list_btr->grocery_item);
		list_btr = list_btr->link_btr;
	}
	putchar("\n");
}