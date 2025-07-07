#include <cs50.h>
#include <stdio.h>

// defining the global varibales, the value of each coin as these do not change
#define CENT 1
#define NICKEL 5
#define DIME 10
#define QUARTER 25

// declaring the function for later use
int coins_given(int change);

int main(void)
{
    // asking for an input for change owed until one above or equal to 0 is inputted
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    // then we use this function to find how mnay coins are required
    coins_given(change);
}


int coins_given(int change)
{
    int coins = 0;
    // we have a loop which keeps going until change is equal to 0
    for (; change > 0;)
    {
        // we see if change is larger than a quarter and if so remove it and add a coin
        if (change >= QUARTER)
        {
            change = change - QUARTER;
            coins++;
        }
        // we see if change is larger than a dime and if so remove it and add a coin
        else if (change >= DIME)
        {
            change = change - DIME;
            coins++;
        }
        // we see if change is larger than a nickel and if so remove it and add a coin
        else if (change >= NICKEL)
        {
            change = change - NICKEL;
            coins++;
        }
        // we see if change is larger than a cent and if so remove it and add a coin
        else if (change >= CENT)
        {
            change = change - CENT;
            coins++;
        }
    }
    // once change is equal to 0, we print how many coins are needed
    printf("%d\n", coins);
}
