/*
 * main.c
 *
 *  Created on: Aug 22, 2024
 *      Author: Ahmed Moussa
 */
#include  "stdio.h"
void main(int argc , char **argv)
{

	char choise ;
	float radius=0;
	float area=0;
	float circumference=0;

	printf("enter circle radius:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&radius);

	printf("write 'a' to print area , write 'c' to print circumference :");
	fflush(stdin);fflush(stdout);
	scanf("%c",&choise);

	if (choise== 'a')
	{
		area = 3.14*radius*radius;
		printf("area = %f",area);
	}
	else if (choise== 'c')
	{
		circumference = 2*3.14*radius;
		printf("circumference = %f",circumference);
	}
	else
	{
		printf("wrong choise");
	}

}


