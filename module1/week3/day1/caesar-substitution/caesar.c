#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char charcipher(char character, int k);
bool validkey(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (validkey(argv[1]))
        {
            string text = get_string("plaintext: ");
            int n = (int)strlen(text);
            int k = atoi(argv[1]);
            char cipher[n];
            int i = 0;
            while (text[i] != '\0')
            {
                cipher[i] = charcipher(text[i], k);
                i++;
            }
            printf("ciphertext: ");
            for (int j = 0; j < n; j++)
            {
                printf("%c", cipher[j]);
            }
            printf("\n");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

char charcipher(char character, int k)
{
    if ((character >= 'A') && (character <= 'Z'))
    {
        return (char)((((int)character + k) - 64) % 26 + 64);
    }
    else if ((character >= 'a') && (character <= 'z'))
    {
        return (char)((((int)character + k) - 96) % 26 + 96);
    }
    else
    {
        return character;
    }
}

bool validkey(string key)
{
    int i = 0;
    while (key[i] != '\0')
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}