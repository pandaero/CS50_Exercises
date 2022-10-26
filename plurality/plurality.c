#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates.
#define MAX 9

// Candidates have name and vote count.
typedef struct
{
    string  name;
    int     votes;
}
candidate;

// Global variablie. Array of candidates.
candidate candidates[MAX];

// Global variable. Number of candidates.
int candidate_count;

// Function prototypes.
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    int     i;
    int     voter_count;
    string  name;

    // Check for invalid usage.
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates.
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    voter_count = get_int("Number of voters: ");

    // Loop over all voters.
    for (i = 0; i < voter_count; i++)
    {
        name = get_string("Vote: ");

        // Check for invalid vote.
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election.
    print_winner();
}

// Update vote totals given a new vote.
bool vote(string name)
{
    int i;
    int j;

    // Compare the names against the stored names.
    i = 0;
    while (i < candidate_count)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
        i++;
    }
    return false;
}

// Print the winner (or winners) of the election.
void print_winner(void)
{
    int i;
    int votemax;

    votemax = 0;
    i = 0;
    // Find the maximum votes.
    while (i <= candidate_count)
    {
        if (votemax < candidates[i].votes)
        {
            votemax = candidates[i].votes;
        }
        i++;
    }
    i--;
    // Find the name corresponding to maximum votes.
    while (i >= 0)
    {
        if (candidates[i].votes == votemax)
        {
            printf("%s\n", candidates[i].name);
        }
        i--;
    }
    return;
}
