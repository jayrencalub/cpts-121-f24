#include "income.h"

double read_double(FILE* infile){
	double num = 0;
	fscanf(infile, "%lf", &num);
	return num;
}

double calc_sum(double sum, double num){
	return sum + num;
}

char determine_tax_bracket(double income){
	char bracket = '\0';

	if (income < 15000) {
		bracket = 'l';
	}
	else if (income >= 15000 && income <= 200000) {
		bracket = 'm';
	}
	else if (income > 200000) {
		bracket = 'h';
	}

	return bracket;
}