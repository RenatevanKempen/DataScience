#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main(int argc, string argv[])
{
  if (argc != 2)
  {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  else if (argc == 2)
  {
      // First we check if the array is a digit number and if so, convert the string input to an int
      int x = 1;
      int k = 0;
      for (int y = 0; y < x; y++)
      {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
          if (isalpha(argv[1][i]))
          {
            printf("Usage: ./caesar key\n");
            return 1;
          }
        }
        k = atoi(argv[1]);
      }


      // Next we prompt the user for a textinput
      string s = get_string("plaintext: ");
      printf("ciphertext: ");

      // Now we make a loop to iterate over the textinput and encrypt it
      for (int i = 0, n = strlen(s); i < n; i++)
      {
          // First check if the character is lower case
          if (islower(s[i]))
          {
              // for lower case there is a different start and end point in ASCII
              int start = 97, end = 122;
              int f = s[i] + k;

              // make sure that a large key is handled
              if (f > end)
              {
                  do
                  {
                      f = f - end - 1 + start;
                  }
                  while (f > end);
                  char new_char = (char)f;
                  printf("%c", new_char);
              }

              // if it is a small key, return the encryption
              else
              {
                  char new_char = (char)f;
                  printf("%c", new_char);
              }
          }

          // now check if it is uppercase
          else if (isupper(s[i]))
          {
              // this starts and ends at a lower ASCII level
              int start = 65, end = 90;
              int f = s[i] + k;

              // see if there is a large key used
              if (f > end)
              {
                  do
                  {
                      f = f - end - 1 + start;
                  }
                  while (f > end);
                  char new_char = (char)f;
                  printf("%c", new_char);
              }

              // if not, print the encryption
              else
              {
                  char new_char = (char)f;
                  printf("%c", new_char);
              }
          }

          //if is is not alphabet-text, just return the character
          else
          {
              printf("%c", s[i]);
          }
      }
      printf("\n");
      return 0;


  }
  // If there is no string given, return an error
  else
  {
      printf("Usage: ./caesar key\n");
      return 1;
  }

}