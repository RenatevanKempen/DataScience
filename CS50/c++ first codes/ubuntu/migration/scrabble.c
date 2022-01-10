#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    // Compute and return score for string
    int score_total = 0;

    // look at the string one character at a time
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Make sure all is uppercase
        word[i] = toupper(word[i]);

        // Check wether the char is a letter
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            // deduct the 65 (number of A in ASCII) to get the correct position in POINTS
            int x = word[i] - 65;
            int score_letter = POINTS[x];
            score_total += score_letter;

        }

        // set the points for others characters to 0 points
        else
        {
            score_total += 0;
        }
    }
    return score_total;
}
