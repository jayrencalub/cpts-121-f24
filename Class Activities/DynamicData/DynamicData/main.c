#include "dynamic.h"

int main(int argc, char *argv[]) { // main(int argc, char *argv[])
	Node* head_btr = NULL; //create_node("milk")
	int success = 0;

	printf("argc: %d, %s, %s\n", argc, argv[0], argv[1]);

	success = insert_at_front(&head_btr, "bread");
	success = insert_at_front(&head_btr, "eggs");
	success = insert_at_front(&head_btr, "milk");

	print_list(head_btr);
	delete_at_front(&head_btr);
	print_list(head_btr);

	printf("success: %d, item: %s\n", success, head_btr->grocery_item);

	/*
	int num = 0, *btr = NULL;

	printf("How many integers would you like to allocate on the heap? ");
	scanf("%d", &num);

	while (num > 0) {
		// allocate space on the heap
		btr = malloc(sizeof(int)); // void * malloc(size_t Size)
		*btr = 50;
		printf("int: %d, %d bytes allocated\n", *btr, sizeof(int));
		num--;
	}
	*/

	return 0;
}