#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i = 0;
    int x = get_int("x: ");

    while (i < x)
    {
        printf("still not there yet\n");
        i++;
    }
}
