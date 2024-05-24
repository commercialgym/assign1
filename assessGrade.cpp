
#include "assessGrade.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assessGrade.h"
#pragma warning(disable: 4996)

#define SUCCESS 0
#define ERROR -1
#define PASS 1
#define FAIL 2
#define SPECIAL_CASE 3



//letter grade to be converted
int assessGrade(char*)
{


	return 0;
}


//FUNCTION: assessGrade(double)
//DESCRIPTION: final grade worker bee, assesses whether the value passed was a passing
// grade, failing grade, or an invalid value
//PARAMETERS: double
//RETURNS: either a pass, fail, or error (meaning invalid grade)
int assessGrade(double finalGrade)
{
	if (finalGrade >= 0.00 && finalGrade <= 100.00)
	{
		if (finalGrade >= 54.50)
		{
			return PASS;
		}
		if (finalGrade < 54.50)
		{
			return FAIL;
		}
	}

	//else means that the input was invalid
	return ERROR;
}

//list of 5 integer grades
int assessGrade(int listOfGrades[])
{
	int gradeSum = 0;
	double finalGrade = 0;
	int numGrades = 5;

	for (int i = 0; i < numGrades; i++)
	{
		if (listOfGrades[i] >= 0 && listOfGrades[i] <= 100)
		{
			gradeSum += listOfGrades[i];
		}
		else
		{
			//if there is ever an input among the list that is not within range, immediately
			//quit this function and tell the parseUserInput function that there was an invalid input
			return ERROR;
		}
	}

	finalGrade = (double)gradeSum / (double)numGrades;
	//now send to worker bee to assess whether it is a pass or fail
	assessGrade(finalGrade);

	return 0;
}

//intelligently parses userInput
int parseUserInput(char* studentGrade)
{

	double finalGrade = 0;
	if (sscanf(studentGrade, "%f", &finalGrade) == 1)
	{
		//pass to the bee worker function
		assessGrade(finalGrade);
		return SUCCESS;
	}

	//magic number / initalize to 5 zeros
	int gradesList[5] = { 0 };
	//can be from 1-5 therefore check if sscanf parses at least one
	if (sscanf(studentGrade, "%d %d %d %d %d", &gradesList[0], &gradesList[1], &gradesList[2], &gradesList[3], &gradesList[4]) >=1)
	{
		assessGrade(gradesList);
		return SUCCESS;
	}

	size_t letterGradeLen = 3;
	size_t length = strlen(studentGrade);
	char letterGrade[4] = { 0 };

	if (length <= letterGradeLen)
	{
		strcpy(letterGrade, studentGrade);
		//am i passing correctly?
		assessGrade(letterGrade);
		return SUCCESS;
	}

	//else means user input
	return ERROR;

}
