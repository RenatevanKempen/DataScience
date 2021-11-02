#include <cs50.h>
#include <stdio.h>

int start(void);
int end(void);

int main(void)
{
    // TODO: Prompt for start size
    start = start();
    // TODO: Prompt for end size
    end = end();
    // TODO: Calculate number of years until we reach threshold

    for (int n = 0; start < end; n++)
    {
        int newborn = (float) start / 3;
        int passaway = (float) start / 4;
        start = start + newborn - passaway;
        // TODO: Print number of years
        printf("Years: %i\n", n);

    }

}

int start(void)
{
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    return start;
}

int end(void)
{
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    return end;
}

