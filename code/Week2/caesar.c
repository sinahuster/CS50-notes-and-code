#include <cs50.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>

// define functions which are used later
int only_digits(string key);

void rotate(string text, int k);

int main(int argc, string argv[])
{
    // check there are only two arguements, one of which is user input
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // use a function that checks all of the string is only digits
    if (only_digits(argv[1]) == 1)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // convert the string into an integer and check it is non-negative
    int k = strtoumax(argv[1], NULL, 10);
    if (k < 0)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // calculate the key modulus 26
    k = k % 26;

    // allow the user to input to the text to be encrypted
    string text = get_string("plaintext:  ");

    // call the function to print the cipher text
    rotate(text, k);
    printf("\n");
}

// definition of the function which checks the key input is only digits
int only_digits(string key)
{
    // iterate through each character and check it has the ASCII value of a digit
    for (int i = 0; i < strlen(key); i++)
    {
        char ch = key[i];
        if (key[i] < 48 || key[i] > 57)
        {
            return 1;
        }
    }

    return 0;
}

// definition of the function which changes the text into the cipher text
void rotate(string text, int k)
{
    // iterate through the characters
    for (int i = 0; i < strlen(text); i++)
    {
        char ch = text[i];

        // check if the character is a letter, if so, continue
        if (isalpha(ch))
        {
            // check if the character is a uppercase letter, calculate the new uppercase letter,
            // then calculate modulus 26 to stay within uppercase letters
            if (isupper(ch))
            {
                ch = (ch - 'A' + k) % 26 + 'A';
            }

            // check if the character is a lowercase letter, calculate the new lowercase letter,
            // then calculate modulus 26 to stay within lowercase letters
            if (islower(ch))
            {
                ch = (ch - 'a' + k) % 26 + 'a';
            }
        }

        // change the character in the text to the new character
        text[i] = ch;
    }

    // print the new ciphertext
    printf("ciphertext: %s", text);
}
