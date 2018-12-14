#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include <iostream>
using namespace std;

struct Codon
{
  	char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

class CodonsTable
{
    public:
        CodonsTable();
        ~CodonsTable();
 	 	// function to load all codons from the given text file
        void LoadCodonsFromFile(string codonsFileName);
        Codon getAminoAcid(char * value);
        void setCodon(char * value, char AminoAcid, int index);

            Codon codons[64];
};

#endif // CODONSTABLE_H
