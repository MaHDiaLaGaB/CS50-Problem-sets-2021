#include "helpers.h"
#include "math.h"
#include <stdlib.h>

void swap (RGBTRIPLE *left, RGBTRIPLE *right);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avr_gray;
    for(int h = 0 ; h < height ; h++)
    {
        for (int w = 0 ; w < width ; w++)
        {
            float color_sum = (image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed);
            avr_gray = color_sum / 3;
            image[h][w].rgbtBlue = round(avr_gray);
            image[h][w].rgbtGreen = round(avr_gray);
            image[h][w].rgbtRed = round(avr_gray);
        }
    }
    return;
}

void swap (RGBTRIPLE *left, RGBTRIPLE *right)
{
    RGBTRIPLE temp = *left;
    *left = *right;
    *right = temp;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{



    for (int h = 0 ; h < height ; h++)
    {
        int wx = width;
        for (int w = 0 ; w < width / 2 ; w++)
        {
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
        for (int w = 0; w < width; w++)
        {
            copy_image[h][w] = image[h][w];
        }
    }
    
    
    
    for (int h = 0; h < height ; h++)
    {
        for (int w = 0 ; w < width ; w++)
        {
            float sumB = 0;
            float sumG = 0;
            float sumR = 0;
            int num = 0;
            
            for (int kr = -1 ; kr <= 1 ; kr++)
            {
                
                for(int kc = -1 ; kc <= 1 ; kc++)
                {
                    if(h + kr >= height || h + kr < 0 || w + kc >= width || w + kc < 0)
                    {
                        continue;
                    }
                    
                    sumB = sumB + copy_image[h + kr][w + kc].rgbtBlue; 
                    sumG = sumG + copy_image[h + kr][w + kc].rgbtGreen; 
                    sumR = sumR + copy_image[h + kr][w + kc].rgbtRed;
                    num++;
                }
            }
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy_image[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy_image[h][w] = image[h][w];
        }
    }
    
    float Gx_kernel [3][3] ={{-1 , 0 , 1} , {-2 , 0 , 2 }, {-1 , 0 , 1}};
    
    float Gy_kernel [3][3] = {{-1 , -2 , -1} ,{ 0 , 0 , 0 },{ 1 , 2 , 1}};
    
    
    
    for (int h = 0; h < height ; h++)
    {
        for (int w = 0 ; w < width ; w++)
        {
            
            float Gx_blue = 0;
            float Gy_blue = 0;
            float Gx_green = 0;
            float Gy_green = 0;
            float Gx_red = 0;
            float Gy_red = 0;
            
            int kernel_cell = 0;
            
            for (int kr = -1 ; kr <= 1 ; kr++)
            {
                
                for(int kc = -1 ; kc <= 1 ; kc++)
                {
                    if(h + kr >= height || h + kr < 0 || w + kc >= width || w + kc < 0)
                    {
                        continue;
                    }
                    
                    Gx_blue += copy_image[h + kr][w + kc].rgbtBlue * Gx_kernel[h + kr][w + kc];
                    Gy_blue += copy_image[h + kr][w + kc].rgbtBlue * Gy_kernel[h + kr][w + kc];
                    
                    Gx_green += copy_image[h + kr][w + kc].rgbtGreen * Gx_kernel[h + kr][w + kc];
                    Gy_green += copy_image[h + kr][w + kc].rgbtGreen * Gy_kernel[h + kr][w + kc];
                    
                    Gx_red += copy_image[h + kr][w + kc].rgbtRed * Gx_kernel[h + kr][w + kc];
                    Gy_red += copy_image[h + kr][w + kc].rgbtRed * Gy_kernel[h + kr][w + kc];
                    
                    
                    
                }
            }
            
            //kernel_cell++;
            
            float sobel_blue = powf(Gx_blue , 2) + powf(Gy_blue , 2);
            float sobel_green = powf(Gx_green , 2) + powf(Gy_green , 2);
            float sobel_red = powf(Gx_red , 2) + powf(Gy_red , 2);
            
            float G_blue = sqrt(sobel_blue);
            float G_green = sqrt(sobel_green);
            float G_red = sqrt(sobel_red);
            
            if(G_blue > 255)
            {
                G_blue = 255;
                
            }else if(G_green > 255)
            {
                G_green = 255;
                
            }else if(G_red > 255)
            {
                G_red = 255;
            }
            
            
            image[h][w].rgbtBlue = round(G_blue);
            image[h][w].rgbtGreen = round(G_green);
            image[h][w].rgbtRed = round(G_red);
    
        }
    }
    
    
    return;
}
