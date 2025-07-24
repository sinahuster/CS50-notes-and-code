#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int word_score(string word);

int main(void)
{
    // Get inputs from Player 1 and 2
    string word1 = get_string("Player 1 : ");
    string word2 = get_string("Player 2 : ");

    // Determine the scores from the words
    int score1 = word_score(word1);
    int score2 = word_score(word2);

    // Determine what to print by comparing the scores
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score2 < score1)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Define a function that calculates the scores of the words
int word_score(string word)
{
    int points = 0;

    // Iterate throught the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Ensure all letters are converted to uppercase
        char letter = toupper(word[i]);

        // Determine the points each character is worth
        if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'L' || letter == 'N' ||
            letter == 'O' || letter == 'R' || letter == 'S' || letter == 'T' || letter == 'U')
        {
            points++;
        }
        else if (letter == 'D' || letter == 'G')
        {
            points += 2;
        }
        else if (letter == 'B' || letter == 'C' || letter == 'M' || letter == 'P')
        {
            points += 3;
        }
        else if (letter == 'F' || letter == 'H' || letter == 'V' || letter == 'W' || letter == 'Y')
        {
            points += 4;
        }
        else if (letter == 'K')
        {
            points += 5;
        }
        else if (letter == 'J' || letter == 'X')
        {
            points += 8;
        }
        else if (letter == 'Q' || letter == 'Z')
        {
            points += 10;
        }
    }
    return points;
}
