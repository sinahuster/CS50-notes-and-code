#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // allow the user to input their name
    string name = get_string("What is your name? ");
    // print hello and the input that they have just given
    printf("hello, %s\n", name);
}
