/* CS261- Assignment 1 - Q.1*/
/* Name:Sami Talibi
 * Date:4/15
 * Solution description: random students, with averages, max, min. uses malloc to create dynamic array
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#pragma warning(disable : 4996)

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student* study = malloc(10 * sizeof(struct student));
	/*Return the pointer*/
	return study; 
		}
     


void generate(struct student* students)
{
	/*Generate random and unique IDs and random scores for ten students,
IDs being between 1 and 10, scores between 0 and 100*/
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int y = rand() % 101;
		int x = rand() % 11;
		while (students[0].id == x || students[1].id == x || students[2].id == x || students[3].id == x || students[4].id == x || students[5].id == x || students[6].id == x || students[7].id == x || students[8].id == x || students[9].id == x)
		{
			x = rand() % 11;
		}
		students[i].id = x;
		students[i].score = y;
	}
}

	void output(struct student* students)
{
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	for (int i = 0; i < 10; i++)
	{
		printf("ID: ");
		printf("%d", students[i].id);
		printf(" ");
		printf("Score: ");;
		printf("%d", students[i].score);
		printf("\n");
	}

}


void summary(struct student* students)
{
     /*Compute and print the minimum, maximum and average scores of the 
ten students*/
	int max = students[0].score;
	int min = students[0].score;
	int average = 0;
	for (int i = 0; i < 10; i++)
	{
		if (min > students[i].score)
		{
			min = students[i].score;

		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (max < students[i].score)
		{
			max = students[i].score;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		average += students[i].score;
	}
	average = average / 10;
	printf("The average score is: ");
	printf("%d", average);
	printf("\n");
	printf("The maximum score is: ");
	printf("%d", max);
	printf("\n");
	printf("The minimum score is: ");
	printf("%d", min);
	printf("\n");
}

void deallocate(struct student* stud)
{
	realloc(stud, NULL);
}

int main()
{
    struct student* stud = NULL;

    /*Call allocate*/
	stud = allocate();
    /*Call generate*/
	generate(stud);
    /*Call output*/
	output(stud);
    /*Call summary*/
	summary(stud);
    /*Call deallocate*/
	assert(stud != NULL);
	deallocate(stud);
    return 0;
}