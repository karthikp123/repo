//This file contains some utility functions.

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 30

#define ASCI_DIFF(x,y) (((x) > (y)) ? ((x) - (y)) : ((y) - (x))) 
#define UPPER(c) ((((c) >= 'a') && (c <= 'z'))?((c) - ASCI_DIFF('a','A')) : c)
#define LOWER(c) ((((c) >= 'A') && (c <= 'Z'))?((c) + ('a' - 'A')) : c)

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


char to_upper (char ch)
{
    char result;
    if (ch >= 'a' && ch <= 'z')
    {
        result = (ch - 'a') + 'A';
    }
    else
    {
        result = ch;
    }
    
    return result;
}

char to_lower (char ch)
{
    char result;
    if (ch >= 'A' && ch <= 'Z')
    {
        result = (ch - 'A') + 'a';
    }
    else
    {
        result = ch;
    }
    
    return result;
}

void string_to_upper (char * str)
{
    
    int index;
    for (index = 0; str [index] != '\0'; index++)
    {
        str[index] = to_upper(str[index]);
    }
    
}

void string_to_lower (char * str)
{
    
    int index;
    for (index = 0; str [index] != '\0'; index++)
    {
        str[index] = to_lower(str[index]);
    }
    
}

void string_copy (char * dest, char * src)
{
   int index;
   index = 0;
    while (src[index] != '\0')
    {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';
}

void mem_copy (char * dest, char * src, int size)
{
    int index;
    
    for (index = 0 ; index <= size ; index++)
    {
        dest[index] = src[index];
    }
    
}

void print_memory (char  * ptr, int size)
{
    int i;
    for (i = 0; i<=size; i++)
    {
        char c = *(ptr+i);
        if(i%7 == 0)
        {
           printf("0X");
        }
        printf ("%x ", c & 0xff);
        if(i % 7 == 6)
        {
            printf ("\n");
        }
    }
    printf ("\n");
}

char *string_cat (char * str1, char * str2)
{   
    char * str = str1;
    
    if (!str1)
    {
        return NULL;
    }
    if (!str2)
    {
        return str1;
    }
    
    while (*str1 != '\0')
    {
        str1++;
    }
    while (*str2 != '\0')
    {
        *str1 = *(str2);
        str1++;
        str2++;
    }
    *str1 = '\0';
    
    return str;
}

int main ()
{
    char str[MAX_SIZE];
    int number;
    
    printf ("enter the string number: ");
    gets (str);
    
    number = asci_to_int (str);
    printf ("the number is: %d\n", number);
    
    char chr;
    char result;
    printf("Enter the charecter to be converted to upper or lower:\n");
    scanf ("%c",&chr);
    result = to_upper (chr);
    
    printf ("To upper: %c\n",result);
    printf("To lower: %c\n", to_lower(result));
    //printf ("upper to lower difference %d\n", ASCI_DIFF('a','A'));
    printf ("Macro result: To upper = %c\n", UPPER(chr));
    printf ("Macro result: To lower = %c\n", LOWER(result));
    char string[30] = "karthik";
    string_to_upper (string);   
    printf ("Strint to upper reslult: %s\n", string);
    string_to_lower(string);
    printf ("String to lower result: %s\n", string);
    
    int size;
    char dest[MAX_SIZE];
    char src[MAX_SIZE];
    printf ("Enter the string to be copied:\n");
    scanf ("%s",src);
    string_copy (dest,src);
    printf ("String copy :copied string in destination: %s\n", dest);
    printf ("Enter the size of the memory to be copied : ");
    scanf ("%d",&size);
    
    mem_copy(dest,src,size);
    int index;
    printf ("Memory copy: copied result to desitnatination: ");
    for (index=0; index < size; index++)
    {
        printf("%c",dest[index]);
    }
    printf ("\n");
    printf ("printing the hex values of the memory\n");
    print_memory (src,30);
    
    
    char str1[30];
    char str2[30];
    char *concat_result;
    printf ("string 1 input: ");
    scanf ("%s",str1);
    printf ("string 2 input: ");
    scanf ("%s",str2);
    concat_result = string_cat (str1,str2);
    printf("The cancatinated string is: %s\n", concat_result);
    
    return 0;
}
