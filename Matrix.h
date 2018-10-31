#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    public:
        Matrix(int row , int col);

        Matrix operator+ (Matrix& mat1);
        Matrix operator- (Matrix& mat1);
        Matrix operator* (Matrix mat1);
        Matrix operator+ (int scalar);
        Matrix operator- (int scalar);
        Matrix operator* (int scalar);

        Matrix operator+= (Matrix& mat1);
        Matrix operator-= (Matrix& mat1);
        Matrix operator+= (int scalar);
        Matrix operator-= (int scalar);
        void  operator++ ();
        void  operator-- ();

        bool   operator== ( Matrix mat1);	// True if identical
        bool   operator!= ( Matrix mat1); 	// True if not same
        bool   isSquare   ();  // True if square matrix
        bool   isSymetric ();  // True if square and symmetric
        bool   isIdentity ();  // True if square and identity
        Matrix transpose();

        int row , col ;
        int** data;
};

#endif // MATRIX_H

