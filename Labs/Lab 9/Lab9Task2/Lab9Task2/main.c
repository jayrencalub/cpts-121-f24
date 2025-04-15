#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* my_strcpy(char* dest, const char* src);
char* my_strcat(char* destination, const char* source);
int my_strcmp(const char* s1, const char* s2);
int my_strlen(const char* s);

int main(void) {
	char str[100] = "hello!", str2[50] = "haha", str3[100] = "1", str4[10] = "hello", str5[10] = "hello!";
	
	// error will be thrown if the dest is smaller than the source
	//my_strcpy(str3, str);
	//puts(str3);

	// append - should be hello!haha
	my_strcat(str, str2);
	puts(str);

	//// compare
	//printf("%d\n", my_strcmp(str4, str5));

	//// length
	//printf("%d\n", my_strlen(str2));

	return 0;
}

char* my_strcpy(char* dest, const char* src) {
	int length = 0, end = 0;

	while (src[length] != '\0') {
		length++;
	}

	for (int i = 0; i < length + 1; ++i) {
		dest[i] = src[i];
		end = i;
	}

	dest[end] = '\0';

	return dest;
}

char* my_strcat(char* dest, const char* src) {
	int length = 0, end = 0;
	char temp[] = {'\0'};

	return dest;
}

int my_strcmp(const char* s1, const char* s2) {
	int result = 0, length = 0, s1_size = 0, s2_size = 0;

	while (s1[s1_size] != '\0') {
		s1_size++;
	}
	while (s2[s2_size] != '\0') {
		s2_size++;
	}
	if (s1_size > s2_size) {
		length = s1_size;
	}
	else {
		length = s2_size;
	}

	for (int i = 0; i < length; i++) {
		if (s1[i] < s2[i]) {
			result = -1;
			break;
		}
		if (s1[i] > s2[i]) {
			result = 1;
			break;
		}
	}

	return result;
}

int my_strlen(const char* s) {
	int count = 0;

	while (s[count] != '\0') {
		count++;
	}

	return count;
}