#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Get User Input
    string text = get_string("Text: ");

    //Words, Letters, Sentences, oh my!
    float W = count_words(text);
    float L = (count_letters(text) / W) * 100;
    float S = (count_sentences(text) / W) * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    //Print Grade Level below 1
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    //Print Grade Level if 16 or higher
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    //Print Grade level
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}

// Number of Letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}
// Number of Words
int count_words(string text)
{
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words ++;
        }
    }
    return words;
}
// Number of Sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences ++;
        }
    }
    return sentences;
}