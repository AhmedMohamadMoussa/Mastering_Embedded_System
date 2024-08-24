/*
 * main.c
 *
 *  Created on: Aug 24, 2024
 *      Author: User
 */
#include  "stdio.h"
void main(int argc , char **argv)
{
	int average=0;
	int studen_degree[5]={0};
	for (int student_no = 0; student_no <= 4; ++student_no)
	{
		printf("enter student no %d degree :",student_no+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&studen_degree[student_no]);
		average+=studen_degree[student_no];
	}
	printf("the average is :%d",(average/5));
}

