#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            for (int j = 0; j < voter_count; j++)
            {
                // here we will store the index of the candidate in the preference array
                preferences[voter][rank] = i;
                return true;
            }
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // first check if there are eliminated candidates
    int x = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        // If not eliminated, x should stay 0
        if (!candidates[i].eliminated)
        {
            x += 0;
        }
        else
        {
            x += 1;

        }

    }


    // store the eliminated candidates in an array
    int index_el[candidate_count];
    int el = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        //find the eliminated candidate index
        if (candidates[i].eliminated)
        {
            index_el[el] = i;
            el += 1;
        }
        else
        {
            index_el[el] = -1;
            el += 0;
        }
    }

    // check the next preference if the candidates are eliminated
    int next_preference;

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            for (int t = 0; t < el; t++)
            {
                if (preferences[i][0] == index_el[t])
                {
                    if (preferences[i][1] == index_el[t + 1])
                    {
                        next_preference = preferences[i][2];
                        printf("%i\n", next_preference);
                        break;
                    }
                    else
                    {
                        next_preference = preferences[i][1];
                        printf("%i\n", next_preference);
                        break;
                    }
                }
            }
        }
    }



    for (int j = 0; j < voter_count; j++)
    {
        for (int y = 0; y < candidate_count; y++)
        {
            // Check if there has been an elimination
            // If not, only the first votes should be counted.
            if (x == 0)
            {
                if (preferences[j][0] == y)
                {
                    candidates[y].votes += 1;
                }
                else
                {
                    candidates[y].votes += 0;
                }
            }
            // If there was an elimination, we should only check the candidates in the preferences array that are not eliminated
            else if (!candidates[y].eliminated)
            {
                for (int t = 0; t < el; t++)
                {
                    if (preferences[j][0] == index_el[t])
                    {
                        for (int co = 0; !(preferences[j][co] == y); co++)
                        {
                            if (preferences[j][co] == y)
                            {
                                candidates[y].votes += 1;
                            }
                            break;
                        }
                    }
                    else if (preferences[j][0] == index_el[t] && preferences[j][1] == index_el[t + 1])
                    else if (preferences[j][0] == y)
                    {
                        candidates[y].votes += 1;
                    }
                }
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // look at the majority
    int majority = round((float)voter_count / 2);
    bool result;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes > majority)
        {
            fprintf(stdout, "%s\n", candidates[i].name);
            //printf("%i\n", candidates[i].votes);
            result = true;
            break;
        }
        else if (!candidates[i].eliminated && candidates[i].votes == majority)
        {
            result = false;
        }
        else
        {
            result = false;
        }
    }
    return result;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int smallest = 1;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            int first_votes = candidates[i].votes;
            if (!candidates[i + 1].eliminated && first_votes <= candidates[i + 1].votes)
            {
                smallest = first_votes;
            }
            else if (first_votes <= smallest)
            {
                smallest = first_votes;
            }
        }
    }
    return smallest;



}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int not_equal = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes == min)
            {
                not_equal += 0;
            }
            else
            {
                not_equal += 1;
            }
        }
    }

    for (int j = 0; j < candidate_count; j++)
    {
        if (not_equal > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {

        // Check if there are candidates with the minimum amount of votes and eliminate them
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }

        // If the candidates have more votes, they should stay in the race
        else if (candidates[i].eliminated == false && candidates[i].votes > min)
        {
            candidates[i].eliminated = false;
        }
    }
    return;
}
