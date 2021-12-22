#include <cs50.h>
#include <stdio.h>

int main()
{
    int sum1, sum2, firstNum, secNum, twoDigits, checkSum, firstTowDigit, numOfDigits, i, j;
    long cardNum, vCardNum;
    
    do
    {   
        //enter credti card number
        cardNum = get_long("Put your credit card number: ");
    }
    while (cardNum <= 0);
    
    
    vCardNum = cardNum;
    firstNum = 0;
    secNum = 0;
    sum1 = 0;
    sum2 = 0;
    i = 0;
    
    // sum from last-to-second digit
    while (cardNum > 0)
    {
        firstNum = cardNum % 10;
        sum1 = sum1 + firstNum;
        cardNum = cardNum / 100 ;
        // count the digits
        i++;
    }
    
    j = 0;

    vCardNum = vCardNum / 10;
     
    //multiply and sum befor the last-to-first digit
    while (vCardNum > 0)
    {
        secNum = vCardNum % 10;
         
        twoDigits = secNum * 2;
        //int n = twoDigits / 10;
        sum2 = sum2 + (twoDigits % 10) + (twoDigits / 10);
         
        vCardNum = vCardNum / 100;
        // count the digits
        j++; 
         
    }
     
    //sum the two first numbers in the card
    firstTowDigit = secNum + firstNum; 
     
    //check if it's vaild or not
    checkSum = sum1 + sum2; 
     
    checkSum = checkSum % 10;
     
    // catculate the number of card digits
    numOfDigits = i + j;
    printf("%d \n",sum1);
    printf("%d \n",sum2 );
    printf("%d \n",numOfDigits );
    printf("%d \n",checkSum);
    
     
    //check the type of the credit card
    if (checkSum == 0 && (twoDigits == 4 || secNum == 4)  && (numOfDigits == 13 || numOfDigits == 16))
    {
        printf("VISA\n");
    }
    else if (checkSum == 0 && numOfDigits == 16 && (firstTowDigit >= 6 && firstTowDigit <= 10))
    {
        printf("MASTERCARD\n");
    }
    else if (checkSum == 0 && numOfDigits == 15 && (firstTowDigit == 7 || firstTowDigit == 10))
    {
        printf("AMEX\n");
    }
    else 
    {
        printf("INVALID\n");
    }
}