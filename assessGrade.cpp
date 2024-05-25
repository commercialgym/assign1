
#include "assessGrade.h"


//letter grade to be converted
int assessGrade(char* letterGrade)
{
	const int kEqual = 0;
	int gradeStatus = 0;

	if (strcmp(letterGrade, "X") == kEqual)
	{
		return IS_X;
	}
	if (strcmp(letterGrade, "A+") == kEqual)
	{
		double gradePlusA = 95;
		assessGrade(gradePlusA);
		return SUCCESS;
	}
	if (strcmp(letterGrade, "A") == kEqual)
	{
		double gradeA = 85;
		assessGrade(gradeA);
		return SUCCESS;
	}
	if (strcmp(letterGrade, "B+") == kEqual)
	{
		double gradePlusB = 77;
		assessGrade(gradePlusB);
		return SUCCESS;
	}
	if (strcmp(letterGrade, "B") == kEqual)
	{
		double gradeB = 72;
		assessGrade(gradeB);
		return SUCCESS;
	}
	if (strcmp(letterGrade, "C+") == kEqual)
	{
		double gradePlusC = 67;
		assessGrade(gradePlusC);
		return SUCCESS;
	}
	if (strcmp(letterGrade, "C") == kEqual)
	{
		double gradeC = 62;
		assessGrade(gradeC);
		return SUCCESS;
	}
	if (strcmp(letterGrade, "D") == kEqual)
	{
		double gradeD = 57;
		assessGrade(gradeD);
		return SUCCESS;
	}
	if (strcmp(letterGrade, "F") == kEqual)
	{
		double gradeF = 50;
		assessGrade(gradeF);
		return SUCCESS;
	}
	if (strcmp(letterGrade, "I") == kEqual)
	{
		printf("Student has Special Situation : I (Incomplete)\n");
		return SUCCESS;
	}
	if (strcmp(letterGrade, "Q") == kEqual)
	{
		printf("Student has Special Situation : Q (Withdrawal After Drop/Refund Date)\n");
		return SUCCESS;
	}
	if (strcmp(letterGrade, "AU") == kEqual)
	{
		printf("Student has Special Situation : AU (Audit Condition)\n");
		return SUCCESS;
	}
	if (strcmp(letterGrade, "DNA") == kEqual)
	{
		printf("Student has Special Situation : DNA (Did Not Attend)\n");
		return SUCCESS;
	}
	if (strcmp(letterGrade, "I/P") == kEqual)
	{
		printf("Student has Special Situation : I/P (In Process)\n");
		return SUCCESS;
	}

	else
	{
		printf("ERROR : Invalid Input\n");
	}
	//if it does not match any then there is an error
	return ERROR;
}


//FUNCTION: assessGrade(double)
//DESCRIPTION: final grade worker bee, assesses whether the value passed was a passing
// grade, failing grade, or an invalid value
//PARAMETERS: double
//RETURNS: either a pass, fail, or error (meaning invalid grade)
int assessGrade(double finalGrade)
{
	int gradeStatus = 0;
	if (finalGrade >= 0.00 && finalGrade <= 100.00)
	{
		if (finalGrade >= 54.50)
		{
			gradeStatus = PASS;
		}
		if (finalGrade < 54.50)
		{
			gradeStatus = FAIL;
		}
	}
	//if it in range it means that the input was invalid
	else
	{
		printf("ERROR : Invalid Input\n");
		return ERROR;
	}

	if (gradeStatus == ERROR)
	{
		printf("**ERROR : Invalid Input\n");
	}
	if (gradeStatus == PASS)
	{
		printf("Student Achieved %.2f %% which is a PASS condition.\n", finalGrade);
	}
	if (gradeStatus == FAIL)
	{
		printf("Student Achieved %.2f %% which is a FAIL condition.\n", finalGrade);
	}

	return SUCCESS;

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
			printf("ERROR : Invalid Input\n");
			return ERROR;
		}
	}

	finalGrade = (double)gradeSum / (double)numGrades;
	//now send to worker bee to assess whether it is a pass or fail
	assessGrade(finalGrade);

	return SUCCESS;

}

//intelligently parses userInput
int parseUserInput(char* studentGrade)
{
	size_t length = strlen(studentGrade);
	if (studentGrade[length - 1] == '\n')
	{
		studentGrade[length - 1] = '\0';
	}

	const int kMinParse = 1;
	int retCode = 0;

	double validInput = 0;
	double finalGrade = 0;
	if (sscanf(studentGrade, "%lf %lf", &finalGrade, &validInput) == kMinParse)
	{
		//pass to the bee worker function
		assessGrade(finalGrade);
		return SUCCESS;
	}

	//magic number / initalize to 5 zeros
	int gradesList[5] = { 0 };
	//can be from 1-5 therefore check if sscanf parses at least one
	if (sscanf(studentGrade, "%d %d %d %d %d", &gradesList[0], &gradesList[1], &gradesList[2], &gradesList[3], &gradesList[4]) >= kMinParse)
	{
		assessGrade(gradesList);
		return SUCCESS;
	}

	/*
	* Checking to see if the student Grade is less than or equal to 3 because the valid letter grades
	* never exceed 3 characters. this way, the assessGrade function that takes a char* does not have
	* to check for every single potential error string that the user enters
	*/
	size_t letterGradeLen = 3;
	length = strlen(studentGrade);
	char letterGrade[NUM_CHARS] = { 0 };

	if (length <= letterGradeLen)
	{
		if (assessGrade(studentGrade) == IS_X)
		{
			return IS_X;
		}
		return SUCCESS;
	}
	else
	{
		printf("ERROR : Invalid Input\n");
		return ERROR;
	}

}
