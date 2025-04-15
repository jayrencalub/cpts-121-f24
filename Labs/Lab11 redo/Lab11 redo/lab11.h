#ifndef LAB11_H
#define LAB11_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct employee {
	char name[100]; // employee's name - last, first
	char title; // title 'B' or 'M'
	double hours_worked; // total number of hours worked
	double payrate; // pay rate per hour
	double payment; // total payment for the pay period – you will compute!
} Employee;

Employee* read_records(FILE* infile, Employee* arr, int* num_employees);
Employee* compute_payment(Employee* arr, int num);
double compute_sum(Employee* arr, int num);
void find_max_and_min(Employee* arr, double* max, double* min, int num);
void print_payments(FILE* outfile, double total, double average, double max, double min);

#endif

