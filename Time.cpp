#include "Time.h"

Time :: Time ()
{
    time_t cur_time = time(0);
    tm *time = localtime(&cur_time);
    
    H = time->tm_hour;
    M = time->tm_min;
    S = time->tm_sec;
    
}

long Time :: getTime ()
{
    return (H*100000 + M*100 + S);
}

void Time :: getTime (int &h, int &m, int &s)
{
    h = H;
    m = M;
    s = S;
}

int main ()
{
    Time tm;
    int h,m,s;
    cout << tm.getTime();
    tm.getTime(h,m,s);
    cout <<endl<< h << ":" << m <<":"<< s;
    return 0;
}
