#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            int promedio = round((blue + green + red) / 3);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = promedio;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            float red = image[i][j].rgbtRed;

            int BlueSepia = round(.272 * red + .534 * green + .131 * blue);
            int GreenSepia = round(.349 * red + .686 * green + .168 * blue);
            int RedSepia = round(.393 * red + .769 * green + .189 * blue);

            if(BlueSepia > 255)
            {
                BlueSepia = 255;
            }
            if(GreenSepia > 255)
            {
                GreenSepia = 255;
            }
            if(RedSepia > 255)
            {
                RedSepia = 255;
            }

            image[i][j].rgbtBlue = BlueSepia;
            image[i][j].rgbtGreen = GreenSepia;
            image[i][j].rgbtRed = RedSepia;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int TBlue, TGreen, TRed;
            TBlue = TGreen = TRed = 0;
            float cont = 0.00;

            for(int k = -1; k < 2; k++)
            {
                for(int y = -1; y < 2; y++)
                {
                    int Upx = i + k;
                    int Upy = j + y;

                    if(Upx < 0 || Upx > (height - 1) || Upy < 0 || Upy > (width - 1))
                    {
                        continue;
                    }

                    TBlue += image[Upx][Upy].rgbtBlue;
                    TGreen += image[Upx][Upy].rgbtGreen;
                    TRed += image[Upx][Upy].rgbtRed;

                    cont++;
                }

                temp[i][j].rgbtBlue = round(TBlue / cont);
                temp[i][j].rgbtGreen = round(TGreen / cont);
                temp[i][j].rgbtRed = round(TRed / cont);
            }
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}
