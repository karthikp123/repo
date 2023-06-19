//This file contains some utility functions.

#include <stdio.h>

#define MAX_SIZE 100

int asci_to_int (char * str)
{
    int num;
    num = 0;
    int index=0;
    int sign=1;
    int sign_present = 0;
    int digit_started = 0;
    
    for (index = 0; str[index] != '\0'; index++)
    {
        if(str[index] == '+' || str[index] == '-' )
        {
            if(sign_present)
            {
               printf("Error: Invalid input at %d, %c\n", index, str[index]);
               break;
            }
            if(digit_started)
            {
               printf ("Error: Invalid input at %d, %c\n", index, str[index]);
               break;
            }
            
            sign_present = 1;
            
            if(str[index] == '-')
            {
                sign = -1;
            }
        }
        else if (str[index] == ' ' || str [index] == '\t')
        {
            printf ("Error: Invalid inputat at %d, %c\n", index, str[index]);
            break;
        }
        else if (str[index] > '0'  && str[index] < '9')
        {
            digit_started = 1;
            num = num * 10 + (str[index] -'0');
        }
        else
        {
            printf ("Error: invalid input at %d, %c\n",index, str[index]);
            break;
        }
    }
    
    return num*(sign);
}


int main ()
{
    char str[MAX_SIZE];
    int number;
    
    printf ("enter the string number: ");
    gets (str);
    
    number = asci_to_int (str);
    printf ("the number is: %d\n", number);
    
    return 0;
}
