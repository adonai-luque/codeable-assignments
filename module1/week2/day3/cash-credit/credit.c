#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    long number = -1;
    int sumaimpar = 0;
    int sumapar = 0;
    int digitodoble;
    number = get_long("Number: ");
    if ((number > 3999999999999) && (number < 5600000000000000))
    {
        long residuo = number;
        while (residuo > 0)
        {
            sumaimpar = sumaimpar + residuo % 10;
            digitodoble = ((residuo / 10) % 10) * 2;
            while (digitodoble > 0)
            {
                sumapar = sumapar + digitodoble % 10;
                digitodoble = digitodoble / 10;
            }
            residuo = residuo / 100;
        }
        
        if (((sumapar + sumaimpar) % 10) == 0)
        {
            if (((number > 339999999999999) && (number < 350000000000000)) || ((number > 369999999999999) && (number < 380000000000000)))
            {
                printf("AMEX\n");
            }
            else if ((number > 5099999999999999) && (number < 5600000000000000))
            {
                printf("MASTERCARD\n");
            }
            else if ((number > 3999999999999999) && (number < 5000000000000000))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
