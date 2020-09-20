#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //capture input
    string name = get_string("What is your name?\n");
    //print to console
    printf("hello, %s\n", name);
}