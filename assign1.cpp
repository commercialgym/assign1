/* assign1.cpp : contains the main loop requesting the user’s input, checking for
“X” or “Z” conditions(and reading the lines in the
    file if “Z”) and the call to parseUserInput() to determine the
    type of user input
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assessGrade.h"
#pragma warning(disable: 4996)


int main(void)
{
    char userInput[NUM_CHARS] = { 0 };
    //variables in the case of user choosing to enter a file
    size_t fileMode = 0;
    char fileName[NUM_CHARS] = { 0 };
    int retCode = 0;
    double finalGrade = 0;
    int numParse = 0;

    //should it be case sensitive? ends when user enters X
    while (strcmpi(userInput, "X") != 0)
    {
        printf("Enter Student's Grade(s) >>> ");
        fgets(userInput, NUM_CHARS, stdin);
        
        //remove newline
        size_t length = strlen(userInput);
        if (userInput[length - 1] == '\n')
        {
            userInput[length - 1] = '\0';
        }

        //do i need to check if userInput is X?

        //now check if the user entered a file 
        if (strcspn(userInput, "Z") == fileMode)
        {
            numParse = sscanf(userInput, "%*s %s", fileName);
            //magic number, do i need error codes?
            if (numParse == 0)
            {
                //printf("Error Parsing File Name\n");
                printf("**FILE I/O ERROR\n");
            }

            FILE* pInputTestFile = NULL;
            if ((pInputTestFile = fopen(fileName, "r")) == NULL)
            {
                printf("**FILE I/O ERROR\n");
                continue;
            }

            //should I create a new variable for this ? i would have to change while condition
            while (fgets(userInput, NUM_CHARS, pInputTestFile) != NULL)
            {
                retCode = parseUserInput(userInput);
                //need to parse to float in order to print their grade
                numParse = sscanf(userInput, "%lf", &finalGrade); // come back to change return code for this
                if (retCode == ERROR)
                {
                    printf("**ERROR : Invalid Input\n");
                }
                if (retCode == PASS)
                {
                    printf("Student Achieved %.2f %% which is a PASS condition.\n", finalGrade);
                }
                if (retCode == FAIL)
                {
                    printf("Student Achieved %.2f %% which is a FAIL condition.\n", finalGrade);
                }
                if (retCode == SPECIAL_CASE)
                {
                    printf("Student has Special Situation : %s\n", userInput);
                }
            }

            //go back and check if these are the right functions to use in the case of error
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
            clearerr(pInputTestFile);
        }

        //repeat of above
        retCode = parseUserInput(userInput);
        //need to parse to float in order to print their grade
        numParse = sscanf(userInput, "%lf", &finalGrade); // come back to return code for this
        if (retCode == ERROR)
        {
            printf("**ERROR : Invalid Input\n");
        }
        if (retCode == PASS)
        {
            printf("Student Achieved %.2lf %% which is a PASS condition.\n", finalGrade);
        }
        if (retCode == FAIL)
        {
            printf("Student Achieved %.2lf %% which is a FAIL condition.\n", finalGrade);
        }
        if (retCode == SPECIAL_CASE)
        {
            printf("Student has Special Situation : %s\n", userInput);
        }

    }

	return 0;

}


