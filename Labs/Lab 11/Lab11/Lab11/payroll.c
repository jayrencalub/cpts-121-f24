#include "payroll.h"

Employee* get_employees(FILE* infile, Employee* arr, int size) {
	char temp[100];
	
	for (int i = 0; !feof(infile); i++) {
		//fgets(arr[i].name, 100, infile);
		temp[0] = '\0';

		fscanf(infile, "%s", &arr[i].name);
		strcat(arr[i].name, temp);
		fscanf(infile, "%s", temp);
		strcat(arr[i].name, temp);

		fscanf(infile, " %c", &arr[i].title);
		fscanf(infile, "%lf", &arr[i].hours_worked);
		fscanf(infile, "%lf", &arr[i].payrate);
	}

	return arr;
}

Employee* calc_payments(Employee arr[], int size) {
	double weekly_hours = 0;

	for (int i = 0; i < size; i++) {
		
	}
}

double get_total(Employee *arr, int size) {
	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum += arr[i].payment;
	}
	
	return sum;
}

double get_average(double sum, int size) {
	return sum / size;
}

void get_max_and_min(Employee* arr, double* max, double* min, int size) {
	*max = -9999999, *min = 9999999;

	for (int i = 0; i < size; i++) {
		if (arr[i].payment > *max) {
			*max = arr[i].payment;
		}
		if (arr[i].payment < *min) {
			*min = arr[i].payment;
		}
	}
}

void print_data(FILE* outfile, double total, double average, double max, double min) {
	fprintf(outfile, "total: %.2lf\n", total);
	fprintf(outfile, "average: %.2lf\n", average);
	fprintf(outfile, "max: %.2lf\n", max);
	fprintf(outfile, "min: %.2lf\n", min);
}
