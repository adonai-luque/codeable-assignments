#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float change = get_string("Change owed: ");
    intchange = round(change * 100);
    int coins = 0;
    coins = coins + intchange / 25;
    intchange = intchange % 25;
    coins = coins + intchange / 10;
    intchange = intchange % 10;
    coins = coins + intchange / 5;
    intchange = intchange % 5;
    coins = coins + intchange;
    printf("%i\n", coins);
}
