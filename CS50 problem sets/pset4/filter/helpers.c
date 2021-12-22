#include "helpers.h"
#include "math.h"
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avr_gray;
    //loop through each row
    for (int h = 0 ; h < height ; h++)
    {
        //loop through each pixel
        for (int w = 0 ; w < width ; w++)
        {
            //calculate the average of each pixel
            float color_sum = (image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed);
            avr_gray = color_sum / 3;
            image[h][w].rgbtBlue = round(avr_gray);
            image[h][w].rgbtGreen = round(avr_gray);
            image[h][w].rgbtRed = round(avr_gray);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through each row
    for (int h = 0 ; h < height ; h++)
    {
        //loop through each pixel
        for (int w = 0 ; w < width ; w++)
        {
            int r = 0;
            int g = 0;
            int b = 0;
            float sepia_blue = 0;
            float sepia_green = 0;
            float sepia_red = 0;
            // caculate sepia algorithm for each channel in each pixel
            sepia_red = 0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue;
            sepia_green = 0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue;
            sepia_blue = 0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue;
            
            r = round(sepia_red);
            g = round(sepia_green);
            b = round(sepia_blue);
            //make sure the value of each channel between 0 and 255 bit
            if (r > 255)
            {
                r = 255;
                
            }
            else if (r < 0)
            {
                r = 0;
            }
            
            if (g > 255)
            {
                g = 255;
                
            }
            else if (g < 0)
            {
                g = 0;
            }
            
            if (b > 255)
            {
                b = 255;
                
            }
            else if (b < 0)
            {
                b = 0;
            }
            //new value for each pixel
            image[h][w].rgbtBlue = b;
            image[h][w].rgbtGreen = g;
            image[h][w].rgbtRed = r;
            
            
            
        }
    }
    return;
}

//swap fanction using pointers
void swap(RGBTRIPLE *left, RGBTRIPLE *right)
{
    RGBTRIPLE temp = *left;
    *left = *right;
    *right = temp;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0 ; h < height ; h++)//loop through each row
    {
        int wx = width;
        for (int w = 0 ; w < width / 2 ; w++)
        {
            //swap fanction to swap between the firist pixel and the last intil the middle
            swap(&image[h][w], &image[h][wx - 1]);
            wx--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy_image[height][width];
    for (int h = 0; h < height; h++)
    {
        //loop through each row and pixel to copy the size of the original image
        for (int w = 0; w < width; w++)
        {
            copy_image[h][w] = image[h][w];
        }
    }
    
    
    //loop through each row
    for (int h = 0; h < height ; h++)
    {
        //loop throgh each pixel
        for (int w = 0 ; w < width ; w++)
        {
            float sumB = 0;
            float sumG = 0;
            float sumR = 0;
            int num = 0;
            //loop through each row of target area 
            for (int kr = -1 ; kr <= 1 ; kr++)
            {
                //loop through each pixel in target area
                for (int kc = -1 ; kc <= 1 ; kc++)
                {
                    //make sure we are not going out of the array 
                    if (h + kr >= height || h + kr < 0 || w + kc >= width || w + kc < 0)
                    {
                        continue;
                    }
                    //calculate the sum for the target pixel including the target it self
                    sumB = sumB + copy_image[h + kr][w + kc].rgbtBlue; 
                    sumG = sumG + copy_image[h + kr][w + kc].rgbtGreen; 
                    sumR = sumR + copy_image[h + kr][w + kc].rgbtRed;
                    num++;
                }
            }
            //calculate the average 
            float avrB = sumB / num;
            float avrG = sumG / num;
            float avrR = sumR / num;
            image[h][w].rgbtBlue = round(avrB);
            image[h][w].rgbtGreen = round(avrG);
            image[h][w].rgbtRed = round(avrR);
            
            
        }
    }
    return;
}
