#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_amount(int cents);

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNIE 1

int main(void)
{
    int cents = get_cents();
    int amount = calculate_amount(cents);
    printf("%i\n", amount);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);
    return cents;
}

int calculate_amount(int cents)
{
    int counter = 0;
    while (cents >= QUARTER)
    {
        cents -= QUARTER;
        counter++;
    }

    while (cents >= DIME)
    {
        cents -= DIME;
        counter++;
    }

    while (cents >= NICKEL)
    {
        cents -= NICKEL;
        counter++;
    }

    while (cents >= PENNIE)
    {
        cents -= PENNIE;
        counter++;
    }

    return counter;
}