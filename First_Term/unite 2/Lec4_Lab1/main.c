/*
 * main.c
 *
 *  Created on: Sep 5, 2024
 *      Author: User
 */


#include <stdio.h>
void main()
{
	int Student_Degree[3];
	int loop;
	for( loop =0 ;loop<3 ;loop++ )
	{
		printf("enter the student %d degree :\n",loop+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&Student_Degree[loop]);
	}
	for( loop =0 ;loop<3 ;loop++ )
	{
		printf("the student %d degree is %d :\n",loop+1,Student_Degree[loop]);
	}
}
