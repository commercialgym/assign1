#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable: 4996)

#define SUCCESS 0
#define ERROR -1
#define PASS 1
#define FAIL 2
#define SPECIAL_CASE 3
#define NUM_CHARS 100
//checks for X, had to create for file i/o
#define IS_X 4

//letter grade to be converted
int assessGrade(char*);

//final grade worker bee
int assessGrade(double);

//list of 5 integer grades
int assessGrade(int[]);

//intelligently parses userInput
int parseUserInput(char*);

