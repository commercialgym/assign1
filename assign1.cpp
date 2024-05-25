/* assign1.cpp : contains the main loop requesting the user’s input, checking for
“X” or “Z” conditions(and reading the lines in the
    file if “Z”) and the call to parseUserInput() to determine the
    type of user input
*/

#include "assessGrade.h"


int main(void)
{
    char userInput[NUM_CHARS] = { 0 };
    //variables in the case of user choosing to enter a file
    size_t fileMode = 0;
    char fileName[NUM_CHARS] = { 0 };
    double finalGrade = 0;
    int numParse = 0;
    int retCode = 0;

    //should it be case sensitive? ends when user enters X
    while (strcmpi(userInput, "X") != 0)
    {
        printf("Enter Student's Grade(s) >>> ");
        fgets(userInput, NUM_CHARS, stdin);

        //now check if the user entered a file 
        if (strcspn(userInput, "Z") == fileMode)
        {
            numParse = sscanf(userInput, "%*s %s", fileName);
            //magic number, do i need error codes?
            if (numParse == 0)
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

            //should I create a new variable for this ? i would have to change while condition
            while (fgets(userInput, NUM_CHARS, pInputTestFile) != NULL)
            {
                /*
                * Reason for IS_X is due to file i/o not accepting X as a valid input. Previously in assessGrade(char*),
                * i had it return SUCCESS if the letterGrade matched "X", reading from file didn't allow userInput in main to recieve 
                * the letter update since it's stuck in a while loop.
                */
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

        //checks "grades" from stdin
        parseUserInput(userInput);

    }

    return SUCCESS;
}


