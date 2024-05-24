
#include "assessGrade.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assessGrade.h"
#pragma warning(disable: 4996)

#define SUCCESS 0
#define ERROR 0


//letter grade to be converted
int assessGrade(char*)
{


	return 0;
}

//final grade worker bee
int assessGrade(double)
{

	return 0;

}

//list of 5 integer grades
int assessGrade(int[])
{

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
