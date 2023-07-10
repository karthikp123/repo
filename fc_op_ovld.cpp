#include "binary_bitwise.h"

int Byte::setBit (unsigned int pos, unsigned int value)
{
    switch(pos)
    {
        case 0:
            bit_0 = value ? 1 : 0;
            break;
        
        case 1:
            bit_1 = value ? 1 : 0;
            break;
        
        case 2:
            this->bit_2 = value ? 1 : 0;
            break;
        
        case 3:
            this->bit_3 = value ? 1 :0;
            break;
        case 4:
            this->bit_4 = value ? 1 : 0;
            break;
        case 5:
            this->bit_5 = value ? 1 :0;
            break;
        case 6:
            this->bit_6 = value ? 1 : 0;
            break;
        case 7:
            this->bit_7 = value ? 1 : 0;
            break;
        default:
            return STATUS_FAILURE;
            
            
    }
    
    return STATUS_SUCCESS;
}

void Byte::display ()
{
    
    
        /*cout << " " << bit_7 << bit_6 << bit_5 << 
                       bit_4 << bit_3 << bit_2 << 
                       bit_1 << bit_0 ;*/
                      
     printf( " %d%d%d%d%d%d%d%d ", bit_7, bit_6, bit_5, 
        		            bit_4, bit_3, bit_2, 
        			    bit_1, bit_0);
}
char * Byte::display (char * buffer)
{
    if (buffer)
    {
        sprintf(buffer, " %d%d%d%d%d%d%d%d ", bit_7, bit_6, bit_5, 
        				       bit_4, bit_3, bit_2, 
        				       bit_1, bit_0);
    }
    
}

int main ()
{
    Byte byte1;
    byte1.setBit(0,1);
    byte1.setBit(1,0);
    byte1.setBit(4,1);
    byte1.setBit(7,1);
    byte1.display();
    
    return 0;
    
}
