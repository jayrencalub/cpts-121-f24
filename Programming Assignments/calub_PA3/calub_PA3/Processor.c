/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 3
* Date: September 20, 2024
* Description: This program reads student records and processes them
*			   to output specific values from multiple functions.
*****************************************************************/

#include "Processor.h"

/*************************************************************
* Function: read_double()
* Date Created: September 19, 2024
* Date Last Modified:
* Description: This function reads double values from a file
* Input parameters: FILE* infile: the file that is being read
* Returns: double of the value being read
* Preconditions: the file must be open
* Postconditions: a double value is returned
*************************************************************/
double read_double(FILE* infile) {
	double value = 0.0;
	fscanf(infile, "%lf", &value);
	return value;
}

/*************************************************************
* Function: read_integer()
* Date Created: September 19, 2024
* Date Last Modified:
* Description: This function reads integer files from a file
* Input parameters: FILE* infile: the file that is being read
* Returns: integer of the value being read
* Preconditions: the file must be open
* Postconditions: an int value is returned
*************************************************************/
int read_integer(FILE* infile) {
	int value = 0;
	fscanf(infile, "%d", &value);
	return value;
}

/*************************************************************
* Function: calculate_sum()
* Date Created: September 19, 2024
* Date Last Modified:
* Description: This function calculates the sum of 5 numbers
* Input parameters: double number1: first number
*					double number2: second number
*					double number3: third number
*					double number4: fourth number
*					double number5: fifth number
* Returns: double of the sum
* Preconditions: there must be 5 arguments when calling the function
* Postconditions: a double is returned
*************************************************************/
double calculate_sum(double number1, double number2, double number3, double number4, double number5) {
	return number1 + number2 + number3 + number4 + number5;
}

/*************************************************************
* Function: calculate_mean()
* Date Created: September 19, 2024
* Date Last Modified:
* Description: This function calculates the average of a number
* Input parameters: double sum: the numerator of the equation
*					double number: the denominator of the equation
* Returns: double of the average
* Preconditions: arguments must be numerical values (0 is okay)
* Postconditions: a double is returned
*************************************************************/
double calculate_mean(double sum, int number) {
	if (number == 0) {
		return -1.0;
	}
	else {
		return sum / number;
	}
}

/*************************************************************
* Function: calculate_deviation()
* Date Created: September 19, 2024
* Date Last Modified:
* Description: This function calculates the deviation of a number
*			   from the mean
* Input parameters: double number: the desired number to get deviation
*					double mean: the mean number
* Returns: a double of the difference between number and mean
* Preconditions: arguments must be numerical values
* Postconditions: a double is returned
*************************************************************/
double calculate_deviation(double number, double mean) {
	return number - mean;
}

/*************************************************************
* Function: calculate_variance
* Date Created: September 19, 2024
* Date Last Modified:
* Description: This function calculates the mean of the sum of
*			   each squared deviation
* Input parameters: double deviation1: first deviation
*					double deviation2: second deviation
*					double deviation3: third deviation
*					double deviation4: fourth deviation
*					double deviation5: fifth deviation
*					int number: the denominator
* Returns: a double of the variance
* Preconditions: arguments must be numerical values (number can be 0)
* Postconditions: returns a double
*************************************************************/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) {
	double variance = pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2);
	variance = calculate_mean(variance, number);
	return variance;
}

/*************************************************************
* Function: calculate_standard_deviation()
* Date Created: September 19, 2024
* Date Last Modified:
* Description: This function calculates the standard deviation
*			   by taking the square root of the variance
* Input parameters: double variance: the variance
* Returns: a double of the standard deviation
* Preconditions: variance must not be negative
* Postconditions: returns a double
*************************************************************/
double calculate_standard_deviation(double variance) {
	return sqrt(variance);
}

/*************************************************************
* Function: find_max()
* Date Created: September 19, 2024
* Date Last Modified:
* Description: This function finds the biggest number out of five
* Input parameters: double number1: first number
*					double number2: second number
*					double number3: third number
*					double number4: fourth number
*					double number5: fifth number
* Returns: double of the biggest number
* Preconditions: arguments must be numerical values
* Postconditions: returns a double
*************************************************************/
double find_max(double number1, double number2, double number3, double number4, double number5) {
	double max = number1;

	if (number2 > max) {
		max = number2;
	}
	if (number3 > max) {
		max = number3;
	}
	if (number4 > max) {
		max = number4;
	}
	if (number5 > max) {
		max = number5;
	}

	return max;
}

/*************************************************************
* Function: find_min(double number1, double number2, double number3, double number4, double number5)
* Date Created: September 19, 2024
* Date Last Modified:
* Description: This function finds the smallest number out of five
* Input parameters: double number1: first number
*					double number2: second number
*					double number3: third number
*					double number4: fourth number
*					double number5: fifth number
* Returns: double of the smallest number
* Preconditions: arguments must be numerical values
* Postconditions: returns a double
*************************************************************/
double find_min(double number1, double number2, double number3, double number4, double number5) {
	double min = number1;

	if (number2 < min) {
		min = number2;
	}
	if (number3 < min) {
		min = number3;
	}
	if (number4 < min) {
		min = number4;
	}
	if (number5 < min) {
		min = number5;
	}

	return min;
}

/*************************************************************
* Function: print_double()
* Date Created: September 19, 2024
* Date Last Modified:
* Description: This function prints a double precision number
*			   (in the hundredths place) onto a file
* Input parameters: FILE* outfile: the file being printed on
*					double number: the number being printed
* Returns:
* Preconditions: the file must be open
* Postconditions:
*************************************************************/
void print_double(FILE* outfile, double number) {
	fprintf(outfile, "%.2lf\n", number);
}