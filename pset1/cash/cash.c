#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get user input
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n <= 0);

    // convert dollars to cents
    int cents = round(n * 100);
    int change = 0;

    // If not $0.00 we still owe change
    while (cents > 0)
    {
        //Check Greedy Algo against each coin
        while (cents >= 25)
        {
            cents = cents - 25;
            change++;
        }
        while (cents >= 10)
        {
            cents = cents - 10;
            change++;
        }
        while (cents >= 5)
        {
            cents = cents - 5;
            change++;
        }
        while (cents >= 1)
        {
            cents = cents - 1;
            change++;
        }
    }
    // print result
    printf("%i\n", change);
}