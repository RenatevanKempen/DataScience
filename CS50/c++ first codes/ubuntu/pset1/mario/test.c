#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt the user for the height
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h > 8 || h < 1);;

    //print the piramid according to the specified height

    // number of times the piramid should print:
    for (int i = 1; i < h; i++)
    {
            for (int j = 0; j <= h; j++)
            {
                 printf("#");
            }
            printf("\n");
     }
}