/*
 * main.c
 *
 *  Created on: Sep 5, 2024
 *      Author: User
 */

/*
 * EX1
 * write a c program to find sum of two matrix of order 2*2
 * using multidimensional arrays where, elements of matrix are entered by user
 * */
#include <stdio.h>
int main()
{
	float matrix1[2][2];
	float matrix2[2][2];
	float matrix_sum[2][2] = { {0},{0} };
	int loop1,loop2;
	printf("the matrix 1 :\n");
	for( loop1 =0 ;loop1<2 ;loop1++ )
	{
		for (loop2 = 0; loop2 < 2; ++loop2)
		{
			printf("enter the element number [%d],[%d]:",loop1+1,loop2+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&matrix1[loop1][loop2]);
		}
	}
	printf("the matrix 2 :\n");
	for( loop1 =0 ;loop1<2 ;loop1++ )
	{
		for (loop2 = 0; loop2 < 2; ++loop2)
		{
			printf("enter the element number [%d],[%d]:",loop1+1,loop2+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&matrix2[loop1][loop2]);
		}
	}
	printf("the sum matrix\n");

	for( loop1 =0 ;loop1<2 ;loop1++ )
	{
		for (loop2 = 0; loop2 < 2; ++loop2)
		{
			matrix_sum[loop1][loop2]=matrix1[loop1][loop2] + matrix2[loop1][loop2];
		}
	}
	for( loop1 =0 ;loop1<2 ;loop1++ )
	{
		for (loop2 = 0; loop2 < 2; ++loop2)
		{
			printf("%.1f  ",matrix_sum[loop1][loop2]);
		}
		printf("\n");
	}
	return 0;
}
