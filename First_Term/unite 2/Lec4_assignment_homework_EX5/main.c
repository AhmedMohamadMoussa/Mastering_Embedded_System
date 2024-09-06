/*
 * main.c
 *
 *  Created on: Sep 5, 2024
 *      Author: User
 */

/*
 * EX5
 * c program to search an element in array
 * */
#include <stdio.h>
int main()
{
	float array[10]={0};
	int loop1,limit,number;
	printf("enter the limitation of rows:");fflush(stdin);fflush(stdout);	scanf("%d",&limit);
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
	printf("enter the number which you search for:");fflush(stdin);fflush(stdout);	scanf("%d",&number);

	for( loop1 =0 ;loop1<limit ;loop1++ )
	{
		if(array[loop1]==number)
		{
			printf("the number which you search is %d and it is present in %d ",number,loop1+1);
			break;
		}
	}

	return 0;
}
