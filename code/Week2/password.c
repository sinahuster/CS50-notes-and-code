// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and "
               "symbol\n");
    }
}

// Definition of the function which determines if the password is valid or not
bool valid(string password)
{
    // create an array where each value will store whether or not the required character was used
    int contains[] = {0, 0, 0, 0};

    // iterate through the password string
    for (int i = 0; i < strlen(password); i++)
    {
        char c = password[i];
        // if there is an uppercase letter, we add to contains[0]
        if (isupper(c) != 0)
        {
            contains[0]++;
        }
        // if there is a lowercase letter, we add to contains[1]
        if (islower(c) != 0)
        {
            contains[1]++;
        }
        // if there is a number, we add to contains[2]
        if (isdigit(c) != 0)
        {
            contains[2]++;
        }
        // if there is punctuation, we add to contains[3]
        if (ispunct(c) != 0)
        {
            contains[3]++;
        }
    }

    // we check that each value of the array contains is greater than 0, if not the password is
    // invalid and we return false, otherwise we return true
    for (int j = 0; j < 4; j++)
    {
        if (contains[j] == 0)
        {
            return false;
        }
    }

    return true;
}
