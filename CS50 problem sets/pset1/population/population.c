#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n1, n2, born, died, n3, n;
    n =0;
    do
    {
        n1 = get_int("Enter first people number: ");
    }
    while (n1 < 9);

    // TODO: Prompt for end size
    do
    {
        n2 = get_int("Enter last people number: ");
    }
    while (n2 < n1);

    // TODO: Calculate number of years until we reach threshold
    
    do
    {
        born = n1 / 3 ;
        died = n1 / 4 ; 
        n1 = (n1 + born) - died;
        n++;
    }
    while (n1 < n2);

    // TODO: Print number of years
    
    printf("Years: %i\n", n);
}