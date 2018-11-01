#ifndef VALARRAY_CLASS_H
#define VALARRAY_CLASS_H

#include <cstdlib>
#include <bits/stdc++.h>
#include <iostream>
#include <valarray>
#include <string>

using namespace std;

class Valarray_Class
{
private:
    enum  { Max =20} ;
    valarray <char> data[Max] ;
    int  Size;
public:
    Valarray_Class();
    bool isEmpty ();
    void Clear ();
    int getSize();
    char pop();
    void push(char v);
    void error (string message);
};

#endif // VALARRAY_CLASS_H
