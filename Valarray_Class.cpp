#include "Valarray_Class.h"
#include <iostream>
#include <valarray>
using namespace std;
Valarray_Class:: Valarray_Class ()
    {
        Size = 0;
    }

    bool Valarray_Class:: isEmpty ()
    {
        if (Size == 0 )//&&  data[0].Size() == 0)
            return true;
        else
            return false;
    }

    void Valarray_Class:: Clear ()
    {
        Size = 0;
        for (int i =0 ; i < Max ; i++)
            data[i].resize(0);
        cout<<"The Stack is clear now "<<endl;

    }
    int Valarray_Class:: getSize()

    {
       return Size;
    }

    char Valarray_Class::pop()
    {
        if (Size == 0)
            error("Stack Underflow");
        char t = data[Size--][0];
        return t;
    }

    void Valarray_Class:: push(char z)
    {
        if (Size == Max)
            error("Stack Overflow");
        data[ ++Size ] = std :: valarray<char> (z , 1);

    }

void Valarray_Class:: error (string message)
{
    cout << "\n" << message << "\n";
    exit (1);
}
