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
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Length Validity
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    //Alpha Validity
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    //Repetition Validity
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Key must not repeat characters.\n");
                    return 1;
                }
            }
        }
    }

    //New alphabet
    char upAlpha[26];
    char lowAlpha[26];
    for (int i = 0; i < 26; i++)
    {
        lowAlpha[i] = tolower(argv[1][i]);
        upAlpha[i] = toupper(argv[1][i]);
        // printf("%c, %c\n", newAlpha[i], newAlpha[i + 25]);
    }

    //Get plaintext input
    string text = get_string("plaintext: ");

    //Return Ciphertext
    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //Alphabetical?
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
        }
        if (islower(text[i]))
        {
            printf("%c", lowAlpha[text[i] - 97]);
        }
        if (isupper(text[i]))
        {
            printf("%c", upAlpha[text[i] - 65]);
        }
    }
    //Clean Terminal
    printf("\n");
    return 0;
}