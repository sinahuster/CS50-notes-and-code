#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int reading_level(string text);

int main(void)
{
    // Allow the user to input the text
    string text = get_string("Text: ");

    // Call the function which calulates the reading level
    int grade = reading_level(text);

    // Determine which output to print dependent on the grade level of the text
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
}

int reading_level(string text)
{
    int sentences = 0;
    int letters = 0;
    int words = 1;

    // Iterate through all the characters of the text string
    for (int i = 0; i < strlen(text); i++)
    {
        char character = text[i];

        // Determines if there is a space, hence a new word
        if (character == ' ')
        {
            words++;
        }
        // Determines if there is end of sentence punctuation, hence new sentance
        else if (character == '.' || character == '!' || character == '?')
        {
            sentences++;
        }
        // Determines if the character is a letter
        else if (isalpha(character))
        {
            letters++;
        }
    }

    // Calculate the appropriate values for the index per 100 words
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index);
}
