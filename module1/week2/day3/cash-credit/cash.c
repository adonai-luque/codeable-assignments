#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
  float change = -0.01;
  while (change < 0)
  {
    change = get_float("Change owed: ");
  }
  int intchange = round(change * 100);
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