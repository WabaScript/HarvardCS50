#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Argument Count
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Argument Validity
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //Get User Plaintext
    int k = atoi(argv[1]);
    string text = get_string("plaintext: ");

    //Return Ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = 0;
        //Alphabetical?
        if (!isalpha(text[i]))
        {
            c = text[i];
        }
        //Uppercase?
        if (isupper(text[i]))
        {
            c = ((text[i] - 65 + k) % 26);
            c = c + 65;
        }
        //Lowercase?
        if (islower(text[i]))
        {
            c = ((text[i] - 97 + k) % 26);
            c = c + 97;
        }
        //Print Encrypted Character
        printf("%c", c);
    }
    //Clean Terminal
    printf("\n");
    return 0;
}