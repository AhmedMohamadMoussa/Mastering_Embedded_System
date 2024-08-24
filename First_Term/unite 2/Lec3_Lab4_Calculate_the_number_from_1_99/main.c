/*
 * main.c
 *
 *  Created on: Aug 24, 2024
 *      Author: User
 */
#include  "stdio.h"
void main(int argc , char **argv)
{
	int var_new=0;
	for (int var = 0; var <= 99; ++var)
	{
		var_new=var_new+var;
	}
	printf("summation of values between 1 to 99:%d",var_new);
}

