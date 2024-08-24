/*
 * main.c
 *
 *  Created on: Aug 24, 2024
 *      Author: User
 */
#include  "stdio.h"
void main(int argc , char **argv)
{
	for (int num_1 = 0; num_1 <= 9; ++num_1)
	{

		for (int num_2 = num_1; num_2 <=9 ; ++num_2)
		{
			printf("%d",num_2);
		}
		printf("\n");
	}
}


