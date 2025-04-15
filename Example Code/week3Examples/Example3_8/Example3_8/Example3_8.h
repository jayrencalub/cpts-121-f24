/*************************************************************************
* Programmer: Andrew O'Fallon                                           *
* Class: CptS 121; Lab Section 0                                        *
* Programming Assignment: Programming Project 8 in Chapter 3            *
*                         of Hanly/Koffman book                         *
* Date:                                                                 *
*                                                                       *
* Description: This program calculates the cyclist's constant rate      *
*              of acceleration and determines how long it will take     *
*              for a cyclist to stop moving. The program displays the   *
*              rate of acceleration and amount of time it takes the     *
*              cyclist to stop moving.                                  *
*                                                                       *
* Relevant Formulas: a = (vf - vi) / t, where a is acceleration,        *
*                                       vi is initial velocity,         *
*                                       vf is final velocity,           *
*                                       t is time interval              *
************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> /* Header file for scanf, printf */

#define MIN_PER_HOUR 60.0      /* There are 60 minutes in one hour */
#define METERS_PER_MILE 1608.0 /* Approximately 1608 meters per mile */
#define SEC_PER_HOUR 3600.0    /* 3600 seconds in one hour */
#define SEC_PER_MIN 60.0       /* 60 seconds in one minute */

/* List the function prototypes for the program */\
/* The descriptions for each of the functions can be seen in a comment block
above each function definition */
/*************************************************************
* Function: run_app ()                                      *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description:                                              *
* Input parameters: None                                    *
* Returns: Nothing                                          *
* Preconditions: Start of program.                          *
* Postconditions:                                           *
*************************************************************/
void run_app(void);

void beginning_program_message(void);

/*************************************************************
* Function: get_initial_velocity ()                         *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function gets the initial velocity      *
*              from the user. The initial velocity is the   *
*              velocity that needed to calculate the        *
*              constant rate of acceleration.               *
* Input parameters: None                                    *
* Returns: The initial velocity as a double.                *
* Preconditions: None                                       *
* Postconditions: The initial velocity in mi/hr is returned.*
*************************************************************/
double get_initial_velocity(void);

/*************************************************************
* Function: get_final_velocity ()                           *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function gets the final velocity        *
*              from the user. The final velocity is the     *
*              velocity that needed to calculate the        *
*              constant rate of acceleration.               *
* Input parameters: None                                    *
* Returns: The final velocity.                              *
* Preconditions: None                                       *
* Postconditions: The final velocity in mi/hr is returned.  *
*************************************************************/
double get_final_velocity(void);

/*************************************************************
* Function: get_time_interval ()                            *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function gets the initial time interval *
*              from the user. The time interval represents  *
*              the amount of time it took the cyclist to    *
*              slow from the initial velocity to the final  *
*              velocity. The final velocity is not a stop.  *
* Input parameters: None                                    *
* Returns: The initial time interval.                       *
* Preconditions: None                                       *
* Postconditions: The time interval in minutes is returned. *
*************************************************************/
double get_time_interval(void);

/*************************************************************
* Function: calculate_acceleration_mi_hour ()               *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calculates the constant rate   *
*              of acceleration in mi/hr^2.                  *
* Input parameters: The initial and final velocities,       *
*                   and initial time interval.              *
* Returns: The constant acceleration in mi/hr^2.            *
* Preconditions: The final and initial velocities           *
*                and initial_time_interval                  *
* Postconditions: The acceleration has been calculated in   *
*                 mi/hr^2.                                  *
*************************************************************/
double calculate_acceleration_mi_hour(double init_velocity, double final_velocity, double amount_time);

/*************************************************************
* Function: calculate_acceleration_m_sec ()                 *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calculates the constant rate   *
*              of acceleration in m/s^2.                    *
* Input parameters: The initial and final velocities,       *
*                   and initial time interval.              *
* Returns: The constant acceleration in m/s^2.              *
* Preconditions: The final and initial velocities           *
*                and initial_time_interval                  *
* Postconditions: The acceleration has been calculated in   *
*                 m/s^2.                                    *
*************************************************************/
double calculate_acceleration_m_sec(double init_velocity, double final_velocity, double amount_time);

/*************************************************************
* Function: calculate_time_to_stop ()                       *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calculates the total time it   *
*              takes a cyclist to role to a stop on a flat  *
*              surface, given an initial velocity.          *
* Input parameters: The initial and final velocities,       *
*                   constant acceleration, and initial      *
*                   time interval.                          *
* Returns: The total time to stop as a double.              *
* Preconditions: The final and initial velocities,          *
*                acceleration, and initial_time_interval    *
* Postconditions: The total time it takes the cyclist to    *
*                 role to a stop.                           *
*************************************************************/
double calculate_time_to_stop(double init_velocity, double final_velocity, double acceleration,
	   double initial_time_interval);

/*************************************************************
* Function: display_acceleration_and_time ()                *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function displays acceleration of the   *
*              cyclist in mi/hr^2 and m/s^2. The function   *
*              also displays the total time to stop.        *
* Input parameters: The acceleration in mi/hr^2 and m/s^2   *
*                   and the total time to stop.             *
* Returns: Nothing                                          *
* Preconditions: The acceleration and time to stop need to  *
*                already been calculated.                   *
* Postconditions: Display of the accelerations and time to  *
*                 stop.                                     *
*************************************************************/
void display_acceleration_and_time(double acceleration_mi_hours, double acceleration_m_sec,
	 double time_to_stop);


