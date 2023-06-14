#include <stdio.h>

int g_myglobal_var;
static int gs_my_global_static_var;

double red (int *i, char *str, int *array)
{
    double c = 2.0;
    printf("Running Red Function\n");
    
    char * ptr = (char *) 0X123;
    printf("%s\n", ptr);

    return c;
}

int orange (char *str, int b, float c)
{
    int d = 10;
    double value;
    int arr[10]= {1,2,3};

   // printf ("Running Orange Function\n");
    value = red (&d, "karthi",arr);
    return d;
}


float yellow (char ch_array[], char * c)
{
    float d = 4.89;
    int value;
    printf ("Running Yellow Function\n");
    value = orange ("orange",2, 3.67);
    //printf ("Running Yellow Function\n");
    return d;
}

char *green (int array[], char a)
{
    char *c = "yellow";
    float value;
    char arr[10] = "hello";
    char chr = 'h';
    printf("Running Green Function\n");
    value = yellow (arr, &chr);
    //printf("Running Green Function\n");

    return c;
}

int *blue (char *c, short int f)
{
    static int d= 10;
    int *e = &d;
    char *value;
    int arr[10] = {1,2,3,4};
    printf ("Running Blue Function\n");
    value = green (arr, 'k');
    //printf ("Running Indigo Function\n");

    return e;
}

char indigo (char a, int c)
{
    char d ='k';
    int * value;
    char chr = 'i';
    printf ("Running Indigo Function\n");
    value = blue (&chr, 2);
   // printf ("Running Indigo Function\n");

    return d;
}


int violet (int a, int b)
{
    printf ("Running Violet Function\n");
    int c = a + b;
    char value;
    value = indigo ('j', 12);
    /*printf ("Running Violet Function\n");*/
    return c;
}

int main (int argc, char * argv[])
{
    int a = violet (1,2);
    return 0;
};
