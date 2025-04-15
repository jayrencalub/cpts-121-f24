#include "income.h"

int main(void) {
	double payment = 0, income = 0;
	char income_bracket = '\0';
	FILE* infile = NULL;

	infile = fopen("salaries.txt", "r");

	while (!feof(infile)) {
		payment = read_double(infile);
		income = calc_sum(income, payment);
	}

	fclose(infile);

	income_bracket = determine_tax_bracket(income);

	printf("%c", income_bracket);

	return 0;
}