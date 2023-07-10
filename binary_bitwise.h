#include <iostream>
#include <cassert>
#include <cstring>

#define STATUS_SUCCESS (0)
#define STATUS_FAILURE (-1)
#define STR_SIZE (10)
#define ISSPACE(c) (c == ' ' || c == '\t' || c == '\n')

#define BIT_0 (0x01)
#define BIT_1 (0x02)
#define BIT_2 (0x04)
#define BIT_3 (0x08)
#define BIT_4 (0x010)
#define BIT_5 (0x020)
#define BIT_6 (0x040)
#define BIT_7 (0x080)


using namespace std;

class Byte
{
    private:
    
    	unsigned char byte;
        
    public:
                
        int setBit (unsigned int pos, unsigned int value=1);
        int clearBit (unsigned int pos);
        char * getBitStr (char * buffer);
        void display();
        char * trim_simple (char * str, char *outstr);
        void displayAllForm();
        
        //cunstructors.explains polymorphism here.
        Byte ();
        Byte (unsigned char value);
        Byte (unsigned int value);
        Byte (int value);
        Byte (const char * str);
        
        //operator overloading
        friend Byte operator+ (const Byte &obj1, const Byte &obj2);
        
        
        
        
};


