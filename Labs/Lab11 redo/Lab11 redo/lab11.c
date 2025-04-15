#include "lab11.h"

Employee* read_records(FILE* infile, Employee* arr, int* num_employees) {
	int index = 0;

	while (!feof(infile)) {
		char temp[100];

		// name
		fscanf(infile, "%s", &arr[index].name);
		strcat(arr[index].name, " ");
		fscanf(infile, "%s", &temp);
		strcat(arr[index].name, temp);

		// title
		fscanf(infile, " %c", &arr[index].title);

		// hours worked
		fscanf(infile, "%lf", &arr[index].hours_worked);

		// payrate
		fscanf(infile, "%lf", &arr[index].payrate);

		index++;
	}

	*num_employees = index;
}

Employee* compute_payment(Employee* arr, int num) {
	double weekly_hours = 0, ot_hours = 0;

	for (int i = 0; i < num; i++) {

		if (arr[i].hours_worked > 80) {
			ot_hours = arr[i].hours_worked - 80;

			if (arr[i].title == 'B') { // basic
				arr[i].payment = (80 * arr[i].payrate) + (1.5 * ot_hours * arr[i].payrate);
			}
			else { // manager
				arr[i].payment = (80 * arr[i].payrate) + (1.8 * ot_hours * arr[i].payrate);
			}
		}
		else {
			arr[i].payment = arr[i].hours_worked * arr[i].payrate;
		}
	}
}

double compute_sum(Employee* arr, int num) {
	double sum = 0;

	for (int i = 0; i < num; i++) {
		sum += arr[i].payment;
	}

	return sum;
}

void find_max_and_min(Employee* arr, double* max, double* min, int num) {
	*max = -999999;
	*min = 999999;

	for (int i = 0; i < num; i++) {
		if (arr[i].payment > *max) {
			*max = arr[i].payment;
		}
		if (arr[i].payment < *min) {
			*min = arr[i].payment;
		}
	}
}

void print_payments(FILE* outfile, double total, double average, double max, double min) {
	fprintf(outfile, "total: %.2lf\n", total);
	fprintf(outfile, "average: %.2lf\n", average);
	fprintf(outfile, "max: %.2lf\n", max);
	fprintf(outfile, "min: %.2lf", min);
}