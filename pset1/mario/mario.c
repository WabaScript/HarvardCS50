#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        // spacing
        for (int j = i; j < n - 1; j++)
        {
            printf(" ");
        }

        // right aligned pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // two spaces in the for loop
        printf("  ");

        // left aligned pyramid
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }
        // line break
        printf("\n");
    }
}
