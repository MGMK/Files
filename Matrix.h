#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    public:
        Matrix(int row , int col , int num[]);

        Matrix operator+ (Matrix mat1);   /// return new matrix
        Matrix operator- (Matrix mat1);   /// return new matrix
        Matrix operator* (Matrix mat1);   /// return new matrix

        Matrix operator+ (int scalar);    /// user will input the scalar
        Matrix operator- (int scalar);    /// user will input the scalar
        Matrix operator* (int scalar);    /// user will input the scalar

        Matrix operator+= (Matrix mat1);  /// return the same matrix
        Matrix operator-= (Matrix mat1);  /// return the same matrix
        Matrix operator+= (int scalar);   /// user will input the scalar
        Matrix operator-= (int scalar);   /// user will input the scalar

        void  operator++ ();  /// matrix = matrix + 1
        void  operator-- ();  /// matrix = matrix - 1

        bool   operator== ( Matrix mat1);	/// True if identical
        bool   operator!= ( Matrix mat1); 	/// True if not same
        bool   isSquare   ();  /// True if square matrix
        bool   isSymetric ();  /// True if square and symmetric
        bool   isIdentity ();  /// True if square and identity
        Matrix transpose();

        int row , col ;
        int** data;
};

#endif MATRIX_H


