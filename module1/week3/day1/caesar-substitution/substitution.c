#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char substitute(char character, string key);
bool validkey(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (validkey(argv[1]))
        {
            string text = get_string("plaintext: ");
            int n = (int)strlen(text);
            string key = argv[1];
            char cipher[n];
            int i = 0;
            while (text[i] != '\0')
            {
                cipher[i] = substitute(text[i], key);
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
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

char substitute(char character, string key)
{
    int index;
    if ((character >= 'A') && (character <= 'Z'))
    {
        index = (int)character % 65;
        return toupper(key[index]);
    }
    else if ((character >= 'a') && (character <= 'z'))
    {
        index = (int)character % 97;
        return tolower(key[index]);
    }
    else
    {
        return character;
    }
}

bool validkey(string key)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    if (strlen(key) != 26)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            int count = 0;
            for (int j = 0; j < 26; j++)
            {
                if (alphabet[i] == tolower(key[j]))
                {
                    count++;
                }
            }
            if (count != 1)
            {
                return false;
            }
        }
    }
    return true;
}