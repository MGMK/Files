#ifndef PROTEIN_H
#define PROTEIN_H
#include"sequence.h"
#include"Dna.h"
#include "RNA.h"
#include <bits/stdc++.h>

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
class DNA;
class RNA;
class Protein : public sequence
{
  	private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p);
 	 	Protein (int l,char * p);
 	 	Protein(Protein * p);
 	 	Protein(const Protein& p);
 	 	~Protein();
 	 	void Print();
        bool validSequence(char * s);
 	 	// return an array of DNA sequences that can possibly
                // generate that protein sequence
    //       DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);
};

#endif // PROTEIN_H
