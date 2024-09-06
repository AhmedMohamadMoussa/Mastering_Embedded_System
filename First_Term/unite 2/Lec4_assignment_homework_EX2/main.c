/*
 * main.c
 *
 *  Created on: Sep 5, 2024
 *      Author: User
 */

/*
 * EX2
 * the program takes number of element from user (where, n is specified user),
 *  stores data in an array and calculates the average of those numbers
 * */
#include <stdio.h>
int main()
{
	float array[100],sum=0;
	int loop1,loop2,limit;
	printf("Enter the array limitation :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&limit);
	printf("Enter the array element :\n");
	for( loop1 =0 ;loop1<limit ;loop1++ )
	{
			printf("enter the element number [%d]:",loop1+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&array[loop1]);
			sum+=array[loop1];
	}
	printf("the average is  : %f",sum/limit);

	return 0;
}
