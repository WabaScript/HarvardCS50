#include <stdio.h>
#include <cs50.h>
#include <string.h>

string validate(long number);
long firstDigits(long number);

int main(void)
{
    //Get user input
    long n;
    n = get_long("Number: ");
    // Print the correct validation
    printf("%s", validate(n));
}

// Get the checksum
bool luhns(long number)
{
    int sum = 0, i = 0;
    while (number > 0)
    {
        sum += (number % 10);
        number /= 10;
        int product = (number % 10) * 2;
        if (product < 10)
        {
            sum += product;
        }
        else
        {
            while (product > 0)
            {
                sum += (product % 10);
                product /= 10;
            }
        }
        number /= 10;
        i += 2;
    }
    // Validate length and see if valid by Luhns algo (0)
    return i >= 13 && sum % 10 == 0;
}

// Look at first digits and determine CC company
string validate(long number)
{
    bool isValid = luhns(number);
    // Quickly determine if valid length
    if (!isValid)
    {
        return "INVALID\n";
    }
    long n = firstDigits(number);
    if (n == 34 || n == 37)
    {
        return "AMEX\n";
    }
    else if (n == 51 || n == 52 || n == 53 || n == 54 || n == 55)
    {
        return "MASTERCARD\n";
    }
    else if (n / 10 == 4)
    {
        return "VISA\n";
    }
    else
    {
        return "INVALID\n";
    }
}

// Get the first 2 digits
long firstDigits(long number)
{
    while (number >= 100)
    {
        number /= 10;
    }
    // return first 2 digits
    return number;
}