// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    matrix mat1, mat2, mat3;
    int row1, row2, col1, col2 ;
    cout << "Enter your rows mat1 number : ";
    cin >> row1 ;
    cout << "Enter your cols  mat1 number : ";
    cin >> col1 ;
    int data1[row1*col1];
    createMatrix (row1, col1, data1, mat1);
    cin >> mat1;

    cout << "Enter your rows mat2 number : ";
    cin >> row2 ;
    cout << "Enter your cols  mat2 number : ";
    cin >> col2 ;
    int data2[row2*col2];
    createMatrix (row2, col2, data2, mat2);
    cin >> mat2;

    cout << "Mat1 is :"<<endl << mat1 << endl;
    cout << "Mat2 is :"<<endl << mat2 << endl;

    while(true)
    {
        string x;
        cout << "1- Mat1 + Mat2 . \n2- Mat1 - Mat2 .\n3- Mat1 * Mat2 . \n4- Mat1 + scalar .\n5- Mat1 - scalar .\n6- Mat1 * scalar .\n7- Mat1 +=  Mat2.\n8- Mat1 -= Mat2.\n9- Mat + scalar .\n";
        cout << "10- Mat - scalar .\n11- ++Mat . \n12- --Mat .\n13- If Mat1 == Mat2 or Not .\n14- If Mat1 != Mat2 or Not .\n15- Square of Mat .\n16- Mat isSymetric or Not .\n17- Mat isIdentity or Not .";
        cout << "\n18- Transpose of Mat .\n\n Enter your choose please : ";
        cin >> x ;

//////////////////////////////////////////////// AbdELhamed
        if (  x ==  "1" )
        {

        }
        else if ( x == "2")
        {

        }
        else if ( x == "3")
        {

        }
        else if ( x == "4")
        {

        }
        else if ( x == "5")
        {
                    }
        else if ( x == "6")
        {

        }


///////////////////////////////////////////////////////// Mohamed Hamdy

        else if ( x == "7")
        {
            mat1 = mat1 + mat2;
            cout <<" mat1 += mat2 : "  <<endl << mat1;
        }
        else if ( x == "8")
        {
            mat1 = mat1 - mat2;
            cout <<" mat1 -= mat2 : "  << endl << mat1;
        }
        else if ( x == "9")
        {
            int scalar ;
            cout << " Enter your scalar number : ";
            cin >> scalar;
            char matnumber ;
            cout << "1 - if you want to add with mat 1.\n 1 - if you want to add with mat 2.\n Enter your choose please : ";
            cin >> matnumber;
            if (matnumber == '1')
            {
                mat1 += scalar;
                cout <<" mat += Scalar : "  << mat1 ;
            }
            else if (matnumber == '2')
            {
                mat2 += scalar;
                cout <<" mat += Scalar : "  << mat2 ;
            }
        }
        else if ( x == "10")
        {
            int scalar ;
            cout << " Enter your scalar number : ";
            cin >> scalar;
            char matnumber ;
            cout << "1 - if you want to add with mat 1.\n2 - if you want to add with mat 2.\n Enter your choose please : ";
            cin >> matnumber;
            if (matnumber == '1')
            {
                mat1 -= scalar;
                cout <<" mat -= Scalar : "  << mat1 ;
            }
            else if (matnumber == '2')
            {
                mat2 -= scalar;
                cout <<" mat -= Scalar : "  << mat2 ;
            }
        }

        else if ( x == "11")
        {
            char matnumber ;
            cout << "1- if you want to add with mat 1.\n2- if you want to add with mat 2.\n Enter your choose please : ";
            cin >> matnumber;
            if (matnumber == '1')
            {
                ++mat1;
                cout <<" mat += 1 : "  << mat1 ;
            }
            else if (matnumber == '2')
            {
                ++mat2;
                cout <<" ++mat : "  << mat2 ;
            }
        }
        else if ( x == "12")
        {
            char matnumber ;
            cout << "1- if you want to add with mat 1.\n2- if you want to add with mat 2.\n Enter your choose please : ";
            cin >> matnumber;
            if (matnumber == '1')
            {
                --mat1;
                cout <<" --mat : "  << mat1 ;
            }
            else if (matnumber == '2')
            {
                --mat2;
                cout <<" --mat : "  << mat2 ;
            }
        }


////////////////////////////////////////////////////Mohamed ALi
        else if ( x == "13")
        {
            cout << "Mat1 == Mat2  :" << (mat1 == mat2) << endl ;
        }
        else if ( x == "14")
        {
            cout << "Mat1 != Mat2  : " << (mat1 != mat2) << endl ;
        }
        else
        {
            continue;
        }
    }
    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}




 /////////////////////////////////////////////////////////// Abd El Hamed Part
