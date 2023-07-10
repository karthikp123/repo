#include "binary_bitwise.h"

Byte::Byte(): byte(0){};

Byte::Byte(unsigned char value)
{
    byte = 0xff & value;
}

Byte::Byte(unsigned int value)
{
    byte = (unsigned char) (0xff & value);
}

Byte::Byte(int value)
{
    byte = (unsigned char) (0xff & value);
}

int Byte::setBit (unsigned int pos, unsigned int value)
{
    	if(pos > 7)
    	{
    	    return STATUS_FAILURE;
    	}
    
        if(value)
        {
             byte = byte | (0x01 << pos);
        }
        else
        {
             byte = byte & (~(0x01 << pos));
        }
                
    return STATUS_SUCCESS;
}

int Byte::clearBit (unsigned int pos)
{
    if(pos > 7)
    {
        return STATUS_FAILURE;
    }
    else
    {
        byte = byte & (~(0x01 << pos));
    }
    
    return STATUS_SUCCESS;
}

char * Byte :: getBitStr (char * buffer)
{
    if(!buffer)
    {
        cout << "Error: Invalid pointer";
        return NULL;
    }
    for (int i = 0, j = 7; i < 8, j >=0; i++, j--)
    {
        if (byte & (0x01 << i))
        {
            buffer[j] = '1';
        }
        else
        {
            buffer[j] = '0';
        }
    }
    buffer[8] = '\0';
    
    return buffer;
}

void Byte :: display ()
{
    char buffer[20];
    
    cout << " " << getBitStr(buffer) << " ";
}

void Byte :: displayAllForm()
{
    
    cout  << (unsigned int)byte;
    cout << " " << hex <<(unsigned int)(byte);
    display();
}

char * Byte :: trim_simple (char * str, char * outstr)
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
     
     if (f_index >= 0)
     {
         for (i = 0; f_index <= l_index; i++, f_index++)
         {
             outstr[i] = str[f_index];
         }
     }
     
     
     str[i] = '\0';
     
     return outstr;
}

Byte :: Byte (const char * str)
{
    char  outstr[STR_SIZE];
    strncpy (outstr,str,STR_SIZE);  
    trim_simple (outstr,outstr);
    //cout << "trimed str:#" << outstr<<"#"<<endl; 
    int i, str_len;
    str_len = strlen(outstr);
    for (i = 0; i<str_len; i++)
    {
        if (outstr[i] != '0' && outstr[i] != '1')
        {
            assert(0);
        }
    }
    int j;
    this->byte =0;
    i = strlen(outstr)-1;
    for (i, j =0 ; j <8; j++, i--)
    {
        if (outstr[i] == '1')
        {
            setBit(j);
        }
    }
    //display ();
}


Byte operator+ (const Byte &obj1, const Byte &obj2)
{
    unsigned int var, carry;
    Byte res;
    var = (unsigned int)(obj1.byte) + (unsigned int)(obj2.byte);
    res = (unsigned char)(0xff & var);
    
    carry = (0xf00 & var) ? 1 : 0;
    
    return res;
    
    
}

int binary_bitwise_main ()
{
    char str[] = "11100011";
    //char str[] = "111000Aa";
    //char str[] = "11100011 1";
    
    
    Byte byte1 (str);
        
    //byte1.setBit (0,1);
    //byte1.setBit (4,1);
    
    //byte1.display ();
    
    Byte obj1("10110000");
    Byte obj2("01001000");
    Byte obj4 = "10101100";
    Byte obj5 = 12; 
    
    Byte obj3 = obj1 + obj2;
    //obj3.display();
    //obj4.display();
    //obj5.display();
    obj5.displayAllForm();
    
    return 0;
    
}

#ifndef RELOCATABLE_OBJ

int main ()
{
    binary_bitwise_main ();
}

#endif //RELOCATABLE_OBJ
