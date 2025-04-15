/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: Lab1Task2
* Date: August 28, 2024 
* Description: This program prompts the user to enter 2 integers
*			   and 2 float values and performs several math
*              functions.
*****************************************************************/


#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings

#include <stdio.h> // necessary to use printf () and scanf ()

int main(void) // the starting point for all C programs
{
	// we need to request memory for 
	int number1_int = 0, number2_int = 0; // 2 variable declarations - reserves two memory blocks for integers and sets them to 0's
		double number1_float = 0.0, number2_float = 0.0; // reserves two memory blocks for 
	// numbers with high precision (floating-point)

	printf("Enter two integer values: "); // prompt/ask the user
	scanf("%d%d", &number1_int, &number2_int); // read the integers typed through the 
										  // keyboard - %d is for "decimal", i.e. integers

	printf("Enter two floating-point values: "); // prompt/ask the user
	scanf("%lf%lf", &number1_float, &number2_float); // read the integers typed through 
											// the keyboard - %lf is for "long float", i.e. 
											// double precision numbers
											
	// place all code for the subtasks / operations below here
	
	/********************************* Part B **************************************/
	// add number1_int and number2_int together and print the result as an integer value
	int int_sum = 0;
	int_sum = number1_int + number2_int;
	//printf("%d\n", number1_int + number2_int)
	printf("%d\n", int_sum);

	// subtraction
	double float_difference = 0;
	float_difference = number2_float - number1_float;
	printf("%lf\n", float_difference);

	// multiply
	double product = 0;
	product = number1_int * number1_float;
	printf("%lf\n", product);

	// division 1
	double quotient1 = 0;
	quotient1 = number1_int / number2_int;
	printf("%d\n", quotient1);
	printf("%lf\n", quotient1);

	// division 2
	double quotient2 = 0;
	quotient2 = number1_int / number2_float;
	printf("%d\n", quotient2);
	printf("%lf\n", quotient2);

	// casting
	double quotient3 = 0;
	quotient3 = (float)number1_int / number2_int;
	printf("%lf\n", quotient3);

	// modding
	int mod = 0;
	mod = (int)number1_float % (int)number2_float;
	printf("%d\n", mod);

	// even vs odd
	printf("%d\n", number1_int % 2);
	printf("%d\n", number2_int % 2);


	/********************************* Part B **************************************/
	int i = 0, r = 0, v = 0;
	printf("Enter I and R values: ");
	scanf("%d%d", &i, &r);
	v = i * r;
	printf("%d", v);

	/********************************* Part C **************************************/
	int voltage = 0, resistance = 0, power = 0;
	printf("\nEnter voltage and power values: ");
	scanf("%d%d", &voltage, &resistance);
	power = voltage * voltage / resistance;
	printf("%d", power);
	
	/********************************* Part D **************************************/


	return 0; // return a success status (value 0) indicating the program worked fine
} // end of the main () function