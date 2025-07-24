#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// declaring the functions which will be used in main
int valid_key(string key);

void encrypted_text(string text, string key);

int main(int argc, string argv[])
{
    // check there are only two arguements, one of which is user input
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    string key = argv[1];

    // checking the key is 26 characters long
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // use the previously declared function, valid_key, to check if the key is valid
    if (valid_key(argv[1]) == 1)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // allow the user to input the plain text which is to be encrypted
    string text = get_string("plaintext:  ");

    // call the previously declared function to change to the encrypted text
    encrypted_text(text, key);
}

// define the function which checks if the key is valid and returns 1 if not
int valid_key(string key)
{
    // iterate through all characters in the string
    for (int i = 0; i < strlen(key); i++)
    {
        char ch = key[i];

        // check each character is alphabetic
        if (isalpha(ch) == 0)
        {
            return 1;
        }

        // checks none of the characters are the same, we change them to uppercase to make sure
        // there isn't a duplicate by one being lowercase and the other uppercase
        for (int j = 0; j < i; j++)
        {
            if (toupper(ch) == toupper(key[j]))
            {
                return 1;
            }
        }
    }
    return 0;
}

// definition of the function which changes the text to the encrypted text
void encrypted_text(string text, string key)
{
    // iterate through the text string
    for (int i = 0; i < strlen(text); i++)
    {
        char ch = text[i];

        // check the character is alphabetic
        if (isalpha(ch))
        {
            // determine whether the character is uppercase or not, then calulate the letter by
            // finding it's place w.r.t 'A', then set the character to the uppercase letter assigned
            // using the key
            if (isupper(ch))
            {
                int letter = ch - 'A';
                ch = toupper(key[letter]);
            }
            // determine whether the character is lowerase or not, then calulate the letter by
            // finding it's place w.r.t 'a', then set the character to the lowercase letter assigned
            // using the key
            if (islower(ch))
            {
                int letter = ch - 'a';
                ch = tolower(key[letter]);
            }
        }
        // set the new character into the text string
        text[i] = ch;
    }

    // print the new chipertext
    printf("ciphertext: %s\n", text);
}
