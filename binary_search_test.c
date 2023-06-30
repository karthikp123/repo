

extern "C"
{
#include <stdio.h>

#define ARRAY_SIZE 10

void print_array (int * array, int size)
{
    int i;
    
    if (!array)
    {
        printf ("Invalid pointer");
    }
    
    for (i = 0; i < size; i++)
    {
        printf ("%d ", array[i]);
    }
    printf ("\n");
}

void sort_array (int * array, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


int binary_search (int *array, int length, int key)
{
        if(!array)
        {
            printf ("Invalid pointer!\n");
        }
	int low=0, mid, high = length;
	while (low <= high)
	{
		mid = (low +(high -1))/2;
		
		if (array[mid] == key)
			return mid;
			
		else if (array[mid] < key)
			low = mid +1;
			
		else 
			high = mid -1;
			
	}
	
	return -1;
}


int binary_search_test_main ()
{
    int array[ARRAY_SIZE], temp,size;
    
    size =0;
    while (1)
    {
        printf ("ente the number: ");
        scanf ("%d", &temp);
        if(temp == -1)
        {
            break;
        }
        else
        {
            array[size] = temp;
            size++;
        }
        
    }
    
    printf ("entered set of values: ");
    print_array (array,size);
    sort_array (array, size);
    printf ("sorted array: ");
    print_array (array,size);
    
    int position,key;
    printf ("enter the key: ");
    scanf ("%d", &key);
    
    position =binary_search (array, size,key);
    printf ("found at position: %d",position);
    
    
    
    return 0;
}

#ifndef RELOCATABLE_OBJ

int main ()
{
    binary_search_test_main ();
    return 0;
}
#endif //RELOCATABLE_OBJ

}

