#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void charges(int, double*, double*);
double round_money(double);

int main(void) {
	int hours = 0;
	double total = 0, average = 0, rounded_total = 0, rounded_average = 0;
	FILE* infile = NULL;
	FILE* outfile = NULL;
	infile = fopen("input.txt", "r");
	outfile = fopen("output.txt", "w");

	fscanf(infile, "%d", &hours);
	charges(hours, &total, &average);
	rounded_total = round_money(total);
	rounded_average = round_money(average);
	fprintf(outfile, "hours: %d\ntotal: %.2lf\naverage: %.2lf", hours, rounded_total, rounded_average);

	fclose(infile);
	fclose(outfile);

	return 0;
}

void charges(int hours, double* total, double* average) {
	if (hours > 10) {
		*total = 7.99 + (hours - 10) * 1.99;
	}
	else {
		*total = 7.99;
	}
	*average = (*total) / hours;
}

double round_money(double value) {
	value = value * 100;
	value = round(value);
	value = value / 100;
	return value;
}