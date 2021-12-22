#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>



int main(int argc, string argv[])
{
    string password = argv[1];
    //check if the key is exist
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //check if the key contain 26 characters
    if (strlen(password) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    //check if the key contain another type of input
    for (int i = 0 ; i < strlen(password); i++)
    {
        if (isalpha(password[i]) == 0)
        {
            printf("key must only contain alphabetical characters\n");
            return 1;
        }
    }
    //check if the key have repeated characters 
    for (int i = 0 ; i < (strlen(password) - 1); i++)
    {
        for (int j = i ; j < (strlen(password) - 1) ; j++)
        {
            if (password[i] == password[j + 1])
            {
                printf("key must not contain repeated characters\n");
                return 1;
            }
        }
       
    } 
    //ask the user to enter the plaintext
    string sms = get_string("write the plaintext: ");
    
    printf("plaintext:%s \n", sms);
    
    int text = strlen(sms);
    //creat empty array of char
    char ciphertext[text + 1];
    
    //cipher the plaintext using for loop
    for (int i = 0 ; i < text ; i++)
    {
        if (islower(sms[i])) //check if the character is lower letter
        {
            char lower = tolower(password[sms[i] - 97]);//keep the lower letter lower
            
            ciphertext[i] = lower;
        }
        else if (isupper(sms[i])) //check if the character is upper letter
        {
            char upper = toupper(password[sms[i] - 65]); //keep the upper letter upper
            
            ciphertext[i] = upper;       
        }
        else 
        {
            //keep any non-alphabetic as it is
            ciphertext[i] = sms[i]; 
        }
        
        ciphertext[i] = ciphertext[i];
        
    } 
    //print the ciphertext
    printf("ciphertext:%s", ciphertext);
    printf("\n");
}