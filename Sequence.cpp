#include "sequence.h"
#include"Dna.h"
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
class DNA;
sequence::sequence()
{
    int length=0;
    seq = new char[length];
}
sequence::sequence(int length)
{
    this->length=length;
    seq = new char[length];
}
sequence::sequence(const sequence& rhs)
{
    for(int i=0 ; i<length ; i++)
        seq[i]=rhs.seq[i];
}

sequence::~sequence(){
    delete []seq;
}


void sequence::Print(){}
bool sequence::validSequence(char * s)
{

}


ostream& operator<< (ostream& out, const sequence& s1)
{
    for(int i = 0; i < s1.length; ++i){
        out << (char) s1.seq[i];
    }
    return out;
}



/// This cons take length and seq of chars .
sequence::sequence(int length,char *seq){
    this->length = length;
    this->seq=new char[length];
    for(int i=0;i<length;i++){

        this->seq[i]=seq[i];
    }


}
/// Lcs Function .
char* Align(sequence* s1, sequence* s2){
    int**LCSarray = new int*[strlen(s1->seq)+1];
    for(int i=0; i<strlen(s1->seq)+1; ++i){
        LCSarray[i]=new int[strlen(s2->seq)+1];

        }
            for(int i=0; i<=strlen(s1->seq); ++i){

            for(int j=0; j<= strlen(s2->seq); ++j){
                    LCSarray[i][j]=0;
            }
    }
    for(int i=0; i<=strlen(s1->seq); ++i){
        for(int j=0; j<=strlen(s2->seq); ++j){
            if(i==0 || j==0){
                LCSarray[i][j]=0;

            }
            else if(s1->seq[i-1]==s2->seq[j-1]){
                LCSarray[i][j]= LCSarray[i-1][j-1]+1;
            }
            else{
                LCSarray[i][j]=max(LCSarray[i][j-1],LCSarray[i-1][j]);
            }

        }
    }
    int index=LCSarray[strlen(s1->seq)][strlen(s2->seq)];
    char*ResultString = new char[index +1];
    ResultString[index]='\0';
    int i=strlen(s1->seq),j=strlen(s2->seq);
    while(i>0 && j>0){
            if(s1->seq[i-1]==s2->seq[j-1]){
                ResultString[index-1]=s1->seq[i-1];
                i--;
                j--;
                index--;
            }
            else if(LCSarray[i-1][j]>LCSarray[i][j-1]){
                i--;

            }
            else
                j--;
    }
    delete[] LCSarray;
    return ResultString;
}


bool operator== (sequence d1, sequence d2)
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
bool operator!= (sequence d1, sequence d2)
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
sequence operator+ (sequence d1, sequence d2)
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
    }
    return d3;
}
