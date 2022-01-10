#include "helpers.h"
#include <math.h>
#include <cs50.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // take the average value of Blue, Green & Red
    // and use this to make a grey - scale
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Define the original colors
            int Blue = image[i][j].rgbtBlue;
            int Green = image[i][j].rgbtGreen;
            int Red = image[i][j].rgbtRed;

            // Calculating the average to get a grey scale
            int grey = round((Blue + Green + Red) / 3.0);

            // Now set the new grey in stead of the original colors
            image[i][j].rgbtBlue = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtRed = grey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Define the original colors
            int Blue = image[i][j].rgbtBlue;
            int Green = image[i][j].rgbtGreen;
            int Red = image[i][j].rgbtRed;

            // Calculating and storing the sepia colors
            int sepiaRed = round(0.393 * Red + 0.769 * Green + 0.189 * Blue);
            int sepiaGreen = round(0.349 * Red + 0.686 * Green + 0.168 * Blue);
            int sepiaBlue = round(0.272 * Red + 0.534 * Green + 0.131 * Blue);

            // Cap at 255 max
            int cap = 255;

            // Now set the new sepia colors in stead of the original colors

            // first look at the cap, else set the color
            if (sepiaBlue > cap)
            {
                image[i][j].rgbtBlue = cap;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }

            if (sepiaGreen > cap)
            {
                image[i][j].rgbtGreen = cap;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaRed > cap)
            {
                image[i][j].rgbtRed = cap;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // create a temp value to store
     RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Turn the entire image via a temp copy of the image
            temp[i][j] = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp[i][j];

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // make a float to calculate with
    float total_pixels = 0.0;

    // create new integers for the totals per pixel
    int total_blue = 0;
    int total_green = 0;
    int total_red = 0;

    // Make a copy of the original image to store the blurred inside
    // This is needed, as the calculation needs to use the orginal pixel to calculate with
    // not the blurred pixel.
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // let's make seperate integers to capture the pixel above, below, left and right.
            int above = i - 1;
            int below = i + 1;
            int left = j - 1;
            int right = j + 1;

            // Define the 'total' per pixel, but leave out the 'edge cases'

            // First the top row
            if (i == 0)
            {
                // the top left corner
                if (j == 0)
                {
                    total_blue = image[i][j].rgbtBlue + image[below][j].rgbtBlue +
                                 image[i][right].rgbtBlue + image[below][right].rgbtBlue;
                    total_green = image[i][j].rgbtGreen + image[below][j].rgbtGreen +
                                  image[i][right].rgbtGreen + image[below][right].rgbtGreen;
                    total_red = image[i][j].rgbtRed + image[below][j].rgbtRed +
                                image[i][right].rgbtRed + image[below][right].rgbtRed;
                    total_pixels = 4.0;
                }
                // the top right corner
                else if (j == width - 1)
                {
                    total_blue = image[i][j].rgbtBlue + image[below][j].rgbtBlue +
                                 image[i][left].rgbtBlue + image[below][left].rgbtBlue;
                    total_green = image[i][j].rgbtGreen + image[below][j].rgbtGreen +
                                  image[i][left].rgbtGreen +  image[below][left].rgbtGreen;
                    total_red = image[i][j].rgbtRed + image[below][j].rgbtRed +
                                image[i][left].rgbtRed + image[below][left].rgbtRed;
                    total_pixels = 4.0;
                }
                // all other pixels in the top row
                else
                {
                    total_blue = image[i][j].rgbtBlue + image[below][j].rgbtBlue +
                                 image[i][left].rgbtBlue + image[below][left].rgbtBlue +
                                 image[i][right].rgbtBlue + image[below][right].rgbtBlue;
                    total_green = image[i][j].rgbtGreen + image[below][j].rgbtGreen +
                                  image[i][left].rgbtGreen + image[below][left].rgbtGreen +
                                  image[i][right].rgbtGreen + image[below][right].rgbtGreen;
                    total_red = image[i][j].rgbtRed + image[below][j].rgbtRed +
                                image[i][left].rgbtRed + image[below][left].rgbtRed +
                                image[i][right].rgbtRed + image[below][right].rgbtRed;
                    total_pixels = 6.0;
                }
            }

            // Bottom row
            else if (i == height - 1)
            {
                // bottom right corner
                if (j == width - 1)
                {
                    total_blue = image[i][j].rgbtBlue + image[above][j].rgbtBlue +
                                     image[i][left].rgbtBlue + image[above][left].rgbtBlue;
                    total_green = image[i][j].rgbtGreen + image[above][j].rgbtGreen +
                                      image[i][left].rgbtGreen +  image[above][left].rgbtGreen;
                    total_red = image[i][j].rgbtRed + image[above][j].rgbtRed +
                                    image[i][left].rgbtRed + image[above][left].rgbtRed;
                    total_pixels = 4.0;
                }
                // bottom left corner
                else if (j == 0)
                {
                    total_blue = image[i][j].rgbtBlue + image[above][j].rgbtBlue +
                                 image[i][right].rgbtBlue + image[above][right].rgbtBlue;
                    total_green = image[i][j].rgbtGreen + image[above][j].rgbtGreen +
                                  image[i][right].rgbtGreen + image[above][right].rgbtGreen;
                    total_red = image[i][j].rgbtRed + image[above][j].rgbtRed +
                                image[i][right].rgbtRed + image[above][right].rgbtRed;
                    total_pixels = 4.0;
                }
                // all other pixels in the bottom row
                else
                {
                    total_blue = image[i][j].rgbtBlue + image[above][j].rgbtBlue +
                                 image[i][left].rgbtBlue + image[above][left].rgbtBlue +
                                 image[i][right].rgbtBlue + image[above][right].rgbtBlue;
                    total_green = image[i][j].rgbtGreen + image[above][j].rgbtGreen +
                                  image[i][left].rgbtGreen + image[above][left].rgbtGreen +
                                  image[i][right].rgbtGreen + image[above][right].rgbtGreen;
                    total_red = image[i][j].rgbtRed + image[above][j].rgbtRed +
                                image[i][left].rgbtRed + image[above][left].rgbtRed +
                                image[i][right].rgbtRed + image[above][right].rgbtRed;
                    total_pixels = 6.0;
                }
            }
            // other rows, not being top or bottom
            else
            {
                // left column
                if (j == 0)
                {
                    total_blue = image[i][j].rgbtBlue + image[above][j].rgbtBlue + image[below][j].rgbtBlue +
                                 image[i][right].rgbtBlue + image[above][right].rgbtBlue + image[below][right].rgbtBlue;
                    total_green = image[i][j].rgbtGreen + image[above][j].rgbtGreen + image[below][j].rgbtGreen +
                                  image[i][right].rgbtGreen + image[above][right].rgbtGreen + image[below][right].rgbtGreen;
                    total_red = image[i][j].rgbtRed + image[above][j].rgbtRed + image[below][j].rgbtRed +
                                image[i][right].rgbtRed + image[above][right].rgbtRed + image[below][right].rgbtRed;
                    total_pixels = 6.0;
                }
                // right column
                else if (j == width - 1)
                {
                    total_blue = image[i][j].rgbtBlue + image[above][j].rgbtBlue + image[below][j].rgbtBlue +
                                     image[i][left].rgbtBlue + image[above][left].rgbtBlue + image[below][left].rgbtBlue;
                    total_green = image[i][j].rgbtGreen + image[above][j].rgbtGreen + image[below][j].rgbtGreen +
                                      image[i][left].rgbtGreen +  image[above][left].rgbtGreen + image[below][left].rgbtGreen;
                    total_red = image[i][j].rgbtRed + image[above][j].rgbtRed + image[below][j].rgbtRed +
                                    image[i][left].rgbtRed + image[above][left].rgbtRed + image[below][left].rgbtRed;
                    total_pixels = 6.0;

                }
                // all middle pixels
                else
                {
                    total_blue = image[i][j].rgbtBlue + image[above][j].rgbtBlue + image[below][j].rgbtBlue +
                                     image[i][left].rgbtBlue + image[above][left].rgbtBlue + image[below][left].rgbtBlue +
                                     image[i][right].rgbtBlue + image[above][right].rgbtBlue + image[below][right].rgbtBlue;
                    total_green = image[i][j].rgbtGreen + image[above][j].rgbtGreen + image[below][j].rgbtGreen +
                                      image[i][left].rgbtGreen +  image[above][left].rgbtGreen + image[below][left].rgbtGreen +
                                      image[i][right].rgbtGreen + image[above][right].rgbtGreen + image[below][right].rgbtGreen;
                    total_red = image[i][j].rgbtRed + image[above][j].rgbtRed + image[below][j].rgbtRed +
                                    image[i][left].rgbtRed + image[above][left].rgbtRed + image[below][left].rgbtRed +
                                    image[i][right].rgbtRed + image[above][right].rgbtRed + image[below][right].rgbtRed;
                    total_pixels = 9.0;
                }
            }

            int average_blue = round(total_blue / total_pixels);
            int average_green = round(total_green / total_pixels);
            int average_red = round(total_red / total_pixels);

            // store the blurred in the temp image, and later on copy all into the output
            copy[i][j].rgbtBlue = average_blue;
            copy[i][j].rgbtGreen = average_green;
            copy[i][j].rgbtRed = average_red;
        }
    }

    // Now set the new average in stead of the original colors in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j] = copy[i][j];
        }
    }

}
