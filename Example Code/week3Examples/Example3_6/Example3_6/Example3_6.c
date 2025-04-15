/**********************************************************************************************
* Programmer: Andrew S. O'Fallon                                                             *
* Class: CptS 121; Lab Section 0                                                             *
* Programming Assignment: Programming Project 6 in Chapter 3                                 *
*                         of Hanly/Koffman book                                              *
* Date:                                                                                      *
*                                                                                            *
* Description: This program calculates the speed of a runner for a mile                      *
*              in feet per second and meters per second. The program reads input             *
*              from a user. The input is the number of minutes and seconds                   *
*              that it took a runner to complete a mile. There are four entries              *
*              of times that need to be read, corresponding to four runners in the race.     *
*              The results of feet/sec and meters/sec calculations are displayed             *
*              to the screen.                                                                *
*                                                                                            *
* Relevant Formulas: 1 mile = 5,280 ft                                                       *
*                    1 km   = 3,282 ft                                                       *
*********************************************************************************************/

#include "example3_6.h"

/*************************************************************
* Function: run_app ()                                      *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description:                                              *
* Input parameters: None                                    *
* Returns: Nothing                                          *
* Preconditions: Start of the program.                      *
* Postconditions:                                           *
*************************************************************/

void run_app(void)
{
	/* Declare a variable to store the minute part of the times for each of the
	four runners */
	int runner1_min = 0, runner2_min = 0, runner3_min = 0, runner4_min = 0;

	/* Declare a variable to store the second part of the times for each of the
	four runners */
	double runner1_sec = 0.0, runner2_sec = 0.0, runner3_sec = 0.0, runner4_sec = 0.0;

	/* Store the total time, of each of the four runners, in seconds */
	double runner1_time_sec = 0.0, runner2_time_sec = 0.0, runner3_time_sec = 0.0,
		runner4_time_sec = 0.0;

	/* Store the speed of each of the four runners in feet per second (fps) */
	double runner1_fps = 0.0, runner2_fps = 0.0, runner3_fps = 0.0, runner4_fps = 0.0;

	/* Store the speed of each of the four runners in meters per second (mps) */
	double runner1_mps = 0.0, runner2_mps = 0.0, runner3_mps = 0.0, runner4_mps = 0.0;

	display_initial_message();


	/* Read the minute part of the time for each runner */
	runner1_min = read_minutes(1);
	runner2_min = read_minutes(2);
	runner3_min = read_minutes(3);
	runner4_min = read_minutes(4);
	printf("\n");

	/* Read the seconds part of the time for each runner */
	runner1_sec = read_seconds(1);
	runner2_sec = read_seconds(2);
	runner3_sec = read_seconds(3);
	runner4_sec = read_seconds(4);

	/* Convert each runner's total time from min and sec to just sec */
	runner1_time_sec = convert_time_to_seconds(runner1_min, runner1_sec);
	runner2_time_sec = convert_time_to_seconds(runner2_min, runner2_sec);
	runner3_time_sec = convert_time_to_seconds(runner3_min, runner3_sec);
	runner4_time_sec = convert_time_to_seconds(runner4_min, runner4_sec);

	/* Calculate the speed of each runner in feet per second */
	runner1_fps = calculate_feet_per_second(runner1_time_sec);
	runner2_fps = calculate_feet_per_second(runner2_time_sec);
	runner3_fps = calculate_feet_per_second(runner3_time_sec);
	runner4_fps = calculate_feet_per_second(runner4_time_sec);

	/* Calculate the speed of each runner in meters per second */
	runner1_mps = calculate_meters_per_second(runner1_time_sec);
	runner2_mps = calculate_meters_per_second(runner2_time_sec);
	runner3_mps = calculate_meters_per_second(runner3_time_sec);
	runner4_mps = calculate_meters_per_second(runner4_time_sec);

	/* Display the speeds of each of the runners (both mps and fps) */
	printf("\n********************\n");
	printf("Runner\tFPS\tMPS\n");
	printf("********************\n");
	display_speeds(runner1_fps, runner1_mps, 1);
	display_speeds(runner2_fps, runner2_mps, 2);
	display_speeds(runner3_fps, runner3_mps, 3);
	display_speeds(runner4_fps, runner4_mps, 4);
	printf("********************\n");
}

/*************************************************************
* Function: display_intial_message ()                       *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function displays the initial program   *
*              greeting.                                    *
* Input parameters: None                                    *
* Returns: Nothing                                          *
* Preconditions: Start of the program.                      *
* Postconditions: A welcome message is displayed.           *
*************************************************************/

