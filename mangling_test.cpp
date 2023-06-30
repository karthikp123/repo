#include <stdio.h>
#include <iostream>

extern "C"
{
    void CNonMangledfile()
    {
        printf ("from non-mangled");
    }
}

void CMangled ()
{
    
    printf ("from mangled");
}

class Myclass
{
     public:
         int a;
         static int b;
         void cppMangledFunction ()
         {
             //cout << "hello from cppmangled";
         }
};

int mangling_test_main ()
{
    Myclass a;
    CNonMangledfile();
    CMangled ();
    
}

#ifndef RELOCATABLE_OBJ

int main ()
{
    mangling_test_main ();
}

#endif //RELOCTABLE_OBJ
