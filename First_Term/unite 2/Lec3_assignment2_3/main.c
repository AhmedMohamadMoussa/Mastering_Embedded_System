/*
 * main.c
 *
 *  Created on: Aug 29, 2024
 *      Author: User
 */
#include "stdio.h"
//EX5: C Program to Check Whether a Character is an Alphabet or not
/*
void main()
{
	// ( 65 --> 90  ) || ( A --> Z )
	// ( 97 --> 122 ) || ( a --> z )
	char character;
	printf("enter the charater:");
	fflush(stdin);fflush(stdout);
	scanf("%c",&character);
	int check_character = character;
	if(check_character>=65 && check_character<=90)
	{printf("the charater you entered is %c:",character);}
	else if(check_character>=97 && check_character<=122)
	{printf("the charater you entered is %c:",character);}
	else
	{printf("this is not a character");}
}
*/
//EX6: C Program to Calculate Sum of Natural Numbers
/*
void main()
{
	int num=0,result=0;
	printf("enter the number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	int var;
	for (var = 0; var <= num; var++)
	{
		result+=var;
	}
	printf("the result is :%d",result);
}
*/
//EX7: C Program to Find Factorial ofa Number
/*
void main()
{
	int num=0,result=1;
	printf("enter the number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	if(num >0)
	{
		int var;
		for (var = 1; var <= num; var++)
		{
			result*=var;
		}
		printf("the result is :%d",result);
	}
	else
	{printf("error");}
}
*/

//EX8: C Program to Make a Simple Calculator to Add, Subtract, Multiply or Divide Using switch...case

void main()
{
	char operation=0;
	printf("enter the operation :");
	fflush(stdin);fflush(stdout);
	scanf("%c",&operation);
	int num1=0,num2=0;
	printf("enter the 1st number :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1);
	printf("enter the 2nd number :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num2);
	switch (operation)
	{
		case '+':
			printf("the Add of two numbers is =%d",num1+num2);
			break;
		case '-':
			printf("the Subtract of two numbers is =%d",num1-num2);
			break;
		case '*':
			printf("the Multiply of two numbers is =%d",num1*num2);
			break;
		case '/':
			printf("the Divide of two numbers is =%d",num1/num2);
			break;
		default:
			break;
	}
}


