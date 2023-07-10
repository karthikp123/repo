#include <iostream>

#define STATUS_SUCCESS (0)
#define STATUS_FAILURE (-1)

using namespace std;

class Byte
{
    private:
    	unsigned int bit_0:1;
        unsigned int bit_1:1;
        unsigned int bit_2:1;
        unsigned int bit_3:1;
        unsigned int bit_4:1;
        unsigned int bit_5:1;
        unsigned int bit_6:1;
        unsigned int bit_7:1;
        
    public:
        
        
        int setBit (unsigned int pos, unsigned int value);
        void display ();
        char * display (char * buffer);
        
        Byte () : bit_0(0), bit_1(0), bit_2(0), bit_3(0), bit_4(0), bit_5(0), bit_6(0), bit_7(0){};
        
};


