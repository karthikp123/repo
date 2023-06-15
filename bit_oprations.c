/* This code tests the the set bit and clear bit operarions. */
#include <stdio.h>

#define SET_BIT(no,pos) ((no) = (no) | ((0X01) << (pos)))
#define CLEAR_BIT(no, pos) ((no) = (no) & (~((0X01) << (pos))))

int set_bit (int number, int position)
{
    int result;
    result = number | (1 << position);
    
    return result;
}


int clear_bit (int number, int position)
{
    int result;
    
    result = number & (~(1 << position));
    
    return result;
}

void print_binary (int number)
{
    int temp = number;
    char binary_str[33] = {0};
    int i;
    for (i = 31; i >= 0 ; i--)
    {
        if(number & 1)
        {
            binary_str[i] ='1';
        }
        else
        {
            binary_str[i] = '0';
        }
        
        number = number >> 1;
    }
    
    binary_str[32] = '\0';
    
    printf("%d, %x, %s\n",temp, temp, binary_str);
}

int main ()
{
    int number;
    int position;
    
    number = 31;
    position = 0;
    
    int result;
    
    printf ("Results using Macro:\n");
    
    printf ("before clearing the position :");
    print_binary(number);
    result = CLEAR_BIT(number, position);
    printf("after the clearing the bit: ");
    print_binary(result);
    
    
    
    printf("\n");
    printf("\n");
    
    
    printf("before setting the position: ");
    print_binary(result);
    result = SET_BIT(result,position);
    printf ("after setting the position:");
    print_binary(result);
    
    printf("\n");
    
    printf ("Results using function:\n");
    
    printf ("before clearing the position :");
    print_binary(number);
    result = clear_bit(number, position);
    printf("after the clearing the bit: ");
    print_binary(result);
    
    
    
    printf("\n");
    printf("\n");
    
    
    printf("before setting the position: ");
    print_binary(result);
    result = set_bit(result,position);
    printf ("after setting the position:");
    print_binary(result);
    
    
    return 0;
}
