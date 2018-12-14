#include "DNA.h"
#include "sequence.h"
#include "RNA.h"
#include <bits/stdc++.h>
#include<fstream>
using namespace std;

DNA::DNA(){
    length = 0;
    startIndex = 0;
    endIndex = 0;
}

DNA::DNA(int l){
    length = l;
}

DNA::DNA(int l,char * seq){
    length = l;
    this->seq = new char[length];
    this->seq[length]={'\0'};
    for(int i=0 ; i<length ; i++)
    {
        this->seq[i]=seq[i];
    }
}

DNA::DNA(int l,char* seq, DNA_Type atype)
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

DNA::DNA(const DNA& rhs){   /// this is the copy cons .
//    if(validSequence(rhs.seq)){
        seq = new char[rhs.length];
        type = rhs.type;
        for(int i =0;i<rhs.length;i++){
            seq[i] = rhs.seq[i];
        }
   }
//}

DNA::~DNA()
{
    delete []seq;
}

bool DNA::validSequence(char * s){  /// to check function is valid or no .
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

void DNA::Print(){   /// function to print seq
    cout<<"DNA sequence is :"<<seq<<endl;
    string types[4] = {"promoter", "motif", "tail", "noncoding"};
    string x ;
    cout << "Enter Your Seq Type {promoter , motif , tail, noncoding} :";
    cin >> x ;
    if ( x == "promoter" || x == "motif" || x == "tail" || x == "noncoding")
        cout<<endl<<"DNA type is :"<<x<<endl;
    else{
        while (true){
            cout << "Enter Your Type Again :";
            cin >> x ;
            if ( x == "promoter" || x == "motif" || x == "tail" || x == "noncoding"){
                cout<<endl<<"DNA type is :"<<x<<endl;
                break;
            }

        }
    }
}

void DNA::BuildComplementaryStrand(int s,int e){ /// get reverse for seq and convert all U to T and take start index and end index .
    complementary_strand = new DNA;
    startIndex = s;
    endIndex = e;
    int index=0;
    int Size = 0;
    if(startIndex == -1 && endIndex == -1)
    {
        for(int i = length-1; i>= 0; i--)
        {
            if(seq[i]!='\0')
            {
                complementary_strand->seq[index] = seq[i];
                index++;
            }
        }
        Size =index;
    }
    else
    {
        for(int i = endIndex; i>= startIndex; i--)
        {
            if(seq[i]!='\0')
            {
                complementary_strand->seq[index] = seq[i];
                index++;
            }
        }
        Size = index;
        index = 0;
    }
    for(int i =0; i<Size; i++)
    {
        if(complementary_strand->seq[i]=='A')
            complementary_strand->seq[i] = 'T';
        else if(complementary_strand->seq[i]=='T')
            complementary_strand->seq[i] = 'A';
        else if(complementary_strand->seq[i]=='C')
            complementary_strand->seq[i] = 'G';
        else if(complementary_strand->seq[i]=='G')
            complementary_strand->seq[i] = 'C';
    }
    cout<<"Complementary strand is :";
    for(int i = 0; i<Size; i++)
    {
        cout<<complementary_strand->seq[i];
    }
    index = Size =0;
    cout<<endl<<endl;
}

RNA DNA::ConvertToRNA(){   /// convert all U to T .
    /// size of seq equal end index - start index .
    int Size = (endIndex - startIndex);
    char s[Size];
    s[Size]={'\0'};  /// for Bugs .
    for(int i=0;i<Size;i++){
        s[i]=complementary_strand->seq[i];
    }
    for(int i=0;i<Size;i++){
        if(s[i]=='T')
            s[i]='U';
    }
    cout << "The RNA Seq is :";
    for(int i = 0 ; i < Size; i++){
        cout << s[i];
    }

    RNA newseq(Size , s , mRNA);
    /// for file Part .
    int i ;
    cout << "\n1- to store seq in file .\n2- tO break .";
    cin >> i;
    if (i == 1){
    string filename_2;
    cout << "\nEnter File Name to Save Data on it (file.txt) :";
    if( 'filename_2' != '\n'){                                      /// to Break if User press enter
        cin >> filename_2;
    }
    ofstream myfile;
    myfile.open (filename_2.c_str());
    if (myfile.is_open())
    {
        for(int i = 0 ; i < Size; i++){
            myfile << s[i];             /// Store data from seq s in my file .
        }
    }
    }
    while(i != 1)
        break;
    return newseq;
}


istream& operator>> (istream& in, DNA& d)
{
    int length ;
    string s="Invalid Sequence of DNA.";
    cout<<"Please, Enter the length of DNA : ";
    cin>>length;
    d.seq =  new char [length+1];
    d.seq[length]='\0';
    for(int i=0 ; i<length ; i++)
    {
        in>>d.seq[i];
        if(d.seq[i]!='A'&&d.seq[i]!='T'&&d.seq[i]!='C'&&d.seq[i]!='G')
            throw s;
    }
    return in;
}

ostream& operator<< (ostream& out, DNA& d)
{
    for(int i=0 ; i<strlen(d.seq) ; i++)
    {
        out<<d.seq[i];
    }
    return out;
}

bool operator== (DNA d1, DNA d2)
{
    if(strlen(d1.seq)==strlen(d2.seq))
    {
        int counter=0;
        for(int i=0 ; i<strlen(d1.seq) ; i++)
        {
            if(d1.seq[i]==d2.seq[i])
            {
                counter++;
            }
            else
                break;
        }
        if(counter==strlen(d1.seq))
            return true;
        else
            return false;
    }
    else
        return false;
}
bool operator!= (DNA d1, DNA d2)
{
    if(strlen(d1.seq)==strlen(d2.seq))
    {
        int counter=0;
        for(int i=0 ; i<strlen(d1.seq) ; i++)
        {
            if(d1.seq[i]!=d2.seq[i])
            {
                return true;
                break;
            }
            else
                counter++;
        }
        if(counter !=0)
            return false;
        else
            return true;
    }
    else
        return true;
}
DNA operator+ (DNA d1, DNA d2)
{
    DNA d3;
    d3.seq=new char [strlen(d1.seq)+strlen(d2.seq)+1];
    d3.seq[strlen(d1.seq)+strlen(d2.seq)]='\0';
    int x=0;
    for(int i=0 ; i<strlen(d1.seq); i++)
    {
        d3.seq[i]=d1.seq[i];
    }
    for(int i=strlen(d1.seq) ; i<(strlen(d1.seq)+strlen(d2.seq)) ; i++)
    {
        d3.seq[i]=d2.seq[x];
        x++;
        cout << d3.seq[i];
    }
    return d3;
}







