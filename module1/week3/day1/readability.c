#include <stdio.h>
#include <cs50.h>
#include <math.h>

int letters(string text);
int words(string text);
int sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float L = 100 * (float)letters(text) / (float)words(text);
    float S = 100 * (float)sentences(text) / (float)words(text);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 0.5)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 15.5)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}

int letters(string text)
{
    int i = 0;
    int count = 0;
    while (text[i] != '\0')
    {
        if (((text[i] >= 'a') && (text[i] <= 'z')) || ((text[i] >= 'A') && (text[i] <= 'Z')))
        {
            count++;
        }
        i++;
    }
    return count;
}

int words(string text)
{
    int i = 0;
    int count = 0;
    while (text[i] != '\0')
    {
        if (text[i] == ' ')
        {
            count++;
        }
        i++;
    }
    return count + 1;
}

int sentences(string text)
{
    int i = 0;
    int count = 0;
    while (text[i] != '\0')
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            count++;
        }
        i++;
    }
    return count;
}