#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through each pizel of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Add the averages of the red, green and blue values and divide by 3 to get the average
            // and this must be rounded.
            // Then the values of red, green and blue are all set to average
            int average =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Define a new RGBTRIPLE which will be used for swapping the pixels
    RGBTRIPLE temp;

    // Iterate through the height and half the width of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // We set the temp to the current pixel and then swap the current pixel to the pixel of
            // the other horizontal half which it will swap with (width - j - 1), and then set that
            // pixel to temp.
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image so we can alter the image without changing the pixels
    // used to create the blur
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Iterate through the height and the width
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Define values for the averages of each colour
            int avg_red = 0;
            int avg_green = 0;
            int avg_blue = 0;
            float count = 0;

            // Iterate through the 3x3 box which surround the pixel
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    // Ensure it is within the image
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        // If it is, add the red, green and blue to the coresponding averages
                        // and increment the count
                        avg_red += copy[k][l].rgbtRed;
                        avg_green += copy[k][l].rgbtGreen;
                        avg_blue += copy[k][l].rgbtBlue;
                        count++;
                    }
                }
            }

            // Change the pixel in the image to the averages divided by the number of pixels
            image[i][j].rgbtRed = round(avg_red / count);
            image[i][j].rgbtGreen = round(avg_green / count);
            image[i][j].rgbtBlue = round(avg_blue / count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE nil = {0, 0, 0};

    // Create a copy of image so we can alter the image without changing the pixels
    // used to highlight the edges
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Iterate through the height and the width
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Define new variables to use the Sobel operator
            RGBTRIPLE top_left = copy[i - 1][j - 1];
            RGBTRIPLE mid_left = copy[i][j - 1];
            RGBTRIPLE bottom_left = copy[i + 1][j - 1];
            RGBTRIPLE top_right = copy[i - 1][j + 1];
            RGBTRIPLE mid_right = copy[i][j + 1];
            RGBTRIPLE bottom_right = copy[i + 1][j + 1];
            RGBTRIPLE top_mid = copy[i - 1][j];
            RGBTRIPLE bottom_mid = copy[i + 1][j];

            // Define if statements for the edges of the map
            if (i == 0)
            {
                top_left = nil;
                top_right = nil;
                top_mid = nil;
            }
            if (j == 0)
            {
                top_left = nil;
                mid_left = nil;
                bottom_left = nil;
            }
            if (i == height - 1)
            {
                bottom_left = nil;
                bottom_mid = nil;
                bottom_right = nil;
            }
            if (j == width - 1)
            {
                top_right = nil;
                mid_right = nil;
                bottom_right = nil;
            }

            // Use the values in the Sobel operator for each colour in the pizel
            int G_xRed = -top_left.rgbtRed - 2 * mid_left.rgbtRed - bottom_left.rgbtRed +
                         top_right.rgbtRed + 2 * mid_right.rgbtRed + bottom_right.rgbtRed;
            int G_yRed = -top_left.rgbtRed - 2 * top_mid.rgbtRed - top_right.rgbtRed +
                         bottom_left.rgbtRed + 2 * bottom_mid.rgbtRed + bottom_right.rgbtRed;
            int G_xGreen = -top_left.rgbtGreen - 2 * mid_left.rgbtGreen - bottom_left.rgbtGreen +
                           top_right.rgbtGreen + 2 * mid_right.rgbtGreen + bottom_right.rgbtGreen;
            int G_yGreen = -top_left.rgbtGreen - 2 * top_mid.rgbtGreen - top_right.rgbtGreen +
                           bottom_left.rgbtGreen + 2 * bottom_mid.rgbtGreen +
                           bottom_right.rgbtGreen;
            int G_xBlue = -top_left.rgbtBlue - 2 * mid_left.rgbtBlue - bottom_left.rgbtBlue +
                          top_right.rgbtBlue + 2 * mid_right.rgbtBlue + bottom_right.rgbtBlue;
            int G_yBlue = -top_left.rgbtBlue - 2 * top_mid.rgbtBlue - top_right.rgbtBlue +
                          bottom_left.rgbtBlue + 2 * bottom_mid.rgbtBlue + bottom_right.rgbtBlue;

            // Calculate the new values of the colours in the pixel
            int G_R = round(sqrt((G_xRed * G_xRed) + (G_yRed * G_yRed)));
            int G_G = round(sqrt((G_xGreen * G_xGreen) + (G_yGreen * G_yGreen)));
            int G_B = round(sqrt((G_xBlue * G_xBlue) + (G_yBlue * G_yBlue)));

            // Check if any are larger than 255, if so, set to 255
            if (G_R > 255)
            {
                G_R = 255;
            }
            if (G_G > 255)
            {
                G_G = 255;
            }
            if (G_B > 255)
            {
                G_B = 255;
            }

            // Change the pixel in the image to the new values
            image[i][j].rgbtRed = G_R;
            image[i][j].rgbtGreen = G_G;
            image[i][j].rgbtBlue = G_B;
        }
    }
    return;
}
