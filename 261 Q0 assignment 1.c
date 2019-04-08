/* CS261- Assignment 1 - Q. 0*/
/* Name: Sami Talbi
 * Date:4/8/19
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/

	printf("\n In fooA, the value pointed to is "); printf("%d", *iptr);
	printf("\n In, fooA, the memory address pointed to is "); printf("%p", iptr);
     /*Increment the value of the integer pointed to by iptr by 5*/
	*iptr += 5;
     /*Print the address of iptr itself*/
	printf("\n In fooA, the memory address pointed to is "); printf("%p", iptr);
    /*Dummy variable, ignore the warning*/
   int c=5;  
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/
	printf(" \n In, fooB, the Value pointed to is "); printf("%d", *jptr);
	printf("\n In, fooB, the memory address is "); printf("%p", jptr);
     /*Decrement the address by 1 pointed to by jptr using jptr */
	*jptr -= 1;
   
     /*Print the address of jptr itself*/
	printf("\n In foob, the memory address is "); printf("%p", jptr);
}


int main(){
    
    /*Declare an integer x and initialize it randomly to a value in [0,10] 
*/

	srand(time(NULL));
	int x = rand() % 11;
    /*Print the value and address of x*/
	printf(" In main the random Value is "); printf("%d", x);
	printf("\n In main the memory address is "); printf("%p", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*Print the value of x*/
	printf("\n After FooA and in main, the value is "); printf("%d", x);
    /*Call fooB() with the address of x*/
	fooB(&x);

    /*Print the value and address of x*/
	printf("\n After FooB and in main, the value is "); printf("%d", x);
	printf("\n After FooB and in main the memory address is "); printf("%p", &x);

	scanf("%d", x);
    return 0;
}


