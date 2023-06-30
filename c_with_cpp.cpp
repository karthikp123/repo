#include <iostream>

using namespace std;

extern "C"
{
    int fn1 ()
    {
        printf ("welcome to c");
    }
}

int main ()
{
     cout << "welcome to cpp"<<endl;
     fn1();
     
     extern "C"
     {
         printf("hello");
     }
    
    return 0;
}
