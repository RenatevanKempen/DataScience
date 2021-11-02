#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    int end;
    do
    {
        start = get_int("Start size: ");
        end = get_int("End size: ");

    }
    while (start < 9);
    return start;
    while (end < start);
    return end;

    // TODO: Prompt for end size
   //int end;
    //do
    //{
    //    end = get_int("End size: \n");
    //    printf("End size = %i\n", end);
    //}
    //while (end < start || end < 9);
    //return end;


    // TODO: Calculate number of years until we reach threshold
    int newborn = start / 3;
    int passaway = start / 4;
    int n = 0;
    for (int n = 0; start < end; start + newborn - passaway; n++)
    // TODO: Print number of years
    {
        printf("Start size = %i\n", start);
        printf("End size = %i\n", end);
        printf("Years: %i\n", n);
    }
}