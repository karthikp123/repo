#include <stdio.h>

void display ()
{
    printf("This is my display function") ;
}

int main ()
{
    int count = 0 ;
    for (int index = 0 ; index < 10 ; index++)
    {
       count += index ;
    }
    printf("value of count = %d\n", count) ;
	
    return 0 ;
}
