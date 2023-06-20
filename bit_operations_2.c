/*This file has the has the operations to get n number of bits from lsb, msb or from the midle.*/

#include <stdio.h>

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
    
    printf("%s\n", binary_str);
    printf ("\n");
}

unsigned int get_bit_msb (int num, int pos_count)
{
    unsigned int mask = 0X00;
    print_binary (mask);
    unsigned int result;
    
    mask = ~(mask);
    print_binary (mask);
    mask = mask >> ((sizeof(int)*8) - pos_count);
    print_binary (mask);    
    
    result = num & mask;
    print_binary (result);
    
    return result;
}

unsigned int get_bit_lsb (int num, int pos_count)
{
    unsigned int mask = 0X00;
    print_binary (mask);
    unsigned int result;
    
    mask = ~(mask);
    print_binary (mask);
    mask = mask << ((sizeof(int)*8) - pos_count );
    print_binary (mask);
    
    print_binary (num);
    result = num & mask;
    print_binary (result);
    result = result >> ((sizeof(int)*8) - pos_count );
    print_binary (result);
    
    return result;
}

unsigned int get_bit_mid (int num, int pos_start, int pos_end)
{
    unsigned int mask = 0X00;
    print_binary (mask);
    unsigned int result;
    
    mask = ~(mask);
    print_binary (mask);
    mask = mask >> (pos_start+((sizeof(int)*8)-(pos_start+(pos_end - pos_start))));
    print_binary (mask);
    mask = mask << ((sizeof(int)*8)-(pos_start+(pos_end - pos_start)));
    print_binary (mask);
    
    result = num & mask;
    print_binary (result);
    
    result = result >> ((sizeof(int)*8)-(pos_start+(pos_end - pos_start)));
    print_binary (result);
}


int main ()
{
    unsigned int msb_result, lsb_result, mid_result;
    msb_result = get_bit_msb (0XA, 4);
    print_binary (0x10);
    printf ("msb result : %x\n",msb_result);
    
    lsb_result = get_bit_lsb (0Xffffffff, 4);
    printf ("lsb result : %x\n", lsb_result);
    
    mid_result = get_bit_mid (0xffffffff, 4, 8);
    printf ("lsb result : %x\n", mid_result);
    
    
    
    //int 
    
    
    
    return 0;
}
