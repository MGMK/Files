#ifndef DNA_H
#define DNA_H
#include "sequence.h"
#include "RNA.h"
#include <iostream>
using namespace std;

class RNA;

enum DNA_Type{promoter, motif, tail, noncoding};
class DNA:public sequence
{
    public:
        DNA();
        ~DNA();
        DNA(int l);
        DNA(int l,char * seq);
        DNA(int l,char * seq, DNA_Type atype);
        DNA(const DNA& rhs);
        void Print();
        void BuildComplementaryStrand(int s,int e);
        RNA ConvertToRNA();
        bool validSequence(char * s);

        friend DNA operator+ (DNA d1, DNA d2);
        friend bool operator!= (DNA d1 , DNA d2);
        friend bool operator== (DNA d1, DNA d2);
        friend istream& operator>> (istream& in, DNA& d);
        friend ostream& operator<< (ostream& out, DNA& d);

    protected:

    private:
        DNA_Type type;
        DNA * complementary_strand;
        int length;
        int startIndex;
        int endIndex;

};

#endif // DNA_H
