#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

bool valid_triangle(float L1, float L2, float L3);

int main(void)
{
    // Get the lengths of the triangle from the user
    float L1 = get_float("Length 1: ");
    float L2 = get_float("Length 2: ");
    float L3 = get_float("Length 3: ");

    // Use the bool function to determine which output to print
    if (valid_triangle(L1, L2, L3))
    {
        printf("This is a valid triangle\n");
    }
    else
    {
        printf("This is not a valid triangle\n");
    }
}

// boolean function that determines if the triangle is valid or not
bool valid_triangle(float L1, float L2, float L3)
{
    // lengths must all be positive
    if (L1 <= 0 || L2 <= 0 || L3 <= 0)
    {
        return false;
    }
    // two lengths added together must be larger than the third length
    if ((L1 + L2) <= L3 || (L2 + L3) <= L1 || (L3 + L1) <= L2)
    {
        return false;
    }
    else
    {
        return true;
    }
}
