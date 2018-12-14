#include "Protein.h"
#include"Sequence.h"
#include <bits/stdc++.h>
class DNA ;
using namespace std;
Protein :: Protein (int l,char * p)
{
    length = l;
    this->seq = new char[length+1];
    this->seq[length]='\0';
    for(int i=0 ; i<length ; i++)
    {
        seq[i]=p[i];
    }
}

Protein::Protein()
{
    length=0;
}

Protein::~Protein()
{
    seq = NULL;
    delete [] seq;
}

void Protein :: Print()
{
    cout<<"Protein sequence is : ";
    for(int i=0 ; i<length ; i++)
    cout<<seq[i];
//    string types[4] = {"Hormon","Enzyme","TF","Cellular_Function"};
//    cout<<endl<<"Protein type is :"<<types[type]<<endl;
}

bool Protein::validSequence(char * s){   /// check valid function and it need to fixed it because the protein not have A , C , G , T chars .
    try{
    for(int i=0;i<length;i++){
        if(s[i]!='A' && s[i]!='T' && s[i]!='G' && s[i]!='C'){
            throw (s[i]);
        }
    }
    }
    catch(...){
        cout<<"invalid Seq ."<< endl;
        return false;
    }
}


//DNA* Protein :: GetDNAStrandsEncodingMe(const DNA & bigDNA)
//{
//    cout << "hey" << endl;
//}


