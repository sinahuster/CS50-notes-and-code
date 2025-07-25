// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// declare the fucntion declare which is defined later
string replace(string word);

int main(int argc, string argv[])
{
    // check that the user input one arguement
    if (argc != 2)
    {
        printf("Usage: %s word\n", argv[0]);
        return 1;
    }

    // we call the function which we have defined to replace the neccessary vowels
    string replacement = replace(argv[1]);
    // then we print the new word
    printf("%s\n", replacement);
}

// define the function which replaces vowels with numbers, returns a string, the new word
string replace(string word)
{
    // iterate through the characters in the string
    for (int i = 0; i < strlen(word); i++)
    {
        char c = word[i];
        // use the function switch to check if the character is a vowels that needs to be changed
        // and if yes, change the character, otherwise just break
        switch (c)
        {
            case 'a':
                c = '6';
                break;

            case 'e':
                c = '3';
                break;

            case 'i':
                c = '1';
                break;

            case 'o':
                c = '0';
                break;

            default:
                break;
        }

        // change the character in the string, word, to the newly assigned character
        word[i] = c;
    }

    return word;
}
