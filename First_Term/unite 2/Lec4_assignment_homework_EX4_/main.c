/*
 * main.c
 *
 *  Created on: Sep 5, 2024
 *      Author: User
 */

/*
 * EX3
 * this program  asked user to enter a matrix ( size of matrix is specified by user )
 * and this program finds the transpose of that matrix and displays it .
 * */
#include <stdio.h>
int main()
{
	float array[10]={0};
	float new_array[10]={0};
	int loop2;
	int loop1,limit,no_element_change,change;
	printf("enter the limitation of rows:");fflush(stdin);fflush(stdout);	scanf("%d",&limit);
	printf("enter the no_element_change:");	fflush(stdin);fflush(stdout);	scanf("%d",&no_element_change);
	printf("enter the change:");			fflush(stdin);fflush(stdout);	scanf("%d",&change);
	for( loop1 =0 ;loop1<limit ;loop1++ )
	{
			printf("enter the element of matrix [%d]:",loop1+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&array[loop1]);
	}
	printf("the normal array\n");
	for( loop1 =0 ;loop1<limit ;loop1++ )
	{
			printf("%.1f  ",array[loop1]);
	}
	printf("\n");

	for( loop1 =0 ;loop1<no_element_change ;loop1++ )
	{
		if(loop1== (no_element_change-1))
		{
			new_array[loop1]=change;

			for (loop2 = loop1; loop2 <= limit+1; ++loop2)
			{
				new_array[loop2+1]=array[loop2];
			}
			break;

		}
		new_array[loop1]=array[loop1];
	}
	printf("the new array\n");
	for( loop1 =0 ;loop1<limit+1 ;loop1++ )
	{
			printf("%.1f  ",new_array[loop1]);

		printf("\n");
	}
	return 0;
}
