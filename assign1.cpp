/* assign1.cpp : contains the main loop requesting the user’s input, checking for
“X” or “Z” conditions(and reading the lines in the
    file if “Z”) and the call to parseUserInput() to determine the
    type of user input
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

int main(void)
{
    char tester[10] = { 0 };
	char newTest[10] = { 0 };
	char bruh[11] = { 0 };


	fgets(tester, 9, stdin);

	size_t length = strlen(tester);

	//use the length (of string) - 1 to index the last element of the string
	if (tester[length - 1] == '\n')
	{
		tester[length - 1] = '\0';
	}

	int num = sscanf_s(tester, "%s %s", &newTest, (unsigned)sizeof(newTest), &bruh, (unsigned)sizeof(bruh));

	printf("you entered %s \n", newTest);

	//const char* FUCK = newTest;

	if (strcmp(newTest, "Z") == 0)
	{
		printf("tester is Z\n");
	}

	return 0;

}


