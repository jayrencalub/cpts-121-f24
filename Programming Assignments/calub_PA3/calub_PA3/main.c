/*****************************************************************
* Programmer: Jayren Calub
* Class: CptS 121, Fall 2024; Lab Section 18
* Programming Assignment: PA 3
* Date: September 20, 2024
* Description: This program reads student records and processes them
*			   to output specific values from multiple functions.
*****************************************************************/

#include "Processor.h"

int main(void) {

	/********************************VARIABLES**********************************/
	int class1 = 0, class2 = 0, class3 = 0, class4 = 0, class5 = 0, sum_class = 0;
	double gpa1 = 0, gpa2 = 0, gpa3 = 0, gpa4 = 0, gpa5 = 0, max_gpa = 0, min_gpa = 0, 
		   deviation1 = 0, deviation2 = 0, deviation3 = 0, deviation4 = 0, deviation5 = 0,
		   variance = 0, standard_deviation = 0,
		   age1 = 0, age2 = 0, age3 = 0, age4 = 0, age5 = 0,
		   sum_gpa = 0, mean_gpa = 0, sum_age = 0, mean_age = 0, mean_class = 0;

	FILE* infile = NULL, * outfile = NULL;

	// opening files
	infile = fopen("input.dat", "r");
	outfile = fopen("output.dat", "w");

	/*
	 FILE* input_stream = NULL, * output_stream;
	input_stream = fopen("txt file ", "type"); 		types: a = append, r = read, w = write.
	fscanf(input_stream, "%datatype", &variable);
	fclose(input_stream);

	output_stream = fopen(“txt file”, “type”);
	fprintf(output_stream, "text”, variables if needed);
	fclose(output_stream);
	*/
	/*******************************FILE READINGS********************************/
	
	// reading the records of student 1
	gpa1 = read_integer(infile); // need to do this so that the student id gets skipped
	gpa1 = read_double(infile);
	class1 = read_integer(infile);
	age1 = read_double(infile);

	// reading the records of student 2
	gpa2 = read_integer(infile); // need to do this so that the student id gets skipped
	gpa2 = read_double(infile);
	class2 = read_integer(infile);
	age2 = read_double(infile);

	// reading the records of student 3
	gpa3 = read_integer(infile); // need to do this so that the student id gets skipped
	gpa3 = read_double(infile);
	class3 = read_integer(infile);
	age3 = read_double(infile);

	// reading the records of student 4
	gpa4 = read_integer(infile); // need to do this so that the student id gets skipped
	gpa4 = read_double(infile);
	class4 = read_integer(infile);
	age4 = read_double(infile);

	// reading the records of student 5
	gpa5 = read_integer(infile); // need to do this so that the student id gets skipped
	gpa5 = read_double(infile);
	class5 = read_integer(infile);
	age5 = read_double(infile);

	// calculate the sums
	sum_gpa = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
	sum_class = calculate_sum(class1, class2, class3, class4, class5);
	sum_age = calculate_sum(age1, age2, age3, age4, age5);

	// calculate the means
	mean_gpa = calculate_mean(sum_gpa, 5);
	mean_class = calculate_mean(sum_class, 5);
	mean_age = calculate_mean(sum_age, 5);

	// calculate deviation of each GPA
	deviation1 = calculate_deviation(gpa1, mean_gpa);
	deviation2 = calculate_deviation(gpa2, mean_gpa);
	deviation3 = calculate_deviation(gpa3, mean_gpa);
	deviation4 = calculate_deviation(gpa4, mean_gpa);
	deviation5 = calculate_deviation(gpa5, mean_gpa);

	// calculate variance of the GPAs
	variance = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, 5);

	// calculate standard deviation of the GPAs
	standard_deviation = calculate_standard_deviation(variance);

	// determines minimum GPA
	min_gpa = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);

	// determines maximum GPA
	max_gpa = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);

	// writes the results into output.dat
	print_double(outfile, mean_gpa);
	print_double(outfile, mean_class);
	print_double(outfile, mean_age);
	print_double(outfile, standard_deviation);
	print_double(outfile, min_gpa);
	print_double(outfile, max_gpa);
	
	// closing files
	fclose(infile);
	fclose(outfile);

	return 0;
}
