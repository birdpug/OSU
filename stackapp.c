/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"
#pragma warning(disable : 4996)


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
			
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
*/
int isBalanced(char* s)
{
	if (s == NULL) return 1;
	char dog = nextChar(s), fin;
	DynArr* whale = newDynArr(50);
	while (dog != '\0')
	{
		if (isEmptyDynArr(whale) == 0)
		{
			fin = topDynArr(whale);
		}
		if (dog == '(')
		{
			pushDynArr(whale, dog);
		}
		if (dog == '[')
		{
			pushDynArr(whale, dog);
		}
		if (dog == '{')
		{
			pushDynArr(whale, dog);
		}
		if (fin == '(' && dog == ')')
		{
			if (isEmptyDynArr(whale))
			{
				return 0;
			}
			popDynArr(whale);
		}
		if (dog == ']' && fin == '[')
		{
			if (isEmptyDynArr(whale))
			{
				return 0;
			}
			popDynArr(whale);
		}
		if ( fin == '{'&& dog == '}')
		{
			if (isEmptyDynArr(whale))
			{
				return 0;
			}
			popDynArr(whale);
		}
		dog = nextChar(s);
	}
	if (isEmptyDynArr(whale))
	{
	deleteDynArr(whale);
		whale = NULL;
		return 1;
	}
	else
	{
		deleteDynArr(whale);
		whale = NULL;
		return 0;
	}
	/*if (s == NULL)
	{
		return 1;
	}
	
	int roundPreserver = 0;
	int checkround = 1;
	int checkcurly = 1;
	int checksquare = 1;
	int balance = 0;
	int tester=0; 
	//
	DynArr *whale;
	whale = newDynArr(50);
	char dog = nextChar(s), top;
	TYPE dreary = 'p';
	while (dog != '\0')
	{
		dog = nextChar(s);
		if (dog != '\0')
		{
			break;
		}
		if (dog == '(')
		{
			pushDynArr(whale, dog);
			printf("( entered");
			printf("\n");
			dreary = getDynArr(whale, tester);
			printf("%s", dreary);
			printf("\n");
			tester++;
		}
		if (dog == ')')
		{
			pushDynArr(whale, dog);
			printf("( entered");
			printf("\n");
			dreary = getDynArr(whale, tester);
			printf("%s", dreary);
			printf("\n");
			tester++;
		}
		if (dog == '{')
		{
			pushDynArr(whale, dog);
			printf("{ entered");
			dreary = getDynArr(whale, tester);
			printf("%s", dreary);
			printf("\n");
			tester++;
		}
		if (dog == '}')
		{
			pushDynArr(whale, dog);
			printf("} entered");
			dreary = getDynArr(whale, tester);
			printf("%s", dreary);
			printf("\n");
			tester++;
		}
		if (dog == '[')
		{
			pushDynArr(whale, dog);
			printf("[ entered");
			dreary = getDynArr(whale, tester);
			printf("%s", dreary);
			printf("\n");
			tester++;
		}
		if (dog == ']')
		{
			pushDynArr(whale, dog);
			printf("] entered");
			dreary = getDynArr(whale, tester);
			printf("%s", dreary);
			printf("\n");
			tester++;
		}

	}
	while (1)
	{
		int ender = 0;
		ender = isEmptyDynArr(whale);
		if (ender == 1)
		{
			break;
		}
;
		checkround = containsDynArr(whale, '(');
		removeDynArr(whale, '(');
		if (checkround == 0)
		{
			roundPreserver = 1;
		}
		if (checkround == 1)
		{
			checkround = containsDynArr(whale, ')');
			removeDynArr(whale, ')');
		}
		if (roundPreserver ==1)
		{
			checkround = 1;
			roundPreserver = 0;
		}
	}

	if (checkround ==1 && checkcurly ==1 && checksquare ==1)
	{
		balance = 1;
	}
	return balance; */
}


int main(int argc, char* argv[]) {

	char* s = argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n", s);
	else
		printf("The string %s is not balanced\n", s);

	return 0;
}

