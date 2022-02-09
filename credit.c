#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cNumber = 0;
    do
    {
        cNumber = get_long("Digit Credit Car number:");
    }
    while (cNumber <= 0);
// some variables
    long workingCC = cNumber;
    int sum;
    int count = 0;
    long divisor = 10;
    // 1st case
    while (workingCC > 0)
    {
        int lastDigit = workingCC % 10;
        sum = sum + lastDigit;
        // moving to digits over
        workingCC = workingCC / 100;
    }
    // 2nd case
    workingCC = cNumber / 10;

    while (workingCC > 0)
    {
        int lastDigit = workingCC % 10;
        // times two the digit
        int timesTwo = lastDigit * 2;
        // sum every times two
        sum = sum + (timesTwo % 10) + (timesTwo / 10);
        // moving to digits over
        workingCC = workingCC / 100;
    }

    workingCC = cNumber;
    while (workingCC > 0)
    {
        workingCC = workingCC / 10;
        count++;
    }

    //divisor
    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }
// getting the first digit
    int firstDigit = cNumber / divisor;
// getting the first and second digit
    int firstTwoDigit = cNumber / (divisor / 10);
// Verification about what is credit card
    if (sum % 10 == 0)
    {
        // If visa
        if (firstDigit == 4)
        {
            printf("Visa Card: %li\n", cNumber);
        }
        // if is American Express
        else if (firstTwoDigit ==  34 || firstTwoDigit == 37)
        {
            printf("American Express: %li\n", cNumber);
        }
        // if master card
        else if (firstTwoDigit == 51 || firstTwoDigit == 52 || firstTwoDigit == 53 || firstTwoDigit == 54 || firstTwoDigit == 55)
        {
            printf("MasterCard: %li\n", cNumber);
        }
    }
    else
    {
        printf("Invalid Credit card: %li\n", cNumber);
    }
}