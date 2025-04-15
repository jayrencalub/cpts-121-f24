#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_initials(char*, char*, char*);

int main(void) {
	char f = '\0', m = '\0', l = '\0';

	get_initials(&f, &m, &l);
	printf("%c\n%c\n%c", f, m, l);

	return 0;
}

void get_initials(char* first, char* middle, char* last) {
	printf("enter your first initial: ");
	scanf(" %c", &*first);
	printf("enter your middle initial: ");
	scanf(" %c", &*middle);
	printf("enter your last initial: ");
	scanf(" %c", &*last);
}