/*****************************************************************
//
//  DESCRIPTION:
//   Takes a user input integer and outputs a table listing if each number from 0 to
//   the user input integer is divisible by 4.
//
//  REFERENCES:
//   Ravi Narayan
//   The C Programming Language, 2nd Edition, Sections 7.2, 7,4, and 7.7
//       By Brian W. Kernighan and Dennis M. Ritchie
//
****************************************************************/

#include <stdio.h>

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   Gives a brief overview of the program to the user.
//                 Requests a positive int from the user.
//                 Then does some checks to ensure the input is an int.
//                     No chars preceding or following an int, int is positive, etc.)
//                 Will continually prompt user for an int until valid input is provided.
//
//  Parameters:    None.
//
//  Return values:  userInput (int): the valid integer provided by the user.
//
****************************************************************/

int user_interface()
{
    /* Array to store user input. */
    char userInputArray[100];

    /* Index where newline is stored from fgets (end of input). */
    int endIndex = 0;

    /* Boolean that controls the valid input checks. */
    int badInput;

    /* Iterator controller. */
    int i;

    /* Used to "reset" the user input array if bad input was detected. */
    char resetUserInputArray[1];

    /* The final int to be returned if user input is valid. */
    int userInput = 0;

    printf("Takes a positive integer.  Then outputs a table of numbers from 0 to ");
    printf("that number, and which of those numbers are a multiple of 4.\n\n");
    printf("Enter maximum number to show: ");

    /* Gets user input and stores a max of 100 chars in a char array */
    fgets(userInputArray, 100, stdin);

    /* Find the newline char (end of user input) */
    for (i = 0; i < 100; i++)
    {
        if (userInputArray[i] == '\n')
        {
            endIndex = i;
        }
    }

    printf("\n");

    do
    {
        /* Resets the boolean and iterator controller */
        badInput = 0;
        i = 0;

        /* Checks for a negative number or an input of just 0 */
        if (userInputArray[0] == '-' || (userInputArray[0] == '0' && endIndex == 1))
        {
            printf("Number needs to be greater than 0.\n\n");
            badInput = 1;
        }

        /* Checks for no input (user just pressed enter at prompt) */
        else if (endIndex == 0)
        {
            printf("You didn't enter anything.\n\n");
            badInput = 1;
        }

        /* Iterates over all chars, checking for any that aren't ints */
        else
        {
            while (badInput == 0 && i < endIndex)
            {
                if (userInputArray[i] != '1' && userInputArray[i] != '2' && userInputArray[i] != '3' && userInputArray[i] != '4' && userInputArray[i] != '5' && userInputArray[i] != '6' && userInputArray[i] != '7' && userInputArray[i] != '8' && userInputArray[i] != '9' && userInputArray[i] != '0')
                {
                    printf("Bad input.  Please enter ONLY an integer (no other ");
                    printf("characters, white space, etc.).\n\n");
                    badInput = 1;
                }
                i++;
            }
        }

        /* If bad input is found, reset the user input array and ask for another input */
        if (badInput == 1)
        {
            for (i = 0; i < 100; i++)
            {
                userInputArray[i] = resetUserInputArray[0];
            }
            printf("Enter maximum number to show: ");
            fgets(userInputArray, 100, stdin);

            for (i = 0; i < 100; i++)
            {
                if (userInputArray[i] == '\n')
                {
                    endIndex = i;
                }
            }
        }
    }
    while (badInput == 1);

    /* If input is valid, reconstruct the user's input as an int*/
    sscanf(userInputArray, "%d", &userInput);
    return userInput;
}

/*****************************************************************
//
//  Function name: is_multiple4
//
//  DESCRIPTION:   Checks if an int is a multiple of 4.
//
//  Parameters:    num (int) : an int.
//
//  Return values:  returnValue (int) : 0 if num is not multiple of 4.
//                                      1 if num is a multiple of 4.
//
****************************************************************/

int is_multiple4(num)
{
    int returnValue;

    if (num % 4 == 0)
    {
        returnValue = 1;
    }
    else
    {
        returnValue = 0;
    }

    return returnValue;
}

/*****************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION:   Takes an int and outputs a table that shows the range of numbers
//                 from 0 to the int, and if those numbers are multiples of 4.
//
//  Parameters:    num (int) : an int.
//
//  Return values:  None.
//
****************************************************************/

void print_table(num)
{
    int i;

    /* Prints colum headers, right aligned. */
    printf("%8s %4s", "Number", "Multiple of 4?\n");

    /* Iterates until all numbers from 0 to num are mutiple of 4 checked. */
    for (i = 0; i <= num; i++)
    {
        if (is_multiple4(i) == 1)
        {
            /* Prints number and "Yes", right aligned */
            printf("%8d %15s", i, "Yes\n");
        }
        else
        {
            /* Prints number and "No", right aligned */
            printf("%8d %15s", i, "No\n");
        }
    }
}

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Calls user_interface() to get a valid int input and store that int
//                 in a variable.  Then passes that variable to print_table(), which
//                 will output a table from 0 to the int input and if the numbers are
//                 multiples of 4.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : Success.
//
****************************************************************/

int main(int argc, char* argv[])
{
    int userInput = user_interface();
    print_table(userInput);
    return 0;
}