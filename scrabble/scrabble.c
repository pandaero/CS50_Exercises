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
        printf("Player 1 Wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int i;
    int score = 0;

    // Compute and return score for string
    i = 0;
    while (word[i] != '\0')
    {
        if (word[i] > 64 && word[i] < 91)
        {
            score += POINTS[word[i] - 65];
        }
        else if (word[i] > 96 && word[i] < 123)
        {
            score += POINTS[word[i] - 97];
        }
        else
        {
            score += 0;
        }
        i++;
    }
    //ASCII Table
    // Uppercase 65 - 90
    // Lowercase 97 - 122
    return (score);
}
