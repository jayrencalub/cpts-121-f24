#ifndef PAYROLL_H
#define PAYROLL_H

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

Employee* get_employees(FILE* infile, Employee* arr, int size);
Employee* calc_payment(Employee* arr, int size);
double get_total(Employee *arr, int size);
double get_average(double sum, int size);
void get_max_and_min(Employee* arr, double* max, double* min, int size);
void print_data(FILE* outfile, double total, double average, double max, double min);

#endif

