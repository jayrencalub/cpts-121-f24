#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double revenue(int t);
int predict(double revenue);

int main(void) {
	int years;

	years = predict(1000);
	printf("%d", years);

	return 0;
}

double revenue(int t) {
	return 203.265 * pow(1.071, t);
}

// revenue in thousands
int predict(double revenue) {
	double years;

	years = log(0.00491968 * revenue) / log(1.071);
	years = round(years);

	return (int)years;
}