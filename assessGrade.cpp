/*
* FILE : assessGrade.cpp
* PROJECT : PROG1385 - A01 Overloaded Functions
* PROGRAMMER : Alexia Tu
* FIRST VERSION : 05/25/2024
* DESCRIPTION : contains the three overloaded assessGrade functions definitions as well as
	* the parseUserInput definition. From the parseUserInput, the type of input is checked in order
	* from a double, int array, and char*. The function that takes the double is the worker bee. The other
	* two functions either converts their arguments' data into a double to pass to the assessGrade worker bee 
	* or returns an error back to parseUserInput if it is an invalid grade. Besides any ERROR printing, the 
	* only two functions that print outputs are the assessGrade(char*) - which may print a special case situation -
	* and the assessGrade(double) function - which prints a final grade and status.
	*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
#include "assessGrade.h"


//FUNCTION: assessGrade(char*)
//DESCRIPTION: Takes a c style string from parseUserInput, then checks to see if it is a match to any 
// requirement defined letter grades. If it is X, it returns a status code that allows the program to end. 
// If it's a letter grade then it will call the worker bee
//PARAMETERS: char* letterGrade (which will be 3 or less meaningful characters in length due to the fact that parseUserInput
// will never send anything longer than that.)
//RETURNS: either a status code for input being X, SUCCESS, or ERROR
int assessGrade(char* letterGrade)
{
	const int kEqual = 0;

	if (strcmp(letterGrade, "X") == kEqual)
	{
		return IS_X;
	}
	if (strcmp(letterGrade, "A+") == kEqual)
	{
		double gradePlusA = 95;
		assessGrade(gradePlusA);
		/*each if () statement needs to return something in order to leave the function or else the
		else statement at the end of the function will print that there's an error every time*/
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
		printf("**ERROR : Invalid Input\n");
	}
	return ERROR;
}


//FUNCTION: assessGrade(double)
//DESCRIPTION: final grade worker bee, assesses whether the value passed was a passing
// grade, failing grade, or an invalid value. Can be used from the other two assessGrade() 
// functions or be called directly from parseUserInput. Prints the final grade status for 
// all valid grade inputs.
//PARAMETERS: double finalGrade
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
		printf("**ERROR : Invalid Input\n");
		return ERROR;
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

//FUNCTION: assessGrade(int[])
//DESCRIPTION: takes an int array which will contain 5 different values from user input. if all the 
// input's are valid and within range, the final grade average is calulated and sent to the worker bee 
// function to determine if they passed or failed. invalid inputs cause the function to quite immediately. 
// since the array was initialized to zero, this function can run even if a user only enters two valid grades.
//PARAMETERS: int listOfGrades
//RETURNS: ERROR or SUCCESS status code
int assessGrade(int listOfGrades[])
{
	int gradeSum = 0;
	double finalGrade = 0;

	for (int i = 0; i < NUM_GRADES; i++)
	{
		if (listOfGrades[i] >= 0 && listOfGrades[i] <= 100)
		{
			gradeSum += listOfGrades[i];
		}
		else
		{
			//if there is ever an input among the list that is not within range, immediately
			//quit this function and tell the parseUserInput function that there was an invalid input
			printf("**ERROR : Invalid Input\n");
			return ERROR;
		}
	}

	finalGrade = (double)gradeSum / (double)NUM_GRADES;
	//now send to worker bee to assess whether it is a pass or fail
	assessGrade(finalGrade);

	return SUCCESS;

}

//FUNCTION: parseUserInput
//DESCRIPTION: takes the initial input from stdin or file i/o and checks to see what type of data they 
// entered. after an overloaded function has successfully taken an argument, the parseUserInput function
// returns a status code so that any remaining assessGrade functions are not called, eliminating duplicates.
//PARAMETERS: char* studentGrade. technically not every string inputted is a valid student grade however
// along the happy path it is.
//RETURNS: SUCCESS or ERROR or IS_X
int parseUserInput(char* studentGrade)
{
	//remove newline
	size_t length = strlen(studentGrade);
	if (studentGrade[length - 1] == '\n')
	{
		studentGrade[length - 1] = '\0';
	}

	const int kMinParse = 1;
	double invalidInput = 0;
	double finalGrade = 0;
	//if the return value of sscanf is not 1 then it is not a valid final grade value, pass on to next
	if (sscanf(studentGrade, "%lf %lf", &finalGrade, &invalidInput) == kMinParse)
	{
		//pass to the bee worker function
		assessGrade(finalGrade);
		return SUCCESS;
	}

	//magic number / initalize to 5 zeros
	int gradesList[NUM_GRADES] = { 0 };
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

	if (length <= letterGradeLen)
	{
		/*
		* Reason for IS_X is due to file i/o not accepting X as a valid input. Previously in assessGrade(char*),
		* i had it return SUCCESS if the letterGrade matched "X", reading X from file didn't allow the program to
		* exit since it's stuck in a while loop. This technically wouldn't necessary if you aren't tricking us by putting
		* X in a file but it's just a precaution.
		*/
		if (assessGrade(studentGrade) == IS_X)
		{
			return IS_X;
		}
		return SUCCESS;
	}
	else
	{
		printf("**ERROR : Invalid Input\n");
		return ERROR;
	}
}
