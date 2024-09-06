/*
 * main.c
 *
 *  Created on: Sep 5, 2024
 *      Author: User
 */

/*
 * Lab:Calculate Polynomial embedded_system
 * Value for a Set of Inputs
 */
/*
 * the program works
 * correctly, however it
 * appears that code size
 * contains many
 * repeated sections, each
 * section for each value. If
 * the number of values
 * increases code size
 * increases.
 * Alternative solve it
 * using Arrays and
 * Loops
 * */
#include <stdio.h>
void main()
{
	float number[5]={5,16,22,3.5,15};
	int loop;
	for( loop =0 ;loop<5 ;loop++ )
	{
		printf("the result for polynomial number %d is : %.2f \n",
				loop+1 , 5*number[loop]*number[loop]+3*number[loop]+2);
	}
}
