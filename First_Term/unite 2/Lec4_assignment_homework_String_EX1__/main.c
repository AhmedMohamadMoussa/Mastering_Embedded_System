/*
 * main.c
 *
 *  Created on: Sep 5, 2024
 *      Author: User
 */

/*
 * EX5
 * c program to find the frequency of characters in a string
 * */
#include <stdio.h>
#include <string.h>
#include <strings.h>
int main()
{
	char Entered_statement[100]={0};
	//Personal note : we should write this ( ={0} ) Because of random data
	printf("enter the statement\n");
	fflush(stdin);fflush(stdout);
	gets(Entered_statement);
	char Entered_character=0;
	printf("enter the character for searching \n");
	fflush(stdin);fflush(stdout);
	scanf("%c",&Entered_character);
	int loop=0,counter=0;
	for( loop = 0 ; loop < sizeof(Entered_statement) ; loop++ )
	{
		if( Entered_statement[loop] == Entered_character )
		{
			counter++;
		}
	}
	printf("the character is frequented for %d  \n",counter);
	return 0;
}
