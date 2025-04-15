/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 2
* Date: September 13, 2024
* Description: This program uses functions to calculate equations
*			   solved with values from user input.
*****************************************************************/

#include "equations.h"

// IMPORTANT: print answers in hundreths place

/*************************************************************
* Function: calculate_newtons_2nd_law(double mass, double acceleration)
* Date Created: September 13, 2024
* Date Last Modified: September 13, 2024
* Description: This function calculates the equation for Newton's 2nd Law
*			   using parameters set by the user.
* Input parameters: double mass: the mass that the user inputted.
*					double acceleration: the acceleration the user inputted.
* Returns: A double that shows the answer of the equation.
* Preconditions: There must be values for mass and acceleration.
* Postconditions: The product of mass * acceleration is returned.
*************************************************************/

double calculate_newtons_2nd_law(double mass, double acceleration) {
	return mass * acceleration;
}

/*************************************************************
* Function: calculate_volume_cylinder(double radius, double height)
* Date Created: September 13, 2024
* Date Last Modified: September 13, 2024
* Description: This function calculates the volume of a cylinder
*			   using radius and height inputted by the user.
* Input parameters: double radius: the radius of the cylinder
*					double height: the height of the cylinder
* Returns: a double that shows the volume of the equation
* Preconditions: there must be values for radius and height
* Postconditions: The volume of the cylinder is returned.
*************************************************************/

double calculate_volume_cylinder(double radius, double height) {
	return PI * (radius * radius) * height;
}

/*************************************************************
* Function: perform_character_encoding(char plaintext_character, int offset)
* Date Created: September 13, 2024
* Date Last Modified: September 13, 2024
* Description: This function takes a character and changes its ASCII value
*			   based on user input.
* Input parameters: char plaintext_character: the character that is getting changed
*					int offset: the value that shifts the ASCII value of the character
* Returns: a char of the modified character
* Preconditions: the value for plaintext_character must be a char and the value for
*				 offset must be an int
* Postconditions: the encoded character is returned
*************************************************************/

char perform_character_encoding(char plaintext_character, int offset) {
	return (char)offset + (plaintext_character - 'a') + 'A';
}

/*************************************************************
* Function: calculate_force(double mass1, double mass2, double distance)
* Date Created: September 13, 2024
* Date Last Modified: September 13, 2024
* Description: This function calulates the gravitational force using values
*			   from user input.
* Input parameters: double mass1: the mass of the first object
*					double mass2: the mass of the second object
*					double distance: the distance between the two objects
* Returns: a double of the calculated equation of force
* Preconditions: there must be values for the variables
* Postconditions: the calculated force is returned
*************************************************************/

double calculate_force(double mass1, double mass2, double distance) {
	return (G * mass1 * mass2) / pow(distance, 2);
}

/*************************************************************
* Function: fahrenheit_to_celsius(double fahrenheit)
* Date Created: September 13, 2024
* Date Last Modified: September 13, 2024
* Description: This function converts the user-inputted Fahrenheit
*			   to Celsius
* Input parameters: double fahrenheit: degrees in fahrenheit
* Returns: a double of the temperature in Celsius
* Preconditions: there must be a value for fahrenheit
* Postconditions: celcius is returned
*************************************************************/

double fahrenheit_to_celsius(double fahrenheit) {
	return (fahrenheit - 32) / ((double)9 / (double)5);
}

/*************************************************************
* Function: calculate_distance(double x1, double x2, double y1, double y2)
* Date Created: September 13, 2024
* Date Last Modified: September 13, 2024
* Description: This function calculates the distance between
*			   two user-inputted points
* Input parameters: double x1: the value of x in the first point
*					double x2: the value of x in the second point
*					double y1: the value of y in the first point
*					double y2: the value of y in the second point
* Returns: a double of the distance between the two points
* Preconditions: there must be a value for each coordinate value
* Postconditions: returns the distance between the two points
*************************************************************/

double calculate_distance(double x1, double x2, double y1, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

/*************************************************************
* Function: calculate_general_equation(int a, double x, double z)
* Date Created: September 13, 2024
* Date Last Modified: September 13, 2024
* Description: This function calculates the answer to a general
*			   equation using user-inputted values
* Input parameters: int a: the value of a in the equation
*					double x: the value of x in the equation
*					double z: the value of z in the equation
* Returns: a double of the answer of the equation
* Preconditions: the argument for a must be an integer, while
*				 the arguments for x and z must be doubles
* Postconditions: returns the answer of the equation
*************************************************************/

double calculate_general_equation(int a, double x, double z) {
	return (89 / 27) - z * x + (double)a / (a % 2);
}