#include "payroll.h"

int main(void) {
	int length = 0;
	double total = 0, average = 0, min = 0, max = 0;
	Employee payroll[200];
	FILE* infile = NULL;
	FILE* outfile = NULL;
	
	infile = fopen("payroll.txt", "r");
	outfile = fopen("paid.txt", "w");

	get_employees(infile, payroll, 4);

	for (int i = 0; i < 4; i++) {
		printf("%s\n", payroll[i].name);
		printf("%c\n", payroll[i].title);
		printf("%lf\n", payroll[i].hours_worked);
		printf("%lf\n\n", payroll[i].payrate);
	}

	fclose(infile);
	fclose(outfile);

	return 0;
}