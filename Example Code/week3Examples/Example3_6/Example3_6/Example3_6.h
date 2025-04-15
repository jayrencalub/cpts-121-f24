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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> /* Header file for scanf, printf */

#define SECONDS_PER_MINUTE 60.0 /* Number of seconds in a minute */
#define FEET_PER_MILE 5280.0    /* Number of feet in one mile */
#define FEET_PER_KM 3282.0      /* Number of feet in one kilometer */
#define METERS_PER_KM 1000.0    /* Number of meters in one kiometer */

/* These are the function prototypes; functions are described more by the comment
blocks before the function  */

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
void run_app(void);

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
void display_initial_message();

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
int read_minutes(int runner_number);

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
double read_seconds(int runner_number);

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
double convert_time_to_seconds(int minutes, double seconds);

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
double calculate_feet_per_second(double time_in_seconds);

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
double calculate_meters_per_second(double time_in_seconds);

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
void display_speeds(double feet_per_second, double meters_per_second, int runner_num);


