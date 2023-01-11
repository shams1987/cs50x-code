#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// implement command line argsuments
int main(int argc, string argv[])
{
    // command line argument needs name of program and key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // loop through the key to check if they are digits
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // ask for text
    string text = get_string("plaintext: ");
    // print cipher
    printf("ciphertext: ");

    int text_length = strlen(text);
    // loop through text
    for (int i = 0; i < text_length; i++)
    {
        // check for uppercase
        if (isupper(text[i]))
        {
            printf("%c", (((text[i] - 65) + atoi(argv[1])) % 26) + 65);
        }
        // check for lowercase
        else if (islower(text[i]))
        {
            printf("%c", (((text[i] - 97) + atoi(argv[1])) % 26) + 97);
        }
        // the rest stays the same
        else
        {
            printf("%c", text[i]);
        }

    }
    printf("\n");
}