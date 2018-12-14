#ifndef RNA_H
#define RNA_H
#include"Codonstable.h"
#include "Sequence.h"
#include "Dna.h"
#include "Protein.h"
#include <iostream>

using namespace std;

class DNA;
class CodonsTable;
class Protein;


enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA: public sequence
{
    public:

        RNA();
        RNA(int l);
        RNA(int l,char* seq);
        RNA(int l,char* seq,RNA_Type atype);
        RNA(const RNA& rhs);
        ~RNA();
        void Print();
        bool validSequence(char * s);
        Protein ConvertToProtein();
        DNA ConvertToDNA();


//        friend RNA operator+ (RNA d1, RNA d2);
//        friend bool operator!= (RNA d1 , RNA d2);
//        friend bool operator== (RNA d1, RNA d2);
//        friend istream& operator>> (istream& in, RNA& d);
//        friend ostream& operator<< (ostream& out, RNA& d);

    protected:

    private:
        RNA_Type type;
};

#endif // RNA_H
