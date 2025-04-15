#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int count = 0;
	double num = 0, sum = 0, avg = 0;
	FILE* infile = NULL;
	FILE* outfile = NULL;

	infile = fopen("data.txt", "r");
	outfile = fopen("output.txt", "w");

	while (!feof(infile)) {
		fscanf(infile, "%lf", &num);
		sum += num;
		count++;
	}

	avg = sum / count;
	
	fprintf(outfile, "%.2lf", avg);
	
	return 0;
}