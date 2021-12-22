#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int counting_words(string text);
int counting_char(string text);
int counting_sent(string text);

int main(void)
{
    string text = get_string("Text: ");
    
    int wordSum = counting_words(text);
    int alphaSum = counting_char(text);
    int sent = counting_sent(text);
     
    printf("%d \n",wordSum);
    printf("%d \n",alphaSum);
    printf("%d \n",sent);
    //calculation
    float index = (((alphaSum * 100.0) / wordSum) * 0.0588) - (((sent * 100.0) / wordSum) * 0.296) - 15.8;
    int grad = round(index);
    
    if (grad < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grad > 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", grad);
    }
    
    
}


int counting_words(string text)
{
    int word = 0;
    
    for (int i = 0 ; text[i] != '\0' ; i++)
    {
        if (text[i] == ' ' && text[i + 1] != ' ')
        {
            word++;
        }
        
    }
    word++;
    
    return (word);
}

int counting_char(string text)
{
    int alpha = 0;
    
    for (int i = 0 ; text[i] != '\0' ; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            alpha++;
        }
    }
    
    return (alpha);
}

int counting_sent(string text)
{
    int sent = 0;
    
    for (int i = 0 ; text[i] != '\0' ; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sent++;
        }
    }
    return (sent);
}