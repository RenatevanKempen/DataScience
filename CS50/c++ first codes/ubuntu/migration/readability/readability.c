#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int count_letters(string t);
int count_words(string t);
int count_sentences(string t);

int main(void)
{
    // Prompt the user for a text
    string s = get_string("Text: ");

    // Let's count the letters, words and sentences in the text
    int l = count_letters(s);
    int w = count_words(s);
    int sen = count_sentences(s);

    // Define and calculate the formula
    float L = ((float) l / w) * 100;
    float S = ((float) sen / w) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the output with the Grade
    // Check if the resulting index number is 16 or higher
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    // Or less than 1
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    // Else round the index and return the grade
    else
    {
        int x = round(index);
        printf("Grade %i\n", x);
    }
}

int count_letters(string t)
{
    // Let's define the number of letters (l) in the text
    int count = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        // lower case letters
        if (t[i] >= 'a' && t[i] <= 'z')
        {
            count += 1;
        }
        // uppercase letters
        else if (t[i] >= 'A' && t[i] <= 'Z')
        {
            count += 1;
        }
        // ignore all other characters
        else
        {
            count += 0;
        }
    }
    return count;
}

int count_words(string t)
{
    // Let's define the number of words (w) in the text
    int count = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        // count the number of spaces to get the words
        if (isspace(t[i]))
        {
            count += 1;
        }
        // ignore all other characters
        else
        {
            count += 0;
        }
    }
    // As a text starts with a word, we will add 1 to add the first word of a text here
    return count + 1;
}

int count_sentences(string t)
{
    // Let's define the number of sentences sen in the text
    int count = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        // count the number of times there is a point, "!" or "?"
        if (t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            count += 1;
        }
        // ignore all other characters
        else
        {
            count += 0;
        }
    }
    return count;
}