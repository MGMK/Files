#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int row , int col , int num[])
{
    this->row = row;
    this->col = col;
    this->data = new int* [row];
    for(int i = 0 ; i < row ; i++){
        this->data[i]=new int [col];
    }
}


Matrix Matrix:: operator+(Matrix mat1){

    int data3[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
    Matrix mat3(mat1.row,mat1.col , data3);  /// mat3 row = mat1 row and mat3 col = mat1 col .
    if(mat1.row == this->row && this->col==mat1.col){
        for (int i = 0 ; i < mat1.row; i++){
            for ( int j = 0 ; j < mat1.col; j++){
                mat3.data[i][j] = this->data[i][j] + mat1.data[i][j];      /// this step add data of mat1 and data from constuctor .

            }

        }
         return mat3 ;  ///  return new matrix .
    }

}

Matrix Matrix:: operator-(Matrix mat1){

    int data3[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
    Matrix mat3(mat1.row,mat1.col , data3);  /// mat3 row = mat1 row and mat3 col = mat1 col .
    if(mat1.row==this->row && this->col==mat1.col){
     for (int i = 0 ; i < mat1.row; i++){
        for ( int j = 0 ; j < mat1.col; j++){
            mat3.data[i][j] = this->data[i][j] - mat1.data[i][j];  /// this step - data of mat1 and data from constructor
        }
    }
     return mat3 ; ///  return new matrix .

    }

}

Matrix Matrix:: operator*(Matrix mat1){


    if(mat1.row == this->col){
        int data3[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
        Matrix mat3(this->row , mat1.col , data3 );  ///create mat3 will include the row from constructor and the row from mat1

        for(int i=0; i < row; ++i)
        {
            for(int j=0; j < col; ++j)
            {
                mat3.data[i][j] = mat1.data[i][j] * this->data[i][j];   /// data of mat3 = data of mat1 * data from constructor
            }
        }
        return mat3;   ///  return new matrix .
    }
}

Matrix Matrix:: operator+ (int scalar){

                int data1[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
        Matrix mat1(row,col , data1);
        for(int i=0; i<row; ++i)
        {
        for(int j=0; j<col; ++j)
            {
                mat1.data[i][j] = this->data[i][j]+scalar; ///  new matrix mat1 data  =  data in constructor + scalar the user will input it
            }
        }
        return mat1;
}

Matrix Matrix:: operator- (int scalar){

        int data1[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
        Matrix mat1(row,col , data1);
        for(int i=0; i<row; ++i)
        {
        for(int j=0; j<col; ++j)
            {
                mat1.data[i][j] = this->data[i][j]-scalar;   ///  new matrix mat1 data  =  data in constructor - scalar the user will input it
            }
        }
        return mat1;
}

Matrix Matrix:: operator* (int scalar){
        int data1[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
        Matrix mat1(row,col , data1);
        for(int i=0; i<row; ++i)
        {
        for(int j=0; j<col; ++j)
            {
                mat1.data[i][j] = this->data[i][j]*scalar; ///  new matrix mat1 data  =  data in constructor * scalar the user will input it
            }
        }
        return mat1;
}
Matrix Matrix:: operator+= (Matrix mat1){
        for(int i=0; i<row; ++i)
        {
        for(int j=0; j<col; ++j)
            {
                this->data[i][j]= this->data[i][j] + mat1.data[i][j]; /// this data in constructor =  data in constructor - mat1 data
            }
        }
        return *this; /// will return the same matrix not a new matrix (Matrix the user will input it .) .
 }

/// this point at default mat in constructor and mat1 point at new matrix .

Matrix Matrix:: operator-= (Matrix mat1){
        for(int i=0; i<row; ++i)
        {
        for(int j=0; j<col; ++j)
            {
                this-> data[i][j] = this->data[i][j] -  mat1.data[i][j];  /// this data in constructor =  data in constructor - mat1 data
            }
        }
        return *this; /// will return the same matrix not a new matrix (Matrix the user will input it .).
}

Matrix Matrix:: operator+= (int scalar){
        for(int i=0; i<row; ++i)
        {
        for(int j=0; j<col; ++j)
            {
                this->data[i][j] = this->data[i][j]+scalar;/// this data in constructor =  data in constructor + scalar the user will input it
            }
        }
        return *this;
}

Matrix Matrix:: operator-= (int scalar){
        for(int i=0; i<row; ++i)
        {
        for(int j=0; j<col; ++j)
            {
                this->data[i][j] = this->data[i][j] + scalar;  /// this data in constructor =  data in constructor - scalar the user will input it
            }
        }
        return *this;
}

void  Matrix:: operator++ (){

        for(int i=0; i<this->row; ++i)
        {
        for(int j=0; j<this->col; ++j)
            {
                ++data[i][j];  /// this data in constructor =  data in constructor + 1
            }
        }
}

void  Matrix:: operator-- (){

        for(int i=0; i<this->row; ++i)
        {
        for(int j=0; j<this->col; ++j)
            {
                --data[i][j];  /// this data in constructor =  data in constructor - 1
            }
        }
}

bool Matrix:: operator== (Matrix mat1)
{
    if(mat1.row == this->row && mat1.col == this->col)
    {
        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                if(mat1.data[i][j] != this->data[i][j])
                {
                    return 0; /// return false if data of mat1 != data in constructor
                }
            }
        }
        return 1;  /// return true if data of mat1 == data in constructor

    }
    else;
    return 0;
}
bool Matrix:: operator!= (Matrix mat1)
{
    if(mat1.row == this->row && mat1.col == this->col)  /// if row in constrictor == data of mat1 && col in constrictor == col of mat1
    {
        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                if(mat1.data[i][j] == this->data[i][j]) /// if data in constrictor == data of mat1 return false
                {
                    return 0;
                }
            }
        }
        return 1;

    }
    else;
    return 0;
}


bool Matrix:: isSquare ()
{
    if (this->row == this->col) /// if row in constrictor == row in constrictor return true
    {
        return 1;
    }
    else;
    return 0;
}

bool Matrix:: isSymetric ()
{
        for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            if(this->data[i][j] != this->data[j][i])  /// if data in constrictor != the same data  and will return false
            {
                return 0;
            }
        }
    }
    return 1;
}
bool Matrix:: isIdentity ()
{

    for(int i=0; i<this->row; i++)
    {
        for(int j=0; j<this->col; j++)
        {
            if(this->data[i][j] != 1)    /// if data in constrictor != 1 will return false
            {
                return 0;
            }
        }
    }
    return 1;
}

Matrix Matrix::transpose()
{

    if(row == col){
        int data3[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
        Matrix mat3(row , col , data3);
        mat3.row=this->row;
        mat3.col=this->col;
        for(int i=0; i<this->row; i++)
        {
            for(int j=0; j<this->col; j++)
            {
                mat3.data[i][j] = this->data[j][i];
            }

        }
        return mat3;
    }
    else;
    cout << "not square matrix"<<endl;
}
