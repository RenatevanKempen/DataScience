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

        // First we convert the string input to an int
        int k = atoi(argv[1]);

        printf("argv is: %s\n", argv[1]);
        printf("K is: %i\n", k);
        int y = 0;

        // Check if the array is a string
        for (int w = 0, m = strlen(argv[1]); w < m; w++)
        {
            if (isdigit(argv[1][w]))
            {
                y += 1;
            }
            else
            {
                y += 0;
            }
            return y;
        }

        printf("y is: %i\n", y);

        if (y > 0)
        {
            // Next we prompt the user for a textinput
            string s = get_string("plaintext: ");
            printf("ciphertext: ");

            for (int i = 0, n = strlen(s); i < n; i++)
            {
                if (islower(s[i]))
                {
                    int start = 97, end = 122;
                    int f = s[i] + k;
                    if (f > end)
                    {
                        f = f - end-1 + start;
                        char new_char = (char)f;
                        printf("%c", new_char);
                    }
                    else
                    {
                        char new_char = (char)f;
                        printf("%c", new_char);
                    }

                }
                else if (isupper(s[i]))
                {
                    int start = 65, end = 90;
                    int f = s[i] + k;
                    if (f > end)
                    {
                        f = f - end + start;
                        char new_char = (char)f;
                        printf("%c", new_char);
                    }
                    else
                    {
                        char new_char = (char)f;
                        printf("%c", new_char);
                    }
                }
                else
                {
                    printf("%c", s[i]);
                }
            }
            printf("\n");
            return 0;
        }

        // if the string is non-numerical, return error
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }
    // If there is no string given, return an error
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}




if (f > end)
                    {
                        f = f - end-1 + start;
                        
                        char new_char = (char)f;
                        printf("%c", new_char);
                    }
                    else
                    {
                        char new_char = (char)f;
                        printf("%c", new_char);
                    }