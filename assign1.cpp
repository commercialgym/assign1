/*
* FILE : assign1.cpp
* PROJECT : PROG1385 - A01 Overloaded Functions
* PROGRAMMER : Alexia Tu
* FIRST VERSION : 05/25/2024
* DESCRIPTION : Test harness for overloaded functions assessGrade(). Takes user input from
    * stdin or file i/o and passes it to parseUserInput which determines what type of input the user
    * entered, then calls an assessGrade function. If the user enters X, the program exits, if they 
    * enter Z followed by a file name, then it opens that file and passes each line read to parseUserInput.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
#include "assessGrade.h"


int main(void)
{
    char userInput[NUM_CHARS] = { 0 };
    //variables in the case of user choosing to enter a file
    char fileName[NUM_CHARS] = { 0 };

    //could use strcmpi to make it case insensitive
    while (strcmp(userInput, "X") != 0)
    {
        printf("Enter Student's Grade(s) >>> ");
        fgets(userInput, NUM_CHARS, stdin);

        /*strcspn returns num of chars up until a specific character. if the first char is Z, the
        num of characters should be zero, the value of kFileMode*/
        if (strcspn(userInput, "Z") == kFileMode)
        {
            if (sscanf(userInput, "%*s %s", fileName) != kNumToParse)
            {
                //printf("Error Parsing File Name\n");
                printf("**FILE I/O ERROR\n");
                continue;
            }

            FILE* pInputTestFile = NULL;
            if ((pInputTestFile = fopen(fileName, "r")) == NULL)
            {
                printf("**FILE I/O ERROR\n");
                //for all file i/o errors it's continue (not return) since we don't want the entire program to stop
                continue;
            }

            while (fgets(userInput, NUM_CHARS, pInputTestFile) != NULL)
            {
                //if the input file has an X, the program exits
                if (parseUserInput(userInput) == IS_X)
                {
                    return SUCCESS;
                }
            }

            //check for error after exiting the while loop, checks if there
            //was an error reading from the file
            if (ferror(pInputTestFile))
            {
                printf("**FILE I/O ERROR\n");
                continue;
            }
            if (fclose(pInputTestFile) == EOF)
            {
                printf("**FILE I/O ERROR\n");
                continue;
            }
            //just in case
            clearerr(pInputTestFile);
        }

        //checks values from stdin
        parseUserInput(userInput);
    }

    return SUCCESS;
}


