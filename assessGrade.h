#pragma once
#include <stdio.h>

#define SUCCESS 0
#define ERROR -1
#define PASS 1
#define FAIL 2
#define SPECIAL_CASE 3
#define NUM_CHARS 40

//letter grade to be converted
int assessGrade(char*);

//final grade worker bee
int assessGrade(double);

//list of 5 integer grades
int assessGrade(int[]);

//intelligently parses userInput
int parseUserInput(char*);

