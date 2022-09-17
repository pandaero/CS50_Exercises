#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int     grade, letters, words, sentences;
    float   index;
    string  text;
    // Ask for input
    text = get_string("Text: ");

    // Scan the text, count punctuation as sentences, spacing as words.
    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);
    // Check counts
    //printf("Letters: %i, Words: %i, Sentences: %i\n", letters, words, sentences);
    // Coleman-Liau index
    // index = .0588 * L - .296 * S - 15.8
    // L = (letters / 100 words), S = (No. of sentences / 100 words)
    index = (.0588 * 100 * letters / words) - (.296 * 100 * sentences / words) - 15.8;
    grade = round(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 15)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
    return (0);
}

int count_letters(string text)
{
    int i, letters;

    letters = 0;
    i = 0;
    while (text[i] != '\0')
    {
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))
        {
            letters += 1;
        }
        else
        {
            letters += 0;
        }
        i++;
    }
    return (letters);
}

int count_words(string text)
{
    int i, words;

    words = 0;
    i = 0;
    while (text[i] != '\0')
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
        else
        {
            words += 0;
        }
        i++;
    }
    return (words + 1);
}

int count_sentences(string text)
{
    int i, sentences;

    sentences = 0;
    i = 0;
    while (text[i] != '\0')
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
        else
        {
            sentences += 0;
        }
        i++;
    }
    return (sentences);
}
