/*
 * main.c
 *
 *  Created on: Aug 24, 2024
 *      Author: User
 */
/*
	 * #####Home_work-1###############


	EX1:

	Write C Program to Print a Sentence

	i should see the Console as following:
	##########Console-output###
	C Programming
	###########################

	########################################################################

	EX2:

	Write C Program to Print a Integer Entered by a User
	i should see the Console as following:
	##########Console-output###
	Enter a integer: 25
	You entered: 25
	###########################

	########################################################################


	EX3:

	Write C Program to Add Two Integers

	i should see the Console as following:
	##########Console-output###
	Enter two integers: 12
	11
	Sum: 23
	###########################

	########################################################################


	EX4:

	Write C Program to Multiply two Floating Point Numbers
	i should see the Console as following:
	##########Console-output###

	###########################
	Enter two numbers: 2.4
	1.1
	Product: 2.640000
	########################################################################



	EX5:

	Write C Program to Find ASCII Value of a Character

	#########Console_output######
	Enter a character: G
	ASCII value of G = 71
	#############################


	########################################################################

	EX6:

	Write Source Code to Swap Two Numbers

	#########Console_output######
	Enter value of a: 1.20
	Enter value of b: 2.45

	After swapping, value of a = 2.45
	After swapping, value of b = 1.2
	#############################
	########################################################################

	EX7:
	it is an interview trick

	Write Source Code to Swap Two Numbers without temp variable.
	 *
 *
 * */

#include "stdio.h"
//Write Source Code to Swap Two Numbers
/*void main ()
{
	int num_1,num_2,num_change;
	printf("enter the first number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num_1);
	printf("enter the second number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num_2);
	num_change=num_1;
	num_1=num_2;
	num_2=num_change;
	printf("enter the first number:%d\n",num_1);
	printf("enter the second number:%d",num_2);

}*/




//Write Source Code to Swap Two Numbers without temp variable.
void main ()
{
	int num_1,num_2;
	printf("enter the first number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num_1);
	printf("enter the second number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num_2);
	num_1=num_1+num_2;
	num_2=num_1-num_2;
	num_1=num_1-num_2;
	printf("enter the first number:%d\n",num_1);
	printf("enter the second number:%d",num_2);

}
