#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt the user for the cash they need to get in return
    float c;
    do
    {
        c = get_float("Change owed: ");
    }
    while (c <= 0);

    // Make the different integers to calculate with
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // calculate the number of cents
    int cents = round(c * 100);

    // Set the counter to zero
    int count = 0;

    // start with the calculation, first look at the quarters
    int q = cents / quarter;

    if (q >= 1)
    {
        int cents_q = cents - (q * quarter);
        count = count + q;
        int d = cents_q / dime;

        // next check the number of dimes
        if (d >= 1)
        {
            int cents_d = cents_q - (d * dime);
            count = count + d;
            int n = cents_d / nickel;

            // now let's find out how many nickels are needed
            if (n >= 1)
            {
                int cents_n = cents_d - (n * nickel);
                count = count + n;
                int p = cents_n / penny;

                // find the number of pennies
                if (p >= 1)
                {
                    count = count + p;
                }
            }
            //if there are no nickels, check out the number of pennies
            else
            {
                int p = cents_d / penny;
                count = count + p;
            }
        }
        // if no dimes, look at the number of nickels
        else
        {
            int n = cents_q / nickel;
            count = count + n;
        }
    }
    //if there are no quarters, check out the number of dimes
    else
    {
        int d = cents / dime;
        if (d >= 1)
        {
            int cents_d = cents - (d * dime);
            count = count + d;
            int n = cents_d / nickel;

            // now let's find out how many nickels are needed
            if (n >= 1)
            {
                int cents_n = cents_d - (n * nickel);
                count = count + n;
                int p = cents_n / penny;

                // find the number of pennies
                if (p >= 1)
                {
                    count = count + p;
                }
            }
            else
            {
                int p = cents_d / penny;
                count = count + p;
            }
        }
        //If also no dimes, let's see how many nickels
        else
        {
            int n = cents / nickel;
            if (n >= 1)
            {
                int cents_n = cents - (n * nickel);
                count = count + n;
                int p = cents_n / penny;

                if (p >= 1)
                {
                    count = count + p;
                }
            }
            // if no nickels, dimes or quarters, look only at the pennies
            else
            {
                int p = cents / penny;
                count = count + p;
            }
        }

    }
    // Return the mininum amount of coins needed
    printf("%i\n", count);
}