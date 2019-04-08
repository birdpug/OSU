#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma warning(disable : 4996)

void fooA(int* iptr)
{
	printf("\n In fooA, the value pointed to is "); printf("%d", *iptr);
	printf("\n In, fooA, the memory address pointed to is "); printf("%p", iptr);
	*iptr += 5;
	printf("\n In fooA, the memory address pointed to is "); printf("%p", iptr);
}
void fooB(int* jptr)
{
	printf(" \n In, fooB, the Value pointed to is "); printf("%d", *jptr);
	printf("\n In, fooB, the memory address is "); printf("%p", jptr);
	*jptr -= 1;
	printf("\n In foob, the memory address is "); printf("%p", jptr);
}

int main()
{
	srand(time(NULL));
		int x = rand() % 11;
		printf(" In main the random Value is "); printf("%d", x);
		printf("\n In main the memory address is "); printf("%p", &x);

		fooA(&x);
		printf("\n After FooA and in main, the value is "); printf("%d", x);
		fooB(&x);
		printf("\n After FooB and in main, the value is "); printf("%d", x);
		printf("\n After FooB and in main the memory address is "); printf("%p", &x);

		scanf("%d", x);

	
	return 0;
}