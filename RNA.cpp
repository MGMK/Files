#include "RNA.h"
#include "sequence.h"
#include "DNA.h"
#include"Protein.h"
#include<fstream>
using namespace std;

RNA::RNA(){
    length = 0;
}

RNA::RNA(int l){
    length = l;
}

RNA::RNA(int l,char* seq)
{
    length = l;
    this->seq = new char[length+1];
    this->seq[length]={'\0'};
    for(int i=0 ; i<length ; i++)
    {
        this->seq[i]=seq[i];
    }
}
RNA::RNA(int l,char* seq,RNA_Type atype)
{
    length = l;
    this->seq = new char[length];
    this->seq[length]={'\0'};
    for(int i=0 ; i<length ; i++)
    {
        this->seq[i]=seq[i];
    }
    type = atype;
}

RNA::RNA(const RNA& rhs){   /// copy con if user enter any invalid char .
    if(validSequence(rhs.seq)){
        seq = new char[rhs.length];
        type = rhs.type;
        for(int i =0;i<rhs.length;i++){
            seq[i] = rhs.seq[i];
        }
   }
}

RNA::~RNA()
{
    delete []seq;
}

bool RNA::validSequence(char * s){   /// to check seq is valid or no
        try{
        for(int i=0;i<length;i++){
            if(s[i]!='A' && s[i]!='U' && s[i]!='G' && s[i]!='C'){
                throw (s[i]);
                }
            }
        }
        catch(...){
            cout<<"invalid Seq ."<< endl;
            return false;
        }
    }


void RNA::Print(){
    cout<<"RNA sequence is :"<<seq;
    string types[4] = {"mRNA", "pre_mRNA", "mRNA_exon", "mRNA_intron"};
    string x ;
    cout << "\nEnter Your Seq Type { mRNA , pre_mRNA , mRNA_exon , mRNA_intron } :";
    cin >> x ;
    if ( x == "mRNA" || x == "pre_mRNA" || x == "mRNA_exon" || x == "mRNA_intron")
        cout<<endl<<"RNA type is :"<<x<<endl;
    else{
        while (true){
            cout << "Enter Your Type Again :";
            cin >> x ;
            if ( x == "mRNA" || x == "pre_mRNA" || x == "mRNA_exon" || x == "mRNA_intron"){
                cout<<endl<<"RNA type is :"<<x<<endl;
                break;
            }

        }
    }
}

DNA RNA::ConvertToDNA(){   /// Convert All of T to U .
    char s[length+1];
    int index = 0;
    for(int i=0; i<length+1; i++)
    {
        s[index]=seq[i];
        index++;
    }

    cout<<"DNA sequence is :";
    for(int i=0; i<length; i++)
    {
        if(s[i]=='U')
            s[i]='T';
        else if(s[i]=='A')
            s[i]='A';
        else if(s[i]=='G')
            s[i]='G';
        else if(s[i]=='C')
            s[i]='C';

        cout<<s[i];
    }

    DNA newseq(length , s);


    /// for file Part .
    int m;
    cout << "\n1- to store seq in file .\n2- tO break .";
    cin >> m;
    if (m == 1){
    string filename_2;
    cout << "\nEnter File Name to Save Data on it (file.txt) :";
    if( 'filename_2' != '\n'){                                      /// to Break if User press enter
        cin >> filename_2;
    }
    ofstream myfile;
    myfile.open (filename_2.c_str());
    if (myfile.is_open())
    {
        for(int i = 0 ; i < length+1; i++){
            myfile << s[i];             /// Store data from seq s in my file .
        }
    }
    }
    while(m != 1)
        break;
    return newseq;
}

Protein RNA:: ConvertToProtein(){   /// Convert all of char DNa to Protein using Codon Table .
   if(this->length%3 != 0){
        throw("invalid size");
   }
   char* arrayofamino=new char[this->length/3];
   int counter=0;     /// counter is the index of the amino acid for its iteration.
    CodonsTable codon; /// we make an object from class codons table
    /// in order to have the access on amino acid and the array of value
    codon.LoadCodonsFromFile("RNA_codon_table.txt"); ///we load the file in order to get the amino acid the user want
    for(int i=0 ; i<this->length ; i+=3){
        for(int j=0 ; j<64 ; j++){
            if((codon.codons[j].value[0] == this->seq[i]) && (codon.codons[j].value[1] == this->seq[i+1]) && (codon.codons[j].value[2] == this->seq[i+2]) ){
                arrayofamino[counter]=codon.codons[j].AminoAcid;
                break;
               }
        }
        counter++;
    }
    Protein p1( this->length/3 , arrayofamino);
    return p1;


    /// for file Part .
    int m;
    cout << "\n1- to store seq in file .\n2- tO break .";
    cin >> m;
    if (m == 1){
    string filename_2;
    cout << "\nEnter File Name to Save Data on it (file.txt) :";
    if( 'filename_2' != '\n'){                                      /// to Break if User press enter
        cin >> filename_2;
    }
    ofstream myfile;
    myfile.open (filename_2.c_str());
    if (myfile.is_open())
    {
        for(int i = 0 ; i < length+1; i++){
            myfile << arrayofamino[i];             /// Store data from seq s in my file .
        }
    }
    }
    while(m != 1)
        break;
  //  return arrayofamino;
}

