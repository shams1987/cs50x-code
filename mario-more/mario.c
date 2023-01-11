#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ask for height
    int height = get_int("Height: ");

    // if height is preoper length
    if (height >= 1 && height <= 8)
    {
        // print rows
        for (int i = 1; i < height + 1; i++)
        {
            // for each row
            for (int j = 0; j < height - i; j++)
            {
                // print balnks
                printf(" ");
            }

            for (int k = 0; k < i; k++)
            {
                // print #
                printf("#");
            }

            //print blank
            printf("  ");

            for (int l = 0; l < i; l++)
            {
                // print #
                printf("#");
            }

            //start next line
            printf("\n");
        }
    }
    // if height is wrong length
    else
    {
        // then start main again
        main();

    }
}