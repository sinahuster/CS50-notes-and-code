#include <cs50.h>
#include <stdio.h>

// declaring a function which is later defined
void print_row(int n, int row);

int main(void)
{
    int n;
    // we loop asking for an input until a deseried one is given, betweeen 1 and 8.
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // we are iterating through the rows and calling the print_row function for each row
    for (int row = 1; row <= n; row++)
    {
        print_row(n, row);
    }
}

// definition of the print_row function
void print_row(int n, int row)
{
    // first we print the blank spaces, which decrease by 1 every row
    for (int i = n - row; i > 0; i--)
    {
        printf(" ");
    }

    // then we print the hashes on the left which increase by 1 every row
    for (int j = 0; j < row; j++)
    {
        printf("#");
    }

    // this is used to print the two black spcaces in the middle of the pyramid
    printf("  ");

    // then finally we print the hashes on the right of the pyramid, increasing by one every row
    for (int l = 0; l < row; l++)
    {
        printf("#");
    }

    // then a new line, so the next row is printed below
    printf("\n");
}
