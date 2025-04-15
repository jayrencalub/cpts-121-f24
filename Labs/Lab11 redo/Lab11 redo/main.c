#include "lab11.h"

int main(void) {
	int num = 0;
	double sum = 0, average = 0, max = 0, min = 0;
	Employee payroll[200];
	FILE* infile = fopen("payroll.txt", "r");
	FILE* outfile = fopen("paid.txt", "w");

	read_records(infile, payroll, &num);
	compute_payment(payroll, num);
	sum = compute_sum(payroll, num);
	average = sum / num;
	find_max_and_min(payroll, &max, &min, num);
	print_payments(outfile, sum, average, max, min);

	fclose(infile);
	fclose(outfile);

	return 0;
}