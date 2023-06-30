/*This file has the has the operations to get n number of bits from lsb, msb or from the midle.*/

extern "C"
{
#include <stdio.h>
//extern void print_binary (int number);

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


unsigned int get_bit_msb (int num, int pos_count)
{
    unsigned int mask = 0X00;
    printf ("mask:          ");
    print_binary (mask);
    unsigned int result;
    
    mask = ~(mask);
    printf ("~mask:         ");
    print_binary (mask);
    mask = mask >> ((sizeof(int)*8) - pos_count);
    printf ("Final Mask:    ");
    print_binary (mask);    
    
    result = num & mask;
    printf ("result:        ");
    print_binary (result);
    
    return result;
}

unsigned int get_bit_lsb (int num, int pos_count)
{
    unsigned int mask = 0X00;
    printf ("mask:          ");
    print_binary (mask);
    unsigned int result;
    
    mask = ~(mask);
    printf ("~mask:         ");
    print_binary (mask);
    mask = mask << ((sizeof(int)*8) - pos_count );
    printf ("Final Mask:    ");
    print_binary (mask);
    
    result = num & mask;
    printf ("result:        ");
    print_binary (result);
    result = result >> ((sizeof(int)*8) - pos_count );
    printf ("result:        ");
    print_binary (result);
    
    return result;
}

unsigned int get_bit_mid (int num, int pos_start, int pos_end)
{
    unsigned int mask = 0X00;
    printf ("mask:          ");
    print_binary (mask);
    unsigned int result;
    
    mask = ~(mask);
    printf ("~mask:         ");
    print_binary (mask);
    mask = mask >> (pos_start+((sizeof(int)*8)-(pos_start+(pos_end - pos_start))));
    //print_binary (mask);
    mask = mask << ((sizeof(int)*8)-(pos_start+(pos_end - pos_start)));
    printf ("Final Mask:    ");
    print_binary (mask);
    
    result = num & mask;
    printf ("result:        ");
    print_binary (result);
    
    result = result >> ((sizeof(int)*8)-(pos_start+(pos_end - pos_start)));
    printf ("result:        ");
    print_binary (result);
}


int bit_operations_2_main ()
{
    unsigned int msb_result, lsb_result, mid_result;
    
    printf ("lsb, msb, mid bit fetching operations:\n");
    printf ("\n");
    printf ("Sent Number:   ");
    print_binary (0xA);
    msb_result = get_bit_msb (0XA, 4);
    printf ("msb result : %x\n",msb_result);
    printf ("\n");
    
    printf ("Sent Number:   ");
    print_binary (0Xffffffff);
    lsb_result = get_bit_lsb (0Xffffffff, 4);
    printf ("lsb result : %x\n", lsb_result);
    printf ("\n");
    
    printf ("Sent Number:   ");
    print_binary (0Xffffffff);
    mid_result = get_bit_mid (0xffffffff, 4, 8);
    printf ("mid result : %x\n", mid_result);
    
    
    
    //int 
    
    
    
    return 0;
}

#ifndef RELOCATABLE_OBJ
int main ()
{
    bit_operations_2_main ();
}
#endif //RELOCATABLE_OBJ

}

