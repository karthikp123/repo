#include <stdio.h>

#define IP_BUFFER_SIZE 10


int getline_count (char * buff, int max)
{
    char ch;
    int i=0;
    
    while (1)
    {
        
        ch = getchar();
        buff [i] = ch;
        
        i++;
        
                
        if(ch == EOF || i > max )
        {
            break;
        }
        
        
    }
    
    return i;

}

int main ()
{
    char array[IP_BUFFER_SIZE];
    char * buff = array;
    
    int count;
    
    count = getline_count (buff, IP_BUFFER_SIZE);
    printf("\n");
    printf("No of charecters:%d ", count);
    
    return 0;
}
