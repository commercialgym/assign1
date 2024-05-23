/* assign1.cpp : contains the main loop requesting the user’s input, checking for
“X” or “Z” conditions(and reading the lines in the
    file if “Z”) and the call to parseUserInput() to determine the
    type of user input
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

#define NUM_ELEMENTS 20

int main(void)
{
    char userInput[NUM_ELEMENTS] = { 0 };

    //should it be case sensitive? ends when user enters X
    while (strcmpi(userInput, "X") != 0)
    {
        printf("Enter Student's Grade(s) >>> ");
        fgets(userInput, NUM_ELEMENTS, stdin);
        
        //remove newline
        size_t length = strlen(userInput);
        if (userInput[length - 1] == '\n')
        {
            userInput[length - 1] = '\0';
        }

        //do i need to check if userInput is X?

        //now check if the user entered a file
        size_t fileMode = 0;
        char fileName[NUM_ELEMENTS] = { 0 }; 
        if (strcspn(userInput, "Z") == fileMode)
        {
            int numParse = sscanf(userInput, "%*s %s", fileName);
            //magic number, do i need error codes?
            if (numParse == 0)
            {
                printf("Error Parsing File Name\n");
            }

            FILE* pInputTestFile = NULL;
            if ((pInputTestFile = fopen(fileName, "r")) == NULL)
            {
                printf("Cannot open file %s", fileName);
                continue;
            }

            while (fgets(userInput, NUM_ELEMENTS, pInputTestFile) != NULL)
            {
                //parse the input
                //the send the input to the assessGrade functions
            }

            //go back and check if these are the right functions to use in the case of error
            if (ferror(pInputTestFile))
            {
                printf("Error Reading %s\n", fileName);
                continue;
            }
            if (fclose(pInputTestFile) == EOF)
            {
                printf("Error Closing %s\n", fileName);
                continue;
            }
            clearerr(pInputTestFile);
        }

        //begin file i/o




    }



	return 0;

}


