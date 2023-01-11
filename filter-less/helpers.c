#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //declare variables
    double average;

    //iterate rows
    for (int row = 0; row < height; row++)
    {
        //iterate colums
        for (int col = 0; col < width; col++)
        {
            //average = sum / 3.0
            average = round((image[row][col].rgbtBlue + image[row][col].rgbtGreen + image[row][col].rgbtRed) / 3.0000);

            //set rgb values to average
            image[row][col].rgbtBlue = average;
            image[row][col].rgbtGreen = average;
            image[row][col].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //declare variables
    float red, green, blue;
    float sepiaRed, sepiaBlue, sepiaGreen;

    //iterate rows
    for (int row = 0; row < height; row++)
    {
        //iterate colums
        for (int col = 0; col < width; col++)
        {
            //color variiables
            red = image[row][col].rgbtRed;
            green = image[row][col].rgbtGreen;
            blue = image[row][col].rgbtBlue;

            //calculate for sepiaColors
            sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            // if sepia values are above 255 set it to 255
            if (sepiaRed > 255)
            {
                image[row][col].rgbtRed = 255;
            }
            else
            {
                image[row][col].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[row][col].rgbtGreen = 255;
            }
            else
            {
                image[row][col].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                image[row][col].rgbtBlue = 255;
            }
            else
            {
                image[row][col].rgbtBlue = sepiaBlue;
            }
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //temporary 2D storage variable
    RGBTRIPLE tmp;

    //iterate through rows
    for (int row = 0; row < height; row++)
    {
        // two pointers restart every row
        int last = width - 1;
        int first = 0;

        //iterate through half the colums and swap
        for (int col = 0; col < width / 2; col++)
        {
            tmp = image[row][first];
            image[row][first] = image[row][last];
            image[row][last] = tmp;

            // the 2 pointers increase and decrease by 1
            last--;
            first++;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //blur image variable
    RGBTRIPLE blur[height][width];

    // variable declaration
    double red, green, blue;
    float counter;

    // iterate rows
    for (int row = 0; row < height; row++)
    {
        // iterate columns
        for (int col = 0; col < width; col++)
        {
            counter = 0;
            red = 0;
            green = 0;
            blue = 0;

            // neighbouring rows
            for (int i = -1; i < 2; i++)
            {
                // neighbouring colums
                for (int j = -1; j < 2; j++)
                {

                    int curRow = row + i;
                    int curCol = col + j;

                    // check if neighbours are valid pixels
                    if (curRow < height && curCol < width && curRow >= 0 && curCol >= 0)
                    {

                        red += image[curRow][curCol].rgbtRed;
                        green += image[curRow][curCol].rgbtGreen;
                        blue += image[curRow][curCol].rgbtBlue;

                        // count increase only when valid
                        counter++;
                    }
                }
            }


            // average of neighboring pizels and erounded
            blur[row][col].rgbtRed = round(red / counter);;
            blur[row][col].rgbtGreen = round(green / counter);
            blur[row][col].rgbtBlue = round(blue / counter);

        }


    }

    //set original image to blurred image

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = blur[row][col];
        }
    }

    return;
}
