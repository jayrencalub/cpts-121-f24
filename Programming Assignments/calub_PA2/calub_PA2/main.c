/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 2
* Date: September 13, 2024
* Description: This program uses functions to calculate equations
*			   solved with values from user input.
*****************************************************************/

#include "equations.h"

int main(void) {

	/******************************VARIABLES******************************/

	// float-type variables
	double newton_force = 0, mass = 0, acceleration = 0, volume_cylinder = 0, radius = 0,
		   height = 0, mass1 = 0, mass2 = 0, gravity_distance = 0, celsius = 0, gravity_force = 0,
		   fahrenheit = 0, point_distance = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, y = 0, z = 0, x = 0;

	// character variables
	char plaintext_character = '\0', encoded_character = '\0'; // null character, ASCII code = 0;

	// integer varibles
	int offset = 0, a = 0;


	/******************************EQUATIONS******************************/

	// Newton's Second Law
	//printf("Enter the mass and acceleration (both floating-point values) for use in Newton's Second law: "); // prompts the user for mass and acceleration values
	//scanf("%lf%lf", &mass, &acceleration); // takes in user input
	//newton_force = calculate_newtons_2nd_law(mass, acceleration);
	//printf("Newton's Second Law: force = mass * acceleration = %lf * %lf = %.2lf\n", mass, acceleration, newton_force); // prints out calculation

	//// volume of a cylinder
	//printf("Enter the radius and height (both floating-point values) for use in the volume of a cylinder: "); // prompts the user for radius and height
	//scanf("%lf%lf", &radius, &height); // takes in user input
	//volume_cylinder = calculate_volume_cylinder(radius, height); // calculates volume of a cylinder
	//printf("Volume of a cylinder: pi * radius^2 * height = %lf * %lf^2 * %lf = %.2lf\n", PI, radius, height, volume_cylinder); // prints out calculation

	//// character encoding
	//printf("Enter offset (integer value) and character: "); // prompts the user for offset and character
	//scanf("%d %c", &offset, &plaintext_character); // takes in user input, space at " %c to ignore white space from other prompts
	//encoded_character = perform_character_encoding(plaintext_character, offset);; // calculates the encoded character
	//printf("Encoded character = %d + (%c - 'a') + 'A' = %c\n", offset, plaintext_character, encoded_character); // prints out calculation

	//// gravity
	//printf("Enter 2 masses and distance (all 3 are float-types): "); // prompts the user for masses and distance
	//scanf("%lf%lf%lf", &mass1, &mass2, &gravity_distance); // takes in user input
	//gravity_force = calculate_force(mass1, mass2, gravity_distance); // calculates gravity
	//printf("Gravity: force = gravitational constant * mass1 * mass2 / distance^2 = %lf * %lf * %lf / (%lf * %lf) = %.15lf\n", 
	//						 G, mass1, mass2, gravity_distance, gravity_distance, gravity_force); // prints out calculation
	//// note: not implementing the hundredths rule here because there are so many decimal places that the program will just print out 0.00

	//// Fahrenheit to Celcius conversion
	//printf("Enter degrees in Fahrenheit: "); // prompts the user for degrees in F
	//scanf("%lf", &fahrenheit); // takes in user input
	//celsius = fahrenheit_to_celsius(fahrenheit);
	//printf("Fahrenheit to Celsius: celsius = (fahrenheit - 32) / (9 / 5) = (%lf - 32) / (9 / 5)) = %.2lf\n", fahrenheit, celsius);

	//// distance between two points
	//printf("Enter x and y coordinates (both float-type) for the first point: "); // prompts the user for the first point
	//scanf("%lf%lf", &x1, &y1); // takes in user input
	//printf("Enter x and y coordinates (both float-type) for the second point: "); // prompts the user for the second point
	//scanf("%lf%lf", &x2, &y2); // takes in user input
	//point_distance = calculate_distance(x1, x2, y1, y2); // calculates the distance between the two points
	//printf("Distance between two points: sqrt((x1 - x2) ^ 2 + (y1 - y2) ^ 2) = \
	//								 sqrt((%lf - %lf) ^ 2 + (%lf - %lf) ^ 2) = %.2lf\n",
	//								 x1, y1, x2, y2, point_distance); // prints out calculation

	// general equation
	printf("Enter values for variables z, x (both float-type), and a (integer) in a general equation: "); // prompts the user for variables
	scanf("%lf%lf%d", &z, &x, &a); // takes in user input
	y = calculate_general_equation(a, x, z); // calculates y
	printf("General equation: y = (89 / 27) - z * x / (a % 2) = 89 / 27) - %lf * %lf / (%d %% 2) = %.2lf", z, x, a, y); // prints out calculation

	return 0;
}