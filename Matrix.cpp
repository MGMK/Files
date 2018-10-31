#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int row , int col)
{
    this->row = row;
    this->col = col;
    this->data = new int* [row];
    for(int i = 0 ; i < row ; i++){
        data[i]=new int [col];
    }
}


Matrix Matrix:: operator+(Matrix& mat1){

    Matrix mat3(mat1.row,mat1.col);
    if(mat1.row == this->row && this->col==mat1.col){
        for (int i = 0 ; i < mat1.row; i++){
            for ( int j = 0 ; j < mat1.col; j++){
                mat3.data[i][j] = this->data[i][j] + mat1.data[i][j];

            }

        }
         return mat3 ;
    }
 else
        cout<<"they haven't same dimensions .";

}

Matrix Matrix:: operator-(Matrix& mat1){
    Matrix mat3(mat1.row,mat1.col);
    if(mat1.row==this->row && this->col==mat1.col){
     for (int i = 0 ; i < mat1.row; i++){
        for ( int j = 0 ; j < mat1.col; j++){
            mat3.data[i][j] = this->data[i][j] - mat1.data[i][j];
        }
    }
     return mat3 ;

    }
     else
        cout<<"they haven't same dimensions .";

}

Matrix Matrix:: operator*(Matrix mat1){

    Matrix mat3(mat1.col,this->row);

    if(mat1.row==this->row && this->col==mat1.col){
        mat3.row=this->row=mat1.row;
        mat3.col=mat1.col=this->col;
        for(int i=0; i < mat3.row; ++i)
        {
            for(int j=0; j < mat3.col; ++j)
            {
                mat3.data[i][j]=this->data[i][j] * mat1.data[j][i];
            }
        }
        return mat3;
    }
    else
        cout<<"they haven't same dimensions .";

}

Matrix Matrix:: operator+ (int scalar){
        Matrix mat1(this->row,this->col);
        for(int i=0; i<mat1.row; ++i)
        {
        for(int j=0; j<mat1.col; ++j)
            {
                mat1.data[i][j] = this->data[i][j]+scalar;
            }
        }
        return mat1;
}

Matrix Matrix:: operator- (int scalar){
        Matrix mat1(this->row,this->col);
        for(int i=0; i<mat1.row; ++i)
        {
        for(int j=0; j<mat1.col; ++j)
            {
                mat1.data[i][j] = this->data[i][j]-scalar;
            }
        }
        return mat1;
}

Matrix Matrix:: operator* (int scalar){
        Matrix mat1(this->row,this->col);
        for(int i=0; i<mat1.row; ++i)
        {
        for(int j=0; j<mat1.col; ++j)
            {
                mat1.data[i][j] = this->data[i][j]*scalar;
            }
        }
        return mat1;
}
Matrix Matrix:: operator+= (Matrix& mat1){
        for(int i=0; i<mat1.row; ++i)
        {
        for(int j=0; j<mat1.col; ++j)
            {
                mat1.data[i][j]=mat1.data[i][j]+this->data[i][j];
            }
        }
        return mat1;
}
Matrix Matrix:: operator-= (Matrix& mat1){
        for(int i=0; i<mat1.row; ++i)
        {
        for(int j=0; j<mat1.col; ++j)
            {
                mat1.data[i][j]=mat1.data[i][j]-this->data[i][j];
            }
        }
        return mat1;
}

Matrix Matrix:: operator+= (int scalar){
        Matrix mat1(this->row,this->col);
        for(int i=0; i<mat1.row; ++i)
        {
        for(int j=0; j<mat1.col; ++j)
            {
                mat1.data[i][j] = mat1.data[i][j]+scalar;
            }
        }
        return mat1;
}

Matrix Matrix:: operator-= (int scalar){
        Matrix mat1(this->row,this->col);
        for(int i=0; i<mat1.row; ++i)
        {
        for(int j=0; j<mat1.col; ++j)
            {
                mat1.data[i][j] = mat1.data[i][j]-scalar;
            }
        }
        return mat1;
}

void  Matrix:: operator++ (){

        for(int i=0; i<this->row; ++i)
        {
        for(int j=0; j<this->col; ++j)
            {
                ++data[i][j];
            }
        }
}

void  Matrix:: operator-- (){

        for(int i=0; i<this->row; ++i)
        {
        for(int j=0; j<this->col; ++j)
            {
                --data[i][j];
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
                    return 0;
                }
            }
        }
        return 1;

    }
    else;
    return 0;
}
bool Matrix:: operator!= (Matrix mat1)
{
    if(mat1.row == this->row && mat1.col == this->col)
    {
        for(int i=0; i<mat1.row; i++)
        {
            for(int j=0; j<mat1.col; j++)
            {
                if(mat1.data[i][j] == this->data[i][j])
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
    if (this->row == this->col)
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
            if(this->data[i][j] != this->data[j][i])
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
            if(this->data[i][j] != 1)
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
        Matrix mat3(row , col);
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
