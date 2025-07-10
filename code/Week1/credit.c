#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // asking the user to put in a number until a valid number is given
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);

    // store the original number before manipulating it
    long original = num;

    // defining the sums which we will use to check using Luhn's algorithm
    int sum_odd = 0;
    int sum_even = 0;
    int total;

    // a counter for how many digits the number contains
    int digits = 0;

    // iterating throught he digits to perform Luhn's algorithm
    while (num > 0)
    {
        int current_digit = num % 10;
        if (digits % 2 == 0)
        {
            sum_odd += current_digit;
        }
        else
        {
            int doubled = current_digit * 2;
            if (doubled >= 10)
            {
                sum_even += (doubled % 10) + (doubled / 10);
            }
            else
            {
                sum_even += doubled;
            }
        }
        num /= 10;
        digits++;
    }

    // continue to calculate if the number is valid using Luhn's algorithm
    total = sum_even + sum_odd;
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // check that the starting numbers match with a card type and print the card types
    // and that the card length is also correct, otherwise we print invalid
    while (original >= 100)
    {
        original /= 10;
    }
    int first_two = original;
    int first = original / 10;

    if (first == 4 && (digits == 13 || digits == 16))
    {
        printf("VISA\n");
    }
    else if ((first_two == 34 || first_two == 37) && digits == 15)
    {
        printf("AMEX\n");
    }
    else if ((first_two >= 51 && first_two <= 55) && digits == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
