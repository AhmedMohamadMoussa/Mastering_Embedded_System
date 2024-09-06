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
	float matrix[10][10]={{0},{0}};
	float new_matrix[10][10]={{0},{0}};
	int loop1,loop2,limit_row,limit_column;
	printf("enter the limitation of rows:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&limit_row);
	printf("enter the limitation of columns:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&limit_column);
	for( loop1 =0 ;loop1<limit_row ;loop1++ )
	{
		for (loop2 = 0; loop2 < limit_column; ++loop2)
		{
			printf("enter the element of matrix [%d],[%d]:",loop1+1,loop2+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&matrix[loop1][loop2]);
		}
	}
	printf("the normal matrix\n");
	for( loop1 =0 ;loop1<limit_row ;loop1++ )
	{
		for (loop2 = 0; loop2 < limit_column; ++loop2)
		{
			printf("%.1f  ",matrix[loop1][loop2]);
		}
		printf("\n");
	}

	for( loop1 =0 ;loop1<10 ;loop1++ )
	{
		for (loop2 = 0; loop2 < 10; ++loop2)
		{
			new_matrix[loop2][loop1]=matrix[loop1][loop2];
		}
	}
	printf("the new matrix\n");
	for( loop1 =0 ;loop1<limit_column ;loop1++ )
	{
		for (loop2 = 0; loop2 < limit_row; ++loop2)
		{
			printf("%.1f  ",new_matrix[loop1][loop2]);
		}
		printf("\n");
	}
	return 0;
}
