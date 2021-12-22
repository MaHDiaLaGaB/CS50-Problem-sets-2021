from cs50 import get_string
import re


def main():
    # asking the user to enter the credit card number
    while True:
        card_num = get_string("Put your credit card number: ")
        # check if credit card number in valid or not 
        pattern = '[0-9]{13,16}'
        x = re.match(pattern, card_num)
        if x:
            break
        print("INVALID")
        break

    card_num2 = int(card_num)
    Vcard_num = card_num2
    first_num = 0
    sec_num = 0
    sum1 = 0
    sum2 = 0
    sum3 = 0
    i = 0
    
    # loop on the numbers to sum the numbers beginning from the first
    while card_num2 > 0:
        first_num = int(card_num2 % 10)
        sum3 += first_num
        card_num2 = int(card_num2 / 100)
        i += 1
        
    j = 0
    Vcard_num = Vcard_num / 10
    # loop through the numbers beginning from the second number
    while (Vcard_num > 0):
        sec_num = int(Vcard_num % 10) 
        two_digits = (sec_num * 2)
        sum3 = sum3 + int(two_digits % 10) + int(two_digits / 10)
        Vcard_num = int(Vcard_num / 100)
        j += 1

    first_two_digits = sec_num + first_num
    
    sum3 = sum3 % 10
    num_of_digits = i + j
   # check the type of the credit card according to thier system
    if sum3 == 0 and (two_digits == 4 or sec_num == 4) and (num_of_digits == 13 or num_of_digits == 16):
        print("VISA")
    elif sum3 == 0 and num_of_digits == 16 and (6 <= first_two_digits <= 10):
        print("MASTERCARD")
    elif sum3 == 0 and num_of_digits == 15 and (first_two_digits == 7 or 10):
        print("AMEX")
 
  
if __name__ == "__main__":
    main()