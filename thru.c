#include <stdio.h>
#include <string.h> // Used for strings, checking equalness, copying strings, etc.
#include <stdlib.h> // Adds atoi() which converts string to int
#include <ctype.h> // Adds isdigit() which is used inside isNumber() function

// This part is used for https://github.com/hussein-esmail7/template-maker
// templateDescription: C Programming Document

/*
thru.c
Hussein Esmail
Created: 2025 01 23
Updated: 2025 01 23
Terminal command to compile file to an executable:
    gcc -o thru thru.c && chmod +x thru && ./thru
Terminal command to compile multiple files into one executable:
    gcc thru.c <Other filenames> -o thru && chmod +x thru && ./thru
Description: [DESCRIPTION]
*/

int isNumber(const char number[])
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return 0;
    }
    return 1;
}

int main(int argc, char **argv) {
	int lastnum = 0;	// The last number given
	int lastargnum = 0; // Index the last number was given
	int operator = 0;	// Which math operator given. See list below
	/* operator:
	 * 0: null / none given yet
	 * 1: +
	 * 2: -
	 * 3: thru
	 * 4:
	 */
	int operatorargnum = 0; // Index the last operator was given
	// Why track argument numbers? There's no scenario where this program
	// should expect two numbers in a row or two operators in a row. Ex:
	// 1. '1 2 3'
	// 2. '1 + - 3'
	// 3. '1 THRU - 4'
	// All do not make sense
    for (int i = 1; i < argc; i++) { // For every argument vigen
    	// argv[0] = ./thru
    	// argv[1] = first argument
        printf("argv[%d]: %s\n", i, argv[i]); // Print argument
		if (i==1) {
			// First argument
			if (isNumber(argv[i])) {
				// if it is a number
				lastnum = atoi(argv[i]); // Save to last number
			} else {
				// Not a number
				// TODO: Raise error: first argument must be number
				printf("ERROR: First argument must be a number.\n");
				return -1;
			}
		} else {
			// All other arguments

		}





    }
    return 0;
}
