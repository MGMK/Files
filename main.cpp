#include <iostream>
#include "Valarray_Class.h"
#include <iostream>
#include <string>
#include <valarray>


using namespace std;


int main ()
{
    Valarray_Class Stack;
    Stack.push ('a');
    Stack.push ('b');
    Stack.push ('c');
    Stack.push ('e');

    cout <<Stack.getSize() <<endl;

    cout << Stack.pop() << " ";
    cout << Stack.pop() << " ";
    cout << Stack.pop() << " ";
    cout << Stack.pop() << " "<<endl;
    cout<<Stack.isEmpty()<<endl;
    Stack.Clear();
    cout<<Stack.isEmpty()<<endl;


}
