/*
 * main.c
 *
 *  Created on: Sep 5, 2024
 *      Author: User
 */

/*
 * LAB: Calculate and Print the Transpose embedded_system
 * of 3x3 Matrix
 * */
#include <stdio.h>
int main()
{
	float number[3][3];
	float new_number [3][3];
	int loop1,loop2;
	for( loop1 =0 ;loop1<3 ;loop1++ )
	{
		for (loop2 = 0; loop2 < 3; ++loop2)
		{
			printf("enter the element number [%d],[%d]:",loop1+1,loop2+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&number[loop1][loop2]);
		}
	}
	printf("the normal matrix\n");

	for( loop1 =0 ;loop1<3 ;loop1++ )
	{
		for (loop2 = 0; loop2 < 3; ++loop2)
		{
			printf("%.1f  ",number[loop1][loop2]);
		}
		printf("\n");
	}

	printf("the Transpose matrix\n");

	for( loop1 =0 ;loop1<3 ;loop1++ )
	{
		for (loop2 = 0; loop2 < 3; ++loop2)
		{
			new_number[loop2][loop1]=number[loop1][loop2];
		}
	}
	for( loop1 =0 ;loop1<3 ;loop1++ )
	{
		for (loop2 = 0; loop2 < 3; ++loop2)
		{
			printf("%.1f  ",new_number[loop1][loop2]);
		}
		printf("\n");
	}
	return 0;
}
