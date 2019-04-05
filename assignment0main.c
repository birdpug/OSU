#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
	printf("Please enter three numbers which would be the length of each side of a triangle.\n");
	int dog=0;
	int mouse=0;
	int rat=0;	
	scanf_s("%d", &dog);
	printf("Ok, Please enter a number that would be the length of the next side of your triangle.\n");
	scanf_s("%d", &mouse);
	printf("Ok, Please enter a number that would be the length of the next side of your triangle.\n");
	scanf_s("%d", &rat);

	int ferret = dog + mouse + rat;
	ferret = ferret / 2;
	dog = ferret - dog;
	mouse = ferret - mouse;
	rat = ferret - rat; 
	ferret = ferret * dog * mouse * rat;
	ferret = sqrt(ferret);
	printf("Ok, the area is ");

	printf("%d", ferret);


	return 0;
}