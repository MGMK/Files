#include <iostream>
#include "DNA.h"
#include "CodonsTable.h"
#include "sequence.h"
#include"Protein.h"
#include<iostream>
using namespace std;
void seq_file();
void display_Seq();


int main()
{

    int Choose;
    int Size;
    cout << "1- From DNA To RNA .\n2- From RNA To Protein .\n3- To CodonTable .\n4- TO Create File And But Data in this file.";
    cout << "\n5- TO load Data From File.\n6- TO Align Function .\n7- TO Operators ."<<endl;
    cout << "Enter Your Choose Please :";
    cin >> Choose;
    if(Choose == 1)
    {
        int length = 0;
        DNA_Type t;
        string seq;
        cout<<"Enter sequence :";
        cin>>seq;
        length = seq.size();

        char* dna;
        dna = new char[length + 1];
        dna[length] = {'\0'};
        for(int i=0; i<length; i++)
        {
            dna[i] = seq[i];
        }

        DNA ob(length);
        if(ob.validSequence(dna))
        {
            DNA ob2(length,dna,t);
            ob2.Print();
            int startIndex, Endindex;
            cout << "Enter start index :";
            cin >> startIndex;          /// start index of seq
            cout << "Enter End index :";
            cin >> Endindex;           /// End index of seq
            ob2.BuildComplementaryStrand(startIndex,Endindex); /// get reverse for seq and convert all U to T
            ob2.ConvertToRNA();       /// Convert Every T to U

        }

    }


    else if(Choose == 2)
    {
        int length = 0 ;
        RNA_Type t;
        string seq;
        cout<<"Enter sequence :";
        cin>>seq;
        length = seq.size();
        char* rna;
        rna = new char[length + 1];
        rna[length] = {'\0'};
        for(int i=0; i<length; i++)
        {
            rna[i] = seq[i];
        }
        RNA ob;
        Protein p;
        RNA ob2(length, rna, t);
        if (ob.validSequence(rna)){
            int i ;
            cout << "1- ConvertToDNA .\n2- ConvertToProtein .";
            cin >> i;
            if (i == 1){
                ob2.Print();
                ob2.ConvertToDNA();
            }
            else if (i != 1){
                CodonsTable c;
                p=ob2.ConvertToProtein();
                p.Print();
            }
        }
    }

    else if ( Choose == 3)
    {

        Codon c1;
        CodonsTable c;
        string File_name = "RNA_codon_table.txt";
        c.LoadCodonsFromFile(File_name);
        int x ;
        cout << "1- If Your Want AminoAcid Function.\n";
        cout << "2- IF you Want SetCodon Function.";
        cin>> x ;

        if (x == 1)
        {
            char Value[3];
            cout << "Enter Your Value from Three Char :";
            for(int i = 0 ; i < 3 ; i++)
            {
                cin >> Value[i];
            }
            c1 = c.getAminoAcid(Value);
            cout <<endl <<"The AminoAcid is : "<< c1.AminoAcid;
        }
        else if  (x == 2)
        {
            char Value[3];
            cout << "Enter Your Value from Three Char :";
            for(int i = 0 ; i < 3 ; i++)
            {
                cin >> Value[i];
            }
            char AminoAcid_char;
            cout << "Enter Your AminoAcid char :";
            cin >> AminoAcid_char;
            int index;
            cout << "Enter index to store it in array Codon :";
            cin >> index;
            c.setCodon(Value, AminoAcid_char, index);
            cout << "Success .";
        }


    }
    else if (Choose == 4)
    {
        seq_file();
    }
    else if (Choose == 5)
    {
        display_Seq();
    }

    else if(Choose==6){
        sequence d1;
        //cout << d1.Align("AAAAA" , "TTTTT");
    }
    else if (Choose == 7){
        int length = 0 , length1 = 0;
        DNA_Type t;
        string seq;
        cout<<"Enter sequence one :";
        cin>>seq;
        length = seq.size();
        string seq1;
        cout<<"Enter sequence one :";
        cin>>seq1;
        length1 = seq1.size();
            char* dna;
            dna = new char[length + 1];
            dna[length] = {'\0'};
            for(int i=0; i<length; i++)
            {
                dna[i] = seq[i];
            }

            char* dna1;
            dna1 = new char[length + 1];
            dna1[length1] = {'\0'};
            for(int i=0; i<length1; i++)
            {
                dna1[i] = seq1[i];
            }
            int m;
            cout << "1- Operator ( + ).\n2- Operator ( == ).\n3- Operator ( != ).\nEnter Your Choose : ";
            cin >> m;
            if (m == 1){
                DNA d1 ;
                DNA d2;
                DNA d3;
                d3 = d1 + d2;
                cout <<"Big Seq is :" << d3;
            }
            else if ( m == 2){
                DNA d1 ;
                DNA d2;
                if ( d1 == d2){
                    cout << "False";
                }
                else
                    cout << "True";
            }
            else if ( m == 3){
                DNA d1 ;
                DNA d2;
                if ( d1 != d2){
                    cout << "True";
                }
                else if (d1 == d2)
                    cout << "False";
            }

        }

    }


void seq_file()
{
    string filename;
    cout << "\nEnter your name of file please for example (filename.txt) :";
    if( 'filename' != '\n')
    {
        cin >> filename;
    }
    ofstream myfile_1;
    cout <<"\nEnter element if data :";
    cout << "\npress (ctrl + z) to quit the program .\n";
    myfile_1.open (filename.c_str());
    int counter=0 ;
    char array_1[50] ;
    if ( myfile_1.is_open())
    {
        while (cin >> array_1[counter])
        {
            myfile_1 << array_1[counter] << "  ";
            ++counter;
        }

    }
    else
    {
        cout << strerror(errno) << endl;
    }

}
void display_Seq()
{
    string filename_2;
    cout << "\nEnter your name of file please for example (filename.txt) :";
    if( 'filename_2' != '\n')
    {
        cin >> filename_2;
    }

    ifstream myfile;
    myfile.open(filename_2.c_str());
    int counter1 = 0;
    char array1[50];
    if ( myfile.is_open())
    {
        cout << "Your Seq is :";
        while (myfile >> array1[counter1])
        {
            cout << array1[counter1];
            ++counter1;
        }
        cout << endl;
        int Choose;
        cout << "1- To DNA .\n2- TO RNA.\n";
        cout << "Enter Your Choose Please :";
        cin >> Choose;

        if (Choose == 1)
        {
            DNA_Type t;
            int length = counter1;
            char* dna;
            dna = new char[length];
            dna[length] = {'\0'};
            for(int i=0; i<length; i++)
            {
                dna[i] = array1[i];
            }
            DNA ob(length);
            DNA ob2(length,dna,t);
            ob2.validSequence(dna);
            ob2.Print();
            int startIndex, Endindex;
            cout << "Enter start index :";
            cin >> startIndex;
            cout << "Enter End index :";
            cin >> Endindex;
            ob2.BuildComplementaryStrand(startIndex, Endindex);
            ob2.ConvertToRNA();

        }
        else if (Choose == 2)
        {
            RNA_Type t;
            int length = counter1;
            char* rna;
            rna = new char[length];
            rna[length] = {'\0'};
            for(int i=0; i<length; i++)
            {
                rna[i] = array1[i];
            }
            RNA ob2(length,rna,t);
            ob2.validSequence(rna);
            ob2.Print();
            ob2.ConvertToDNA();
        }
    }
    else
    {
        cout << strerror(errno) << endl;
    }
}
