#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int n;  //declare n
    // ask for change
    do
    {
        n = get_int("Change owed: ");
    }
    while (n < 0);  // keep asking if change is negative
    return n;
}

int calculate_quarters(int cents)
{
    int x = 0;
    // for cents above 25
    while (cents >= 25)
    {
        cents -= 25;
        x += 1;
    }
    return x;
}

int calculate_dimes(int cents)
{
    int y = 0;
    // for cents above 10 and less than 25
    while (cents >= 10)
    {
        cents -= 10;
        y += 1;
    }
    return y;
}

int calculate_nickels(int cents)
{
    int z = 0;
    // for change between 5 and 10
    while (cents >= 5)
    {
        cents -= 5;
        z += 1;
    }
    return z;
}

int calculate_pennies(int cents)
{
    // simple return for change less than 5
    return cents;
}
