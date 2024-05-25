
#include "assessGrade.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assessGrade.h"
#pragma warning(disable: 4996)


//letter grade to be converted
int assessGrade(char* letterGrade)
{
	const int kEqual = 0;
	int gradeStatus = 0;
	//do i need to remove a null character for lettergrade?
	if (strcmp(letterGrade, "A+") == kEqual)
	{
		double gradePlusA = 95;
		gradeStatus = assessGrade(gradePlusA);
		strcpy(letterGrade, "95");
		return gradeStatus;
	}
	if (strcmp(letterGrade, "A") == kEqual)
	{
		double gradeA = 85;
		gradeStatus = assessGrade(gradeA);
		strcpy(letterGrade, "85");
		return gradeStatus;
	}
	if (strcmp(letterGrade, "B+") == kEqual)
	{
		double gradePlusB = 77;
		gradeStatus = assessGrade(gradePlusB);
		strcpy(letterGrade, "77");
		return gradeStatus;
	}
	if (strcmp(letterGrade, "B") == kEqual)
	{
		double gradeB = 72;
		gradeStatus = assessGrade(gradeB);
		strcpy(letterGrade, "72");
		return gradeStatus;
	}
	if (strcmp(letterGrade, "C+") == kEqual)
	{
		double gradePlusC = 67;
		gradeStatus = assessGrade(gradePlusC);
		strcpy(letterGrade, "67");
		return gradeStatus;
	}
	if (strcmp(letterGrade, "C") == kEqual)
	{
		double gradeC = 62;
		gradeStatus = assessGrade(gradeC);
		strcpy(letterGrade, "62");
		return gradeStatus;
	}
	if (strcmp(letterGrade, "D") == kEqual)
	{
		double gradeD = 57;
		gradeStatus = assessGrade(gradeD);
		strcpy(letterGrade, "57");
		return gradeStatus;
	}
	if (strcmp(letterGrade, "F") == kEqual)
	{
		double gradeF = 50;
		gradeStatus = assessGrade(gradeF);
		strcpy(letterGrade, "50");
		return gradeStatus;
	}
	if (strcmp(letterGrade, "I") == kEqual)
	{
		strcpy(letterGrade, "I (Incomplete)");
		return SPECIAL_CASE;
	}
	if (strcmp(letterGrade, "Q") == kEqual)
	{
		strcpy(letterGrade, "Q (Withdrawal After Drop/Refund Date)");
		return SPECIAL_CASE;
	}
	if (strcmp(letterGrade, "AU") == kEqual)
	{
		strcpy(letterGrade, "AU (Audit Condition)");
		return SPECIAL_CASE;
	}
	if (strcmp(letterGrade, "DNA") == kEqual)
	{
		strcpy(letterGrade, "DNA (Did Not Attend)");
		return SPECIAL_CASE;
	}
	if (strcmp(letterGrade, "I/P") == kEqual)
	{
		strcpy(letterGrade, "I/P (In Process)");
		return SPECIAL_CASE;
	}

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
	int gradeStatus = 0;

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
	gradeStatus = assessGrade(finalGrade);

	return gradeStatus;
}

//intelligently parses userInput
int parseUserInput(char* studentGrade)
{
	const int kMinParse = 1;
	int retCode = 0;

		//magic number / initalize to 5 zeros
	int gradesList[5] = { 0 };
	//can be from 1-5 therefore check if sscanf parses at least one
	if (sscanf(studentGrade, "%d %d %d %d %d", &gradesList[0], &gradesList[1], &gradesList[2], &gradesList[3], &gradesList[4]) >= kMinParse)
	{
		retCode = assessGrade(gradesList);
		return retCode;
	}

	double finalGrade = 0;
	if (sscanf(studentGrade, "%lf", &finalGrade) == kMinParse)
	{
		//pass to the bee worker function
		retCode = assessGrade(finalGrade);
		return retCode;
	}


	size_t letterGradeLen = 3;
	size_t length = strlen(studentGrade);
	char letterGrade[NUM_CHARS] = { 0 };

	if (length <= letterGradeLen)
	{
		//strcpy(letterGrade, studentGrade);
		//am i passing correctly?
		retCode = assessGrade(studentGrade);
		return retCode;
	}

	//else means user input
	return ERROR;

}
