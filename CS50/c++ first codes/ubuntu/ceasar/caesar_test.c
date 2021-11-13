#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Check if there is an string given
    if  (argc == 2)
    {

        printf("argv is: %s\n", argv[1]);
        int t = 0;
        // Check if the array is a string
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            do
            {
                t ++;
            }
            while (isdigit(argv[1][i]));
            return t, n;
        }

            if (t == n)
            {
                printf("Success");
                int k = atoi(argv[1]);
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }


    }

        //int k = atoi(argv[1]);
        //printf("k is: %i\n", k);


    }
    // If there is no string given, return an error
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}