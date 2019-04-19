/* CS261- Assignment 1 - Q.3*/
/* Name: Sami Talibi
 * Date: 4/15
 * Solution description: uses loops and if statements to make a character array lowercase. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable : 4996)

//checks to see if a letter is lower case. if it, then it changes it to the uppercase version
char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
	if (ch == 'a')
	{
		ch = 'A';
	}
	if (ch == 'b')
	{
		ch = 'B';
	}
	if (ch == 'c')
	{
		ch = 'C';
	}
	if (ch == 'd')
	{
		ch = 'D';
	}
	if (ch == 'e')
	{
		ch = 'E';
	}
	if (ch == 'f')
	{
		ch = 'F';
	}
	if (ch == 'g')
	{
		ch = 'G';
	}
	if (ch == 'h')
	{
		ch = 'H';
	}
	if (ch == 'i')
	{
		ch = 'I';
	}
	if (ch == 'j')
	{
		ch = 'J';
	}
	if (ch == 'k')
	{
		ch = 'K';
	}
	if (ch == 'l')
	{
		ch = 'L';
	}	
	if (ch == 'm')
	{
		ch = 'M';
	}	if (ch == 'n')
	{
		ch = 'N';
	}	if (ch == 'o')
	{
		ch = 'O';
	}	if (ch == 'p')
	{
		ch = 'P';
	}	if (ch == 'q')
	{
		ch = 'Q';
	}	if (ch == 'r')
	{
		ch = 'R';
	}	if (ch == 's')
	{
		ch = 'S';
	}	if (ch == 't')
	{
		ch = 'T';
	}	if (ch == 'u')
	{
		ch = 'U';
	}	if (ch == 'v')
	{
		ch = 'V';
	}	if (ch == 'w')
	{
		ch = 'W';
	}	if (ch == 'x')
	{
		ch = 'X';
	}	if (ch == 'y')
	{
		ch = 'Y';
	}	if (ch == 'z')
	{
		ch = 'Z';
	}
	return ch; 
}
//checks to see if a letter is upper case. if it is, then it changes it to the lowercase version.
char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/                          
	if (ch == 'A')
	{
		ch = 'a';
	}
	if (ch == 'B')
	{
		ch = 'b';
	}
	if (ch == 'C')
	{
		ch = 'c';
	}
	if (ch == 'D')
	{
		ch = 'd';
	}
	if (ch == 'E')
	{
		ch = 'e';
	}
	if (ch == 'F')
	{
		ch = 'f';
	}
	if (ch == 'G')
	{
		ch = 'g';
	}
	if (ch == 'H')
	{
		ch = 'h';
	}
	if (ch == 'I')
	{
		ch = 'i';
	}
	if (ch == 'J')
	{
		ch = 'j';
	}
	if (ch == 'K')
	{
		ch = 'k';
	}
	if (ch == 'L')
	{
		ch = 'l';
	}
	if (ch == 'M')
	{
		ch = 'm';
	}
	if (ch == 'N')
	{
		ch = 'n';
	}
	if (ch == 'O')
	{
		ch = 'o';
	}
	if (ch == 'P')
	{
		ch = 'p';
	}
	if (ch == 'Q')
	{
		ch = 'q';
	}
	if (ch == 'R')
	{
		ch = 'r';
	}
	if (ch == 'S')
	{
		ch = 's';
	}
	if (ch == 'T')
	{
		ch = 't';
	}
	if (ch == 'U')
	{
		ch = 'u';
	}
	if (ch == 'V')
	{
		ch = 'v';
	}
	if (ch == 'W')
	{
		ch = 'w';
	}
	if (ch == 'X')
	{
		ch = 'x';
	}
	if (ch == 'Y')
	{
		ch = 'y';
	}
	if (ch == 'Z')
	{
		ch = 'z';
	}
	return ch;
}
//uses a loop to count the length of character array. increments if there is a character.
int stringLength(char s[]) {
   /*Return the length of the string*/
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return i; 
}


void camelCase(char* word) {

	/*Convert to camelCase*/
	int l = stringLength(word); //gets lenght
	bool pugpuppy = false; // sets up bool for whether the string is appropriate
	{
		for (int i = 0; i < l; i++)
		{
			word[i] = toLowerCase(word[i]); //changes every letter possible to lowercase
		}//converts all to lowercase
		for (int i = 0; i < l; i++)
		{
			if (word[i] == ' ') //removes spaces
			{
				word[i] = '_';
			}
			
		}
		for (int i = 0; i < l; i++) //makes sure there is atleast some underscores
		{
			if (word[i] == '_')
			{
				pugpuppy = true;
				break;
			}
		}
		if (pugpuppy == true) //continue if there are underscores
		{
			pugpuppy = false; //sets false for another check
			for (int i = 0; i < l; i++)
			{
				if (word[i] == 'a' || word[i] == 'b' || word[i] == 'c' || word[i] == 'd' || word[i] == 'e' || word[i] == 'f' || word[i] == 'g' || word[i] == 'h' || word[i] == 'h' || word[i] == 'i' || word[i] == 'j' || word[i] == 'k' || word[i] == 'l' || word[i] == 'm' || word[i] == 'n' || word[i] == 'o' || word[i] == 'p' || word[i] == 'q' || word[i] == 'r' || word[i] == 's' || word[i] == 't' || word[i] == 'u' || word[i] == 'v' || word[i] == 'w' || word[i] == 'x' || word[i] == 'y' || word[i] == 'z')
				{
					pugpuppy = true; //if there are letters then we continue
					break;
				}
			}
		}
		if (pugpuppy == true) //continue if there are letters
		{
			for (int i = 0; i < l; i++)
			{
				if (word[i] == ' ' || word[i] == '!' || word[i] == '@' || word[i] == '#' || word[i] == '$' || word[i] == '%' || word[i] == '^' || word[i] == '&' || word[i] == '*' || word[i] == '(' || word[i] == ')' || word[i] == '-' || word[i] == '+' || word[i] == '=' || word[i] == '`' || word[i] == '~' || word[i] == '1' || word[i] == '2' || word[i] == '3' || word[i] == '4' || word[i] == '5' || word[i] == '6' || word[i] == '7' || word[i] == '8' || word[i] == '9' || word[i] == '10')
				{
					word[i] = '_'; //change all non alphabetic characters to underscore
				}
			}
			for (int i = 0; i < l; i++)
			{
				if (word[i] == '_') //after underscores make the next letter capital. also removes the underscore.
				{
					int d = i; //marks current location in the string
					word[i] = word[i + 1]; //changes underscore to next character
					word[i] = toUpperCase(word[i]); //capitalizes it
					i++; 
					while (i < l) //changes all the following letters
					{
						word[i] = word[i + 1];
						i++;
					}
					i = d; //go back to where we paused to carry out loop functions to edit rest of string
					if (word[i] == '_') // if we found an underscore move back one.
					{
						i = d - 1;
					}
				}
			}
			word[0] = toLowerCase(word[0]);//makes first letter lowercase.
		}
		else
		{
			printf("\n");
			printf("invalid input string");
			printf("\n");
		}
	}
}



		int main() {
			/*Read the string from the keyboard*/
			char dog[100];
			printf("Enter a string");
			printf("\n");
			scanf("%[^\n]s", dog);
			printf("\n");

			/*Call camelCase*/
			camelCase(dog);

			/*Print the new string*/
			printf("The string is: %s ", dog);
		

			return 0;
		}