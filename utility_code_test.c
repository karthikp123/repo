//This file contains some utility functions.

extern "C"
{


#include "utilities.h"

#define ISSPACE(c) (c == ' ' || c == '\t' || c == '\n')
#define BIG_ENDIAN 1
#define LITTLE_ENDIAN 2
#define IS_BIGENDIAN (get_endian() == BIG_ENDIAN)
#define IS_LITTLEENDIAN (get_endian() == LITTLE_ENDIAN)

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

void get_line (char * str, int max)
{
    char c;
    int i;
    i = 0;
    while ((c = getchar() ) != '\n' && i < max)
    {
        str[i] = c;
        i++;
    }
    str[i] = '\0';
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

//This function is used in the c often to clear the set of memory.
//for example whole structure can be set to zero using this small function.
char *mem_set (char * ptr, char c, int size)
{
    if (!ptr)
    {
        printf("Invalid string");
        return NULL;
    }
    
    int i;
    for (i = 0; i < size; i++)
    {
        *ptr = c;
         ptr++;
    }
}

int string_length (char * str)
{
if (!str)
    {
        printf("Invalid string");
        return NULL;
    }
    
    int count;
    count =0;
    while (str[count] != '\0')
    {
        count++;
    }
    
    return count;
}

char * string_reverse (char * str)
{
    if (!str)
    {
        printf("Invalid string");
        return NULL;
    }
    
    int string_len;
    string_len = string_length (str);
    int i,j;
    char temp;
    for (i = 0, j = string_len-1 ; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        
    }
}

/*void trim (char * str)
{
    int first_index, last_index,i,j;
    first_index = -1;
    last_index = -1;
    
    
    for (i=0; str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'); i++)
    {
        first_index = i;
        
    }
    first_index = i;
    printf ("forst index: %d\n",first_index);
    
    for (i=first_index; str[i] != '\0'; i++ )
    {
        if (str[i] != ' ' && str[i] != '\t')
            last_index = i;
    }
    last_index = i;
    printf ("last index: %d\n",last_index);
    
    for (i=first_index, j=0; i <= last_index; i++, j++)
    {
        str[j] = str[i];
    }
    
    str[j] = '\0';
}*/

char * trim_simple (char * str)
{
    int f_index = -1;
    int l_index = -1;
    int i;
    
    if (!str)
    {
        printf ("Invalid pointer");
        return NULL;
    }
     
     for (i = 0; str[i] != '\0'; i++ )
     {
         if (!(ISSPACE(str[i])))
         {
             if (f_index ==-1)
             {
                 f_index = i;
             }
             
             l_index = i;
         }
     }
     
     for (i = 0; f_index <= l_index; i++, f_index++)
     {
         str[i] = str[f_index];
     }
     
     str[i] = '\0';
     
     return str;
}

int get_endian()
{
    int int_val = 0x1A2B3C4D;
    char *chr_ptr = (char *) &int_val;
    
    if ((*chr_ptr) == 0x4d)
    {
        return LITTLE_ENDIAN;
    }
    else
    {
        return BIG_ENDIAN;
    }
}

int string_cmp (char *s, char * t)
{
    int i,res;
    for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
    {
        return 0;
    }
    res= s[i]-t[i];
    return res > 0 ? 1 : -1;
}

char * str_search (char *str, char * key)
{
    int i,index;
    static char res[30] = "";
    for ( i = 0; str[i] != '\0'; i++)
    {
    	
        for (int j = 0; str[i] == key[j]; j++)
        {
            
            if (j == 0)
            {
                index = i;
            }
            res[j] = str[i];
            
            if (key[j+1] == '\0')
            {
                res[j+1] = '\0';
                return res;
            }
            
            i++;
            
        }
    }
    return NULL;
}

int utilities_main ()
{
    char str[MAX_SIZE];
    int number;
    
    printf ("\n");
    printf ("String to integer conversion:\n");
    printf ("enter the string number: ");
    get_line (str, sizeof(str));
    number = asci_to_int (str);
    printf ("\n");
    printf ("the number is: %d\n", number);
    printf ("\n");
    
    printf ("charecter upper and lower functions:\n");
    char chr;
    char result;
    printf("Enter the charecter to be converted to upper or lower:\n");
    scanf ("%c",&chr);
    result = to_upper (chr);
    
    printf ("To upper: %c\n",result);
    printf("To lower: %c\n", to_lower(result));
    
    printf ("Macro result: To upper = %c\n", UPPER(chr));
    printf ("Macro result: To lower = %c\n", LOWER(result));
    printf ("\n");
    
    printf ("string Toupper and Tolower functions:\n");
    char string[30] = "karthik";
    printf ("Input string : %s", string);
    string_to_upper (string);   
    printf ("Strint to upper reslult: %s\n", string);
    string_to_lower(string);
    printf ("String to lower result: %s\n", string);
    printf ("\n");
    
    printf ("String copy function;\n");
    int size;
    char dest[MAX_SIZE];
    char src[MAX_SIZE];
    printf ("Enter the string to be copied:\n");
    scanf ("%s",src);
    string_copy (dest,src);
    printf ("String copy :copied string in destination: %s\n", dest);
    printf ("\n");
    
    printf ("Memory copy function:\n");
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
    printf ("\n");
    
    printf ("printing the hex values of the memory:\n");
    print_memory (src,30);
    printf ("\n");
    
    printf ("String concat function:\n");
    char str1[30];
    char str2[30];
    char *concat_result;
    printf ("string 1 input: ");
    get_line (str1, sizeof(str1));
    printf ("string 2 input: ");
    get_line (str2, sizeof(str2));
    concat_result = string_cat (str1,str2);
    printf("The cancatinated string is: %s\n", concat_result);
    printf ("\n");
    
    //memset
    char memset_str[10];
    mem_set (memset_str, 0 , sizeof(memset_str));
    printf ("%s\n",memset_str);
    
    //string length
    //int l = string_length ("kartik_p");
    //printf("%d\n",l);

    //strint reverse
    printf ("String riverse:\n");
    char reverse_str[30]= "karthikp";
    printf ("Input string: %s\n",reverse_str);
    string_reverse (reverse_str);
    printf ("Reversed string: %s\n", reverse_str);
    printf ("\n");
    
    //trim function
    printf ("trim function:\n");
    char trim_str[30];
    printf ("enter the string:\n");
    get_line(trim_str, sizeof(trim_str));
    char * trim_result = trim_simple (trim_str);
    printf ("after trimmig:%s\n", trim_result);
    printf ("\n");
    
    //check big endian or little endian
    if (IS_BIGENDIAN)
    {
        printf ("it is a big endian function\n");
    }
    else if (IS_LITTLEENDIAN)
    {
        printf ("it is a little endian\n");
    }
    
    //string compare
    printf ("string compare function:\n");
    char compare_s1[30]="karthi", compare_s2[30] = "karthi";
    int compare_result;
    
    printf ("enter the string: ");
    scanf ("%s",compare_s1);
    printf ("enter the string2: ");
    scanf ("%s",compare_s2);
    compare_result = string_cmp (compare_s1, compare_s2);
    if (compare_result == 0)
    {
        printf ("%d : comapre successfull\n", compare_result);
    }
    else
    {
        printf ("%d : comapre unsuccessfull\n", compare_result);
    }
    printf ("\n");
    
    //string search
    printf ("string search function:\n");
    char search_source[30], search_key[30];
    char *search_result;
    printf ("enter the string: ");
    scanf("%s", search_source);
    printf ("enter the string to search: ");
    scanf("%s",search_key);
    search_result = str_search (search_source, search_key);
    if(search_result == NULL)
    {
        printf ("no mathch found\n");
    }
    else
    {
        printf ("match found: %s\n",search_result);
    }
    
    
    return 0;
}

#ifndef RELOCATABLE_OBJ
int main ()
{

   utilities_main();
}
#endif // RELOCATABLE_OBJ

}