void display_initial_message()
{
	printf("*** Welcome to the Penn Relays' mile race software ***\n\n");

	return;
}

/*************************************************************
* Function: read_minutes ()                                 *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function prompts the user for the       *
*              minutes part of the runner's time and scans  *
*              in the minutes.                              *
* Input parameters: The number of the runner.               *
* Returns: The minutes part of the runner's time as an      *
*          integer.                                         *
* Preconditions: Times of runners must be available.        *
* Postconditions: The minutes part of the runners time is   *
*                 returned.                                 *
*************************************************************/

int read_minutes(int runner_number)
{
	int number_minutes = 0;

	printf("Please enter runner %d's minutes part of time: ", runner_number);
	scanf("%d", &number_minutes);

	return number_minutes;
}

/*************************************************************
* Function: read_seconds ()                                 *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function prompts the user for the       *
*              seconds part of the runner's time and scans  *
*              in the seconds.                              *
* Input parameters: The number of the runner.               *
* Returns: The seconds part of the runner's time as a       *
*          double.                                          *
* Preconditions: The minutes part had to have been read in  *
*                already.                                   *
* Postconditions: The seconds part of the runners time is   *
*                 returned.                                 *
*************************************************************/

double read_seconds(int runner_number)
{
	double seconds = 0.0;

	printf("Please enter runner %d's seconds part of time: ", runner_number);
	scanf("%lf", &seconds);

	return seconds;
}

/*************************************************************
* Function: convert_time_to_seconds ()                      *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function converts the times from min    *
*              and sec to just sec.                         *
* Input parameters: The time in minutes and seconds.        *
* Returns: The runner's time in seconds only.               *
* Preconditions: The minutes and seconds of the time had to *
*                have been scanned in by the user.          *
* Postconditions: The runner's time in seconds only is      *
*                 returned.                                 *
*************************************************************/

double convert_time_to_seconds(int minutes, double seconds)
{
	double overall_seconds = 0.0;

	/* Need the time in seconds only in order to calculate ft/s and m/s */

	overall_seconds = SECONDS_PER_MINUTE * minutes + seconds;

	return overall_seconds;
}

/*************************************************************
* Function: calculate_feet_per_second ()                    *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calculates the speed of the    *
*              runner in feet/sec                           *
* Input parameters: The total time in seconds.              *
* Returns: The speed of the runner in feet per second.      *
* Preconditions: The total time of the runner in seconds.   *
* Postconditions: The speed of the runner in feet/second is *
*                 returned.                                 *
*************************************************************/

double calculate_feet_per_second(double time_in_seconds)
{
	double feet_per_second = 0.0;

	/* Calculate the speed of the runner in feet per second */

	feet_per_second = FEET_PER_MILE / time_in_seconds;

	return feet_per_second;
}

/*************************************************************
* Function: calculate_meters_per_second ()                  *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calculates the speed of the    *
*              runner in meters/sec                         *
* Input parameters: The total time in seconds.              *
* Returns: The speed of the runner in meters per second.    *
* Preconditions: The total time of the runner in seconds.   *
* Postconditions: The speed of the runner in meters/second  *
*                 is returned.                              *
*************************************************************/

double calculate_meters_per_second(double time_in_seconds)
{
	double meters_per_second = 0.0;

	/* Calculate the speed of the runner in meters per second */
	/* Use the conversion m/s =
	(1000 m/km) * (1 km/3,282 ft) * (5,280 ft/mi) * (1 mi/time_in_seconds) */

	meters_per_second = (METERS_PER_KM * (FEET_PER_MILE / FEET_PER_KM)) /
		time_in_seconds;

	return meters_per_second;
}

/*************************************************************
* Function: display_speeds ()                               *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function displays the speed of the      *
*              runner in meters/sec and feet/sec.           *
* Input parameters: The speed in ft/sec and m/s, runner num.*
* Returns: Nothing                                          *
* Preconditions: The speed calculations of the runner in    *
*                m/s and ft/s                               *
* Postconditions: The speed of the runner in ft/s and m/s   *
*                 is displayed.                             *
*************************************************************/

void display_speeds(double feet_per_second, double meters_per_second, int runner_num)
{
	/* Display the runner number and speeds in ft/s (fps) and m/s (mps) */

	printf("%6d\t%0.2lf\t%0.2lf\n", runner_num, feet_per_second, meters_per_second);

	return;
}