/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 1
* Date: September 6, 2024
* Description: This program calculates multiple equations and
*			   functions based on the user input of variables.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS // to be able to use scanf() with no errors
#include <stdio.h> // printf(), scanf()
#include <math.h> // sqrt()

/*******************************************CONSTANTS********************************************/

#define PI 3.1415926 // pi
#define G 6.67 * pow(10,-11) // gravitational constant

int main() {
	/*******************************************VARIABLES********************************************/

	// float-type variables
	double newton_force = 0, mass = 0, acceleration = 0, volume_cylinder = 0, radius = 0,
		   height = 0, mass1 = 0, mass2 = 0, gravity_distance = 0, celsius = 0, gravity_force = 0,
		   fahrenheit = 0, point_distance = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, y = 0, z = 0, x = 0;

	// character variables
	char plaintext_character = '\0', encoded_character = '\0'; // null character, ASCII code = 0;

	// integer varibles
	int offset = 0, a = 0;

	/********************************************EQUATIONS********************************************/
	
	//// Newton's Second Law of Motion
	//printf("Enter the mass and acceleration (both floating-point values) for use in Newton's Second law: "); // prompts the user for mass and acceleration values
	//scanf("%lf%lf", &mass, &acceleration); // takes in user input
	//newton_force = mass * acceleration; // calculates force
	//printf("Newton's Second Law: force = mass * acceleration = %lf * %lf = %lf\n", mass, acceleration, newton_force); // prints out calculation

	//// volume of a cylinder
	//printf("Enter the radius and height (both floating-point values) for use in the volume of a cylinder: "); // prompts the user for radius and height
	//scanf("%lf%lf", &radius, &height); // takes in user input
	//volume_cylinder = PI * (radius * radius) * height; // calculates volume of a cylinder
	//printf("Volume of a cylinder: pi * radius^2 * height = %lf * %lf^2 * %lf = %lf\n", PI, radius, height, volume_cylinder); // prints out calculation

	// character encoding
	printf("Enter offset (integer value) and character: "); // prompts the user for offset and character
	scanf("%d %c", &offset, &plaintext_character); // takes in user input, space at " %c to ignore white space from other prompts
	encoded_character = (char)offset + (plaintext_character - 'a') + 'A'; // calculates the encoded character
	printf("Encoded character = %d + (%c - 'a') + 'A' = %c\n", offset, plaintext_character, encoded_character); // prints out calculation
	// notes: with an offset of 1, plaintext_character of 'A' results in ', but plaintext_character of 'A' results in 'B'
	
	//// gravity
	//printf("Enter 2 masses and distance (all 3 are float-types): "); // prompts the user for masses and distance
	//scanf("%lf%lf%lf", &mass1, &mass2, &gravity_distance); // takes in user input
	//gravity_force = (G * mass1 * mass2) / pow(gravity_distance, 2); // calculates gravity
	//printf("Gravity: force = gravitational constant * mass1 * mass2 / distance^2 = %lf * %lf * %lf / (%lf * %lf) = %.15lf\n", // prints out calculation
	//			G, mass1, mass2, gravity_distance, gravity_distance, gravity_force);

	////// Fahrenheit to Celcius conversion
	//printf("Enter degrees in Fahrenheit: "); // prompts the user for degrees in F
	//scanf("%lf", &fahrenheit); // takes in user input
	//celsius = (fahrenheit - 32) / ((double) 9 / (double) 5);
	//printf("Fahrenheit to Celsius: celsius = (fahrenheit - 32) / (9 / 5) = (%lf - 32) / (9 / 5)) = %lf\n", fahrenheit, celsius);

	//// distance between two points
	//printf("Enter x and y coordinates (both float-type) for the first point: "); // prompts the user for the first point
	//scanf("%lf%lf", &x1, &y1); // takes in user input
	//printf("Enter x and y coordinates (both float-type) for the second point: "); // prompts the user for the second point
	//scanf("%lf%lf", &x2, &y2); // takes in user input
	//point_distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); // calculates the distance between the two points
	//printf("Distance between two points: sqrt((x1 - x2) ^ 2 + (y1 - y2) ^ 2) = \
	//									 sqrt((%lf - %lf) ^ 2 + (%lf - %lf) ^ 2) = %lf\n", 
	//									 x1, y1, x2, y2, point_distance); // prints out calculation
	//
	//// general equation
	//printf("Enter values for variables z, x (both float-type), and a (integer) in a general equation: "); // prompts the user for variables
	//scanf("%lf%lf%d", &z, &x, &a); // takes in user input
	//y = (89 / 27) - z * x + (double)a / (a % 2); // calculates y
	//printf("General equation: y = (89 / 27) - z * x / (a % 2) = 89 / 27) - %lf * %lf / (%d %% 2) = %lf", z, x, a, y); // prints out calculation
	
	return 0; // to show the program ran successfully
}