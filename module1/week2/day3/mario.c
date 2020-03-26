#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = -1;
    while ((h < 1) || (h > 8))
    {
        h = get_int("Height: ");
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < (h - i - 1); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < (i + 1); k++)
        {
            printf("#");
        }
        printf("\n");
    }
}