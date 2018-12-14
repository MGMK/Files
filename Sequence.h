#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
using namespace std;


class sequence
{
    public:

        sequence();
        sequence(int length);
        sequence(int length , char *seq);
        sequence(const sequence& rhs);
         ~sequence();
        virtual void Print();
        virtual bool validSequence(char * s);
        //        DNA operator+ (DNA d1 , DNA d2)

        //friend ostream& operator<< (ostream&, sequence seq);
        friend char* Align(sequence * s1, sequence * s2);

        char * seq;

    public:
        int length;


};

#endif // SEQUENCE_H
