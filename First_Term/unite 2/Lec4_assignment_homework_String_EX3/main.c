/*
 * main.c
 *  Created on: Sep 5, 2024
 *      Author: User
 */

/*
 * EX3
 * c program to reverse string without using library function
 * */
#include <stdio.h>
#include <string.h>
//#include <strings.h>
int main()
{
	//ahmed mohamad el sayed ibrahem moussa
	char Entered_statement1[100]={'\0'};
	char Entered_statement2[100]={"\0"};
	//Personal note : we should write this ( ={0} ) Because of random data
	printf("enter the statement\n");
	fflush(stdin);fflush(stdout);
	gets(Entered_statement1);
	int loop1=0 , loop2=strlen(Entered_statement1)-1;
	//Personal note : it is important to do { loop2=strlen(Entered_statement1)-1  }
	//if we do not put -1 ,it does not work
	// which strlen(Entered_statement1) , the last letter is \0
	// if we start with it in new array , it does not print any thing
	while(loop1<=strlen(Entered_statement1))
	{

		Entered_statement2[loop1]=Entered_statement1[loop2];
		loop1++;loop2--;
	}
	printf("%s",Entered_statement2);
	return 0;
	/*
	char str[100],temp;
	int i=0,j=0;
	printf("enter the value ");
	gets(str);
	j=strlen(str);
	while(i<j)
	{
		temp   = str[i];
		str[i] = str[j];
		str[j] = temp;
		j++;i--;
	}
	printf("the value is : %s",str);
	*/
}
