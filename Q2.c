/* CS261- Assignment 1 - Q.2*/
/* Name:Sami Talibi
 * Date: 4/15
 * Solution description: Attempts to shuffle a pointer around. Passes pointers to functions and prints statements about them.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)

int foo(int **a, int **b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
	int * pHolder = a;
	a = b;
	b = pHolder;
	/*("%p", pHolder);
	printf("\n");
	printf("%p", a);
	printf("\n");
	printf("%p", b);*/
    /*Decrement the value of integer variable c*/
	c--; 
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	srand(time(NULL));
	int x = rand() % 11;
	int y = rand() % 11;
	int z = rand() % 11;
    /*Print the values of x, y and z*/
	printf("The value of x: ");
	printf("%d", x);
	printf("\n");
	printf("The value of y: ");
	printf("%d", y);
	printf("\n");
	printf("The value of z: ");
	printf("%d", z);
	printf("\n");
    /*Call foo() appropriately, passing x,y,z as parameters*/
	z = foo(&x, &y, z);
    /*Print the values of x, y and z*/
	printf("The value of x: ");
	printf("%d", x);
	printf("\n");
	printf("The value of y: ");
	printf("%d", y);
	printf("\n");
	printf("The value of z: ");
	printf("%d", z);
	printf("\n");
    /*Print the value returned by foo*/
	printf("The value returned by foo: ");
	printf("%d", z);
    return 0;
	//1. The value returned is different than the integer Z. Calling foo returns an integer. Therefore, it will set a variable
	// as that number. It will be different than the integer passed as an argument.
	//2. They are not. Passing pointers is passing a copy of the memory address. The function can change them,
	//but they are only changing a copy .
}
    
    


