#include <cs50.h>
#include <stdio.h>

int main(void)
{   
    //asking for the user name
    string name = get_string("What is your name?\n");
    //print out "hello" followed by the user name
    printf("Hello, %s\n", name);
}