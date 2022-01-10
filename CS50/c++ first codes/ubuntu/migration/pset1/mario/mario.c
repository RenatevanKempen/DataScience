#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for the height
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h > 8 || h < 1);

    // Print the pyramid according to the specified height

    // number of times the pyramid should print:
    int p = 1;
    // number of times we need a space:
    int x = h - 1;

    // make the pyramid
    for (int i = 0; i < p; i++)
    {

        for (int n = 0; n < h; n++)
        {
            printf("%.*s", x, "        ");
            x--;
            for (int j = 0; j <= n; j++)
            {

                printf("#");
            }
            printf("\n");
        }

    }
}