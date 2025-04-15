#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen(), strcpy(), strncpy(), strcat()

char* my_strcpy(char *dest, const char *src);

int main(void) {
	char str[5] = { 'a', 'b', 'c', 'd', '\0' } /* mutuble memory */, str2[100] = "cat", 
		* str3 = "dog" /* immutable memory, literal string */;

	/*str2 = str;*/ // pointer assignment - not copying strings
	//strcpy(str2, "this is a string");
	puts(str2);

	// first + last
	strcat(str2, str);

	puts(str2);

	printf("result of strcmp: %d\n", strcmp("cat", "dog")); // -1 because c comes before d
	printf("result of strcmp: %d\n", strcmp("Cat", "cat")); // -1 because C comes before c
	printf("result of strcmp: %d\n", strcmp("dog", "cat")); // 1 because d comes after c
	printf("result of strcmp: %d\n", strcmp("cat!", "cat!")); // 0 because strings are equal

	my_strcpy(str2, "this is a string");
	printf("%s", str2);

	//printf("%s ", str3);
	//puts(str3); // append stdout stream

	//printf("Enter a name: ");
	//// scanf("%s", str2);
	//fgets(str2, 100, stdin);


	return 0;
}

char* my_strcpy(char* dest, const char* src) {
	int end = 0;

	for (int i = 0; src[i] != '\0'; ++i) {
		dest[i] = src[i];
		end = i;
	}

	dest[end] = '\0';

	return dest;
}