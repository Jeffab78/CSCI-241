/**
 *
 * Program: CSCI 241 Assignment 1
 * Author:  Jeff Byerly
 * z-ID:   z1860060
 * Date:   2/11/19
 *
 * This program tests functions for manipulating C strings.
 */

#include <iostream>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

//prototype functions
char* copy(char*, const char*,size_t);
char* reverseCopy(char*,const char*,size_t);
char* caseChangeCopy(char*,const char*,size_t);
char* replaceCopy(char*,const char*,char,char,size_t);
void read(char*, int);

int main()
   {
   const int WORDSIZE = 15;
   char words[][WORDSIZE] = {"sprightful", "reason to row", "New York", "Bolton", "Frida", ""};
   char word[WORDSIZE];

   // Test the copy function
   cout << "Copy \"sprightful\", should see \"sprightful\".\n";
   copy(word, words[0], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the copy function
   cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
   copy(word, "Supercalifragilisticexpialidocious", 5);
   cout << word << endl << endl;

   // Test the replaceCopy function
   cout << "Replace 'r' in \"reason to row\" with 's', should see \"season to sow\".\n";
   replaceCopy(word, words[1], 'r', 's', sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the replaceCopy function
   cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
   replaceCopy(word, "Supercalifragilistic", 'S', 'd', 5);
   cout << word << endl << endl;

   // Test the caseChangeCopy function
   cout << "Case change \"New York\", should see \"nEW yORK\".\n";
   caseChangeCopy(word, words[2], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the caseChangeCopy function
   cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
   caseChangeCopy(word, "Supercalifragilistic", 5);
   cout << word << endl << endl;

   // Test the reverseCopy function
   cout << "Reverse \"Bolton\", should see \"notloB\"\n";
   reverseCopy(word, words[3], sizeof(word) - 1);;
   cout << word << endl << endl;

   // Test the limit on the reverseCopy function
   cout << "Reverse \"cytogeneticists\", should see \"tsicitenegotyc\"\n";
   reverseCopy(word, "cytogeneticists", sizeof(word) - 1);;
   cout << word << endl << endl;

   cout << "Reverse \"Frida\", change case, and replace 'D' with 'Z', should see \"AZIRf\".\n";
   replaceCopy(caseChangeCopy(reverseCopy(word, words[4], sizeof(word) - 1), word, sizeof(word) - 1), word, 'D', 'Z', sizeof(word) - 1);
   cout << word << endl << endl;

   cout << "Enter your entire name: ";
   read(words[5], sizeof(words[5]));
   cout << words[5] << endl << endl;

   cout << "Reverse your name and change case.\n";
   cout << caseChangeCopy(reverseCopy(word, words[5], sizeof(word) - 1), word, sizeof(word) - 1) << endl;

   return 0;
   }

// Add your function definitions here
/***************************************************************
Function Name: copy
Use:  copies the source string into the destination string
Parameters:  takes in pointers to 2 arrays and an unsigned int
Returns: returns a pointer to the start of the new string
***************************************************************/
char* copy(char* destination, const char* source, size_t num)
{
	size_t i;
	for (i=0;source[i] != '\0' && i<num; i++)
	{ strcpy(destination,source);
	}
	
	destination[i]='\0';	
	return destination;
}


/***************************************************************
Function Name: reverseCopy
Use:  Copies the source string into the destination string in reverse order
Parameters:  takes in pointers to 2 arrays and an unsigned int
Returns: returns a pointer to the start of the new string
***************************************************************/
char* reverseCopy(char* destination, const char* source, size_t num)
{
	size_t length = strlen(source);
	int limit;
		
		if (length<num)
			limit = length-1;
		else
			limit = num-1;
	int i;		
	for (i=0; limit >= 0; i++,limit--)
		{
			destination[i]=source[limit];
		};
	destination[i]='\0';
	return destination;
}

/***************************************************************
Function Name: caseChangeCopy
Use:  copies the source string into the destination string and changes the case of every character in the new string.
Parameters:  takes in pointers to 2 arrays and an unsigned int
Returns: returns a pointer to the start of the new string
***************************************************************/
char* caseChangeCopy(char* destination,const char* source,size_t num)
{
	size_t i;
	size_t length = strlen(source);
	int limit;
		
		if (length<num)
			limit = length;
		else
			limit = num;
	
	char newstr[limit];
	for (i=0;source[i] != '\0' && i<num; i++)
	{ 
		newstr[i]=source[i];
		
	}
	
	for (i=0; (int)i<limit; i++)
		if(isupper(newstr[i]))
			newstr[i]=tolower(newstr[i]);
		else if (islower(newstr[i]))
			newstr[i]=toupper(newstr[i]);
	strcpy(destination,newstr);
	
	destination[i]='\0';
	return destination;

}
/***************************************************************
Function Name: replaceCopy
Use:  copies a source string into a new string and replaces specific letters with other letters.
Parameters:  takes in pointers to 2 arrays, 2 char variables and an unsigned int.
Returns: returns a pointer to the start of the new string
***************************************************************/
char* replaceCopy(char* destination,const char* source,char target,char replace,size_t num)
{
		size_t i;
	size_t length = strlen(source);
	int limit;
		
		if (length<num)
			limit = length;
		else
			limit = num;
	
	char newstr[limit];
	for (i=0;source[i] != '\0' && i<num; i++)
	{ 
		newstr[i]=source[i];
		
	}
	
	for (i=0; (int)i<limit; i++)
		if(newstr[i]==target)
			newstr[i]=replace;
	strcpy(destination,newstr);
	
	destination[i]='\0';
	return destination;
	
}

/***************************************************************
Function Name: read
Use:  
Parameters:  
Returns: nothing
***************************************************************/
void read(char* destination, int num)
{
	
	cin.getline(destination,num);
	
}

