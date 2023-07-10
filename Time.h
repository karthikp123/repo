#include <iostream>
#include <ctime>

using namespace std;

class Time
{
    private:
        int H;
        int M;
        int S;
    
    public:
        Time();
        
        long getTime ();
        void getTime (int &h, int &m, int &s);
};


