/*This file is to demostrate the variable amount of arguments as input*/

#include <stdarg.h>
#include  <stdio.h>

int average (int num, ...)
{
    va_list valist;
    
    int sum, i;
    sum = 0;
    
    va_start (valist, num);
    
    for (i=0; i< num; i++)
    {
        sum += va_arg (valist, int);     
    }
    
    va_end (valist);
    
    return sum/num;

}

int var_length_test_main ()
{
    printf ("Average of numbers from 2 to 4: %d\n", average (2,3,4));
    
    return 0;
}

#ifndef RELOCATABLE_OBJ
 int main ()
 {
     var_length_test_main ();
 }
 #endif //RELOCATABLE_OBJ
