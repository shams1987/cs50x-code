#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // not a valid input
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // open input file card.raw
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Cannot open: %s\n", input_file);
        return 2;
    }

    //array to store 512 bytes
    BYTE buffer[512];

    //declaration for counting of image
    int count = 0;

    //set output to null
    FILE *output_file = NULL;

    //string to hold a filename
    char *filename = malloc(8 * sizeof(char));

    // Repeat until end of card:
    while (fread(&buffer, 512, 1, input_file) == 1)
    {
        // If start of a new JPEG:
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // not first JPEG, close previous
            if (!(count == 0))
            {
                fclose(output_file);
            }
            // Initialise file
            sprintf(filename, "%03i.jpg", count);
            output_file = fopen(filename, "w");
            count++;
        }
        // JPEG has been found
        if (count != 0)
        {
            //write to file
            fwrite(&buffer, 512, 1, output_file);
        }
    }
    //close input and output files
    free(filename);
    fclose(input_file);
    fclose(output_file);
    return 0;



}