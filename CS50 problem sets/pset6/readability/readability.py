from cs50 import get_string
import re

# counting charactars


def counting_char(text):
    char = 0
    for i in text:
        if i.islower() or i.isupper():
            char += 1
    return char
    
# counting words


def counting_words(text):
    
    words = text.count(' ') + 1
    return words
    
# counting sentences


def counting_sent(text):
    sent = text.count('.') + text.count('?') + text.count('!')
    return sent 
    

def main():
    # promting the user to enter text
    text = get_string("Text: ")
    # calling the counting functions
    word_sum = counting_words(text)
    alpha_sum = counting_char(text)
    sent_sum = counting_sent(text)
    # calculating Coleman-Liau index  
    index = (((alpha_sum * 100.0) / word_sum) * 0.0588) - (((sent_sum * 100.0) / word_sum) * 0.296) - 15.8
    grad = (round(index))
    
    # check the grad level
    if grad < 1:
        print("Before Grade 1")
    elif grad > 16:
        print("Grade 16+")
    else:
        print("Grade ", grad)


if __name__ == "__main__":
    main()
