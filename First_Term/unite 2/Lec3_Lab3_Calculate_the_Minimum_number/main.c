/*
 * main.c
 *
 *  Created on: Aug 22, 2024
 *      Author: User ( ahmed moussa )
 */
#include  "stdio.h"
void main(int argc , char **argv)
{
	int num_1,num_2;
	printf("Enter the values :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num_1);
	fflush(stdin);fflush(stdout);
	scanf("%d",&num_2);
	printf("the maximum number is :%d",(num_1>num_2)? num_1:num_2 );
}

