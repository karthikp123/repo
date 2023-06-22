#include <stdio.h>
#include <string.h>

#define IP_BUFFER_SIZE 100
#define WORD_OUT 0
#define WORD_IN 1
#define IS_WHITESPACE(ch) (((ch) == ' ') || \
                          ((ch) == '\n') || \
                          ((ch) == '\0') ||\
                          ((ch) == '\t'))


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

int word_count (char * buffer)
{
    int state = WORD_OUT;
    int wc=0;
    int index;
    
    for (index =0; index <=  IP_BUFFER_SIZE && buffer[index] ; index++)
    {
        if (state == WORD_OUT)
        {
            if(!IS_WHITESPACE (buffer[index]))
            {
                state = WORD_IN;
            }
        }
        else if ( state == WORD_IN)
        {
            if (IS_WHITESPACE (buffer[index]))
            {
                wc += 1;
                state = WORD_IN;
            }  
        }
    }
    if (state == WORD_IN)
    {
        wc++;
    }
    
    return wc;
}



int word_count_main ()
{
    char buffer [IP_BUFFER_SIZE];
    
    int count, wc;
    
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
    
    printf ("\n");
    printf ("Word count:\n");
    wc = word_count (buffer);
    printf ("No. of words in the string is: %d\n",wc);   
    return 0;
}

#ifndef RELOCATABLE_OBJ
int main ()
{
    
    word_count_main ();
}
#endif //RELOCATABLE_OBJ
