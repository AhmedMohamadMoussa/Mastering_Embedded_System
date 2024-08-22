/*
 * main.c
 *
 *  Created on: Aug 22, 2024
 *      Author: User
 */
#include  "stdio.h"
void main(int argc , char **argv)
{
	int num_1,num_2,num_3,choise;
	printf("Enter three values :");/*there are another method {  scanf("%d %d %d",&num_1,&num_2,&num_3);  }*/
	fflush(stdin);fflush(stdout);
	scanf("%d",&num_1);
	fflush(stdin);fflush(stdout);
	scanf("%d",&num_2);
	fflush(stdin);fflush(stdout);
	scanf("%d",&num_3);
	if (num_1>num_2 && num_1>num_3)
	{
		printf("The Maximum values :%d",num_1);
	}
	else if (num_2>num_1 && num_2>num_3)
	{
		printf("The Maximum values :%d",num_2);
	}
	else if (num_3>num_1 && num_3>num_2)
	{
		printf("The Maximum values :%d",num_3);
	}
	else
	{
		printf("There are equality between two or more number");
	}
}

