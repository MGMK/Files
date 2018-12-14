#include "CodonsTable.h"
#include <iostream>
#include <fstream>
using namespace std;

CodonsTable::CodonsTable()
{
    //ctor
}

CodonsTable::~CodonsTable()
{
    //dtor
}

void CodonsTable::LoadCodonsFromFile(string codonsFileName){   /// load codons table from file .
    ifstream file(codonsFileName.c_str());
      int c=0;
        while(file>>codons[c].value,file>>codons[c].AminoAcid){
             /// in this 3 cases value no have AminoAcid ( - )
            char arr1[4]="UAA";
            char arr2[4]="UAG";
            char arr3[4]="UGA";
            if(codons[c].value==arr1 || codons[c].value==arr2 ||codons[c].value==arr3)
            {
                codons[c].AminoAcid==' - ';
            }
                c++;
            }

            file.close();
        }



Codon CodonsTable::getAminoAcid(char* value)   /// take value and return char of protein .
{
    for (int i = 0; i < 64; i++)
    {
        if (codons[i].value[0] == value[0] && codons[i].value[1] == value[1] && codons[i].value[2] == value[2])
        ///  i use value[0] and value[1] and value[2] because the value the user input it have 3 char .
            return codons[i];
    }
}


void CodonsTable :: setCodon(char * value, char AminoAcid, int index)
/// take seq of char and take AminoAcid and take index and put all this thing (seq and AminoAcid)
/// in codon array of size 64 in index user will choose it .
{

    Codon temp;
    for (int i = 0; i < 4; i++)
    {
        temp.value[i] = value[i];
    }
    temp.AminoAcid = AminoAcid;
    codons[index] = temp;

}