matrix operator+  (matrix mat1, matrix mat2)
{
 cout << " Add Your code AbdelHamed";
}
matrix operator-  (matrix mat1, matrix mat2)
{
    cout << " Add Your code AbdelHamed";
}

matrix operator*  (matrix mat1, matrix mat2)
{
    cout << " Add Your code AbdelHamed";
}
matrix operator+ (matrix& mat1, int scalar)
{
    cout << " Add Your code AbdelHamed";
}

matrix operator- (matrix mat1, int scalar)
{
    cout << " Add Your code AbdelHamed";
}

matrix operator* (matrix mat1, int scalar)
{
    cout << " Add Your code AbdelHamed";

}

/////////////////////////////////////////////////////////////////// Mohamed Hamdy Part


////////////////////////// cin oprator
istream& operator>> (istream& in, matrix& mat)
{
    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            in>>mat.data[i][j];
        }
    }
    return in;

}

matrix operator+= (matrix& mat1, matrix mat2)
{
    for(int i=0; i<mat1.row; ++i)
    {
        for(int j=0; j<mat1.col; ++j)
        {
            mat1.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
        }
    }
    return mat1;
}

matrix operator-= (matrix& mat1, matrix mat2)
{

    for(int i=0; i<mat1.row; ++i)
    {
        for(int j=0; j<mat1.col; ++j)
        {
            mat1.data[i][j]=mat1.data[i][j]- mat2.data[i][j];
        }
    }
    return mat1;
}


matrix operator+= (matrix& mat, int scalar)
{

    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            mat.data[i][j]=mat.data[i][j]+scalar;
        }
    }
    return mat;
}
matrix operator-= (matrix& mat, int scalar)
{

    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            mat.data[i][j]=mat.data[i][j]-scalar;
        }
    }
    return mat;
}
void   operator++ (matrix& mat)
{

    int scalar = 1 ;
    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            mat.data[i][j]=mat.data[i][j]+ scalar;
        }
    }
}

void   operator-- (matrix& mat)
{

    int scalar = 1 ;
    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            mat.data[i][j]=mat.data[i][j]- scalar;
        }
    }
}



//////////////////////////////////////////////////////////// Mohamed Ali Part

////////////////////// cout opratot
ostream& operator<< (ostream& out, matrix mat)
{
    for(int i=0; i<mat.row; ++i)
    {
        for(int j=0; j<mat.col; ++j)
        {
            out<<mat.data[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}

bool   operator== (matrix mat1, matrix mat2)
{
    cout << " Add Mohamed Ali code AbdelHamed";
}
bool   operator!= (matrix mat1, matrix mat2)
{
    cout << " Add Mohamed Ali code AbdelHamed";
}
bool   isSquare   (matrix mat)
{
    cout << " Add Mohamed Ali code AbdelHamed";
}

bool   isSymetric (matrix mat)
{
    cout << " Add Mohamed Ali code AbdelHamed";
}
bool   isIdentity (matrix mat)
{
    cout << " Add Mohamed Ali code AbdelHamed";
}
matrix transpose(matrix mat)
{
    cout << " Add Mohamed Ali code AbdelHamed";
}
