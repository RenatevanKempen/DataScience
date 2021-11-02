#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");
    if (x < y)
    {
        printf(" x is less than y\n");

    }
    else if (x > y)
    {
        printf(" x is greater than y\n");
    }
    else //if (x == y)
    {
        printf(" x is equal to y\n");
    }
}