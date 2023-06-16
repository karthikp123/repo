#include <stdio.h>
#include <string.h>

#define IP_BUFFER_SIZE 100

int getline_count (char * buffer, int max)
{
    char ch;
    int i=0;
    
    while ((ch = getchar()) != EOF && i < max)
    {
        buffer [i] = ch;
        i++;
    }
    
    buffer[i] = '\0';
    
    return i;

}

int main ()
{
    char buffer [IP_BUFFER_SIZE];
    
    int count;
    
    printf ("size of array : %ld\n", sizeof(buffer));
    count = getline_count (buffer, IP_BUFFER_SIZE);
    printf ("\n");
    printf ("No of charecters: %d\n", count);
    //printf("%s\n",buffer);
    
    int i,ns=0,nl=0;
    for (i=0 ; buffer[i] != '\0' ; i++)
    {
        if(buffer[i] == ' ')
        {
            ns++;
        }
        if(buffer[i] == '\n')
        {
            nl++;
        }
    }
    
    printf ("No. of lines: %d\n", nl);
    printf ("No. of spaces: %d\n", ns);
    
    
    return 0;
}
