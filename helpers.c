#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int av, r, g, b;
            r = image[i][j].rgbtRed;
            g = image[i][j].rgbtGreen;
            b = image[i][j].rgbtBlue;
            av = (int) round((r + g + b) / 3.0);
            image[i][j].rgbtRed = av;
            image[i][j].rgbtBlue = av;
            image[i][j].rgbtGreen = av;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int i, j, r, g, b;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            r = image[i][j].rgbtRed;
            g = image[i][j].rgbtGreen;
            b = image[i][j].rgbtBlue;
            float red = round(.393 * r + .769 * g + .189 * b);
            if (red > 255)
                red = 255;
            image[i][j].rgbtRed = (BYTE) red;
            float green = round(.349 * r + .686 * g + .168 * b);
            if (green > 255)
                green = 255;
            image[i][j].rgbtGreen = (BYTE) green;
            float blue = round(.272 * r + .534 * g + .131 * b);
            if (blue > 255)
                blue = 255;
            image[i][j].rgbtBlue = (BYTE) blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    int i, j, sumRed, sumGreen, sumBlue, count, di, dj, ni, nj;
    RGBTRIPLE copy[height][width];
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;
            count = 0;

            for (di = -1; di <= 1; di++)
            {
                for (dj = -1; dj <= 1; dj++)
                {
                    ni = i + di;
                    nj = j + dj;

                    // Skip neighbors that are outside the image
                    if (ni < 0 || ni >= height || nj < 0 || nj >= width)
                    {
                        continue;
                    }

                    sumRed += copy[ni][nj].rgbtRed;
                    sumGreen += copy[ni][nj].rgbtGreen;
                    sumBlue += copy[ni][nj].rgbtBlue;
                    count++;
                }
            }

            image[i][j].rgbtRed = (BYTE) round((float) sumRed / count);
            image[i][j].rgbtGreen = (BYTE) round((float) sumGreen / count);
            image[i][j].rgbtBlue = (BYTE) round((float) sumBlue / count);
        }
    }
    return;
}
