#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    
    do 
    {
        n = get_int("Enter the desired hight:  "); // ask the user for the hight
    }
    while ((n > 8) || (n < 1)); // logical condition 
    
    for (int i = 0; i < n ; i++)
    {
        // printing the spaces
        for (int x = 0 ; x < (n - i - 1) ; x++)
        {
            printf(" ");
        }
        // printing the boxex
        for (int j = 0 ; j <= i ; j++)
        {
            printf("#");
        }
        //go to new line each time
        printf("\n");
    }
    
}