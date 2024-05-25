/*
* FILE : assessGrade.h
* PROJECT : PROG1385 - A01 Overloaded Functions
* PROGRAMMER : Alexia Tu
* FIRST VERSION : 05/25/2024
* DESCRIPTION : Includes the prototypes for the 3 overloaded functions of assessGrade(),
    * the parseUserInput() function, as well as my defines and constants.
*/

//my return codes
#define SUCCESS 0
#define ERROR -1
#define PASS 1
#define FAIL 2
//used for user input and file i/o
#define NUM_CHARS 100
//used for the input in the case of an array of ints
#define NUM_GRADES 5
//used when parsing the file i/o name that follows Z, one string should be parsed
const int kNumToParse = 1;
//used to check if there were zero characters before Z
const size_t kFileMode = 0;
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

