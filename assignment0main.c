#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)

int main()
{
	printf("Please enter three numbers which would be the length of each side of a triangle.\n");
	int dog=0;
	int mouse=0;
	int rat=0;	
	scanf("%d", &dog);
	printf("Ok, Please enter a number that would be the length of the next side of your triangle.\n");
	scanf("%d", &mouse);
	printf("Ok, Please enter a number that would be the length of the next side of your triangle.\n");
	scanf("%d", &rat);

	double ferret = dog + mouse + rat;
	ferret = ferret / 2;
	dog = ferret - dog;
	mouse = ferret - mouse;
	rat = ferret - rat; 
	ferret = ferret * dog * mouse * rat;
	ferret = sqrt(ferret);
	printf("Ok, the area is ");

	printf("%d", ferret);
	scanf("%d", &rat);

	return 0;
}