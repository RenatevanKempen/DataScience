#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    int end;
    int n = 0;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 10);
    // TODO: Prompt for end size
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    // TODO: Calculate number of years until we reach threshold
    do
    {
        if (start == end)
        {
            n = 0;
        }
        else if (start < end)
        {
            start = start + (start / 3) - (start / 4);
            n++;
        }
        else
        {
            return n;
        }
    }
    while (start < end);
    // TODO: Print number of years
    printf("Years: %i", n);

}