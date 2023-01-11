#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // prototype
    int count_letters(string text);
    int count_words(string text);
    int count_sentences(string text);

    // text input
    string text = get_string("Text: ");

    // calculations
    float L = count_letters(text) * 100 / count_words(text);
    float S = count_sentences(text) * 100 / count_words(text);
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    // 3 if statements for printing result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }



}

// function for counting letters
int count_letters(string text)
{
    // initalize length and count
    int length = strlen(text);
    int count = 0;

    // loop through text
    for (int i = 0; i < length; i++)
    {
        // only cuont a--z and A--Z
        if (toupper(text[i]) >= 65 && toupper(text[i]) <= 90)
        {
            count += 1;
        }

    }
    return count;
}

// function for counting words
int count_words(string text)
{
    // initalize length and count
    int length = strlen(text);
    int count = 1;

    // loop through text
    for (int i = 0; i < length; i++)
    {
        // only cuont " "
        if (text[i] == ' ')
        {
            count += 1;
        }

    }
    return count;
}

// function for counting sentences
int count_sentences(string text)
{
    // initalize length and count
    int length = strlen(text);
    int count = 0;

    // loop through text
    for (int i = 0; i < length; i++)
    {
        // check for . ? !
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count += 1;
        }

    }
    return count;
}