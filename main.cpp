// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1 - Problem 0
// Program: CS213-2018-A2-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include "Matrix.h"
using namespace std;

ostream& operator<<(ostream& out, const Matrix& mat);
istream& operator>>(istream& in,  Matrix& mat);

int main()
{
    int row1, row2, col1, col2 ;
    cout <<"Enter number of row one :";
    cin >> row1;
    cout <<"Enter number of col one :";
    cin >> col1;
    int data1[row1*col1];
    Matrix mat1(row1,col1, data1);
    cin >> mat1;

    cout <<"Enter number of row two :";
    cin >> row2;
    cout <<"Enter number of col two :";
    cin >> col2;
    int data2[row2*col2];
    Matrix mat2(row2, col2, data2);
    cin >> mat2;

    while(true)
    {
        string x;
        cout << "1- Mat1 + Mat2 . \n2- Mat1 - Mat2 .\n3- Mat1 * Mat2 . \n4- Mat1 + scalar .\n5- Mat1 - scalar .\n6- Mat1 * scalar .\n7- Mat1 +=  Mat2.\n8- Mat1 -= Mat2.\n9- Mat + scalar .\n";
        cout << "10- Mat - scalar .\n11- ++Mat . \n12- --Mat .\n13- If Mat1 == Mat2 or Not .\n14- If Mat1 != Mat2 or Not .\n15- Square of Mat .\n16- Mat isSymetric or Not .\n17- Mat isIdentity or Not .";
        cout << "\n18- Transpose of Mat .\n19- To End .\n\n Enter your choose please : ";
        cin >> x ;
        if (  x ==  "1" )
        {
            while ( (row1 != row2 && col1 != col2) || (row1 == row2 && col1 != col2) || (row1 != row2 && col1 == col2) )
            {

                cout<<"they haven't same dimensions ." << endl << endl;
                break;
            }
            while ( row1 == row2 && col1 == col2)
            {

                Matrix mat3 = mat1 + mat2;
                cout <<"mat1 + mat2 : "  << endl << endl << mat3;
                break;
            }

        }
        else if ( x == "2")
        {
            while ( (row1 != row2 && col1 != col2) || (row1 == row2 && col1 != col2) || (row1 != row2 && col1 == col2) )
            {

                cout<<"they haven't same dimensions ." << endl << endl;
                break;
            }
            while ( row1 == row2 && col1 == col2)
            {

                Matrix mat3 =mat1 - mat2;
                cout <<"mat1 - mat2 : "  << endl << mat3 ;
                break;
            }
        }
        else if ( x == "3")
        {
            while ( col1 != row2)
            {

                cout<<"they haven't same dimensions ." << endl << endl;
                break;
            }
            while ( col1 == row2)
            {

                Matrix mat3 = mat1 * mat2;
                cout <<" mat1 * mat2 : "  << endl << mat3 ;
                break;
            }
        }
        else if ( x == "4")
        {
            int scalar ;
            cout << " Enter your scalar number : ";
            cin >> scalar;
            char matnumber ;
            cout << "1 - if you want to add with mat 1.\n2 - if you want to add with mat 2.\n Enter your choose please : ";
            cin >> matnumber;
            if (matnumber == '1')
            {
                cout <<" mat += Scalar : \n"  << mat1 + scalar ;
            }
            else if (matnumber == '2')
            {
                cout <<" mat += Scalar :\n "  << mat2  + scalar;
            }
        }
        else if ( x == "5")
        {
            int scalar;
            cout << " Enter your scalar number : ";
            cin >> scalar;
            char matnumber ;
            cout << "1 - if you want to - with mat 1.\n2 - if you want to - with mat 2.\n Enter your choose please : ";
            cin >> matnumber;
            if (matnumber == '1')
            {
                cout <<" mat -= Scalar : \n"  << mat1 - scalar ;
            }
            else if (matnumber == '2')
            {
                cout <<" mat -= Scalar :\n "  << mat2  - scalar;
            }
        }

        else if ( x == "6")
        {
            int scalar;
            cout << " Enter your scalar number : ";
            cin >> scalar;
            char matnumber ;
            cout << "1 - if you want to * with mat 1.\n2 - if you want to * with mat 2.\n Enter your choose please : ";
            cin >> matnumber;
            if (matnumber == '1')
            {
                cout <<" mat -= Scalar : \n"  << mat1 * scalar ;
            }
            else if (matnumber == '2')
            {
                cout <<" mat -= Scalar :\n "  << mat2 * scalar ;
            }
        }
        /////////////////////////////////////////////////////////

        else if ( x == "7")
        {
            while (  (row1 != row2 && col1 != col2) || (row1 == row2 && col1 != col2) || (row1 != row2 && col1 == col2) )
            {

                cout<<"they haven't same dimensions ." << endl << endl;
                break;
            }
            while ( row1 == row2 && col1 == col2)
            {

                cout <<" mat1 += mat2 : \n"  <<endl << mat1 + mat2;
                break;
            }
        }


        else if ( x == "8")
        {
            while (  (row1 != row2 && col1 != col2) || (row1 == row2 && col1 != col2) || (row1 != row2 && col1 == col2) )
            {

                cout<<"they haven't same dimensions ." << endl << endl;
                break;
            }
            while ( row1 == row2 && col1 == col2)
            {

                cout <<" mat1 -= mat2 : \n"  << endl << mat1 - mat2;
                break;
            }
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
                cout <<" mat += Scalar : \n"  << mat1 + scalar;
            }
            else if (matnumber == '2')
            {
                cout <<" mat += Scalar : \n"  << mat2 + scalar ;
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
                cout <<" mat -= Scalar : \n"  << mat1 - scalar ;
            }
            else if (matnumber == '2')
            {
                cout <<" mat -= Scalar :\n "  << mat2 - scalar;
            }
        }

        else if ( x == "11")
        {
            char matnumber ;
            cout << "1- if you want to add with mat 1.\n2- if you want to add with mat 2.\n Enter your choose please : ";
            cin >> matnumber;
            if (matnumber == '1')
            {
                ++mat1 ;
                cout <<" ++mat : \n"  << mat1 ;
            }
            else if (matnumber == '2')
            {
                ++mat2;
                cout <<" ++mat : \n"  << mat2 ;
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
                cout <<" --mat : \n"  << mat1 ;
            }
            else if (matnumber == '2')
            {
                --mat2;
                cout <<" --mat : \n"  << mat2 ;
            }
        }
        else if ( x == "13")
        {
            cout << "Mat1 == Mat2  :" << (mat1 == mat2)<< endl ;
        }
        else if ( x == "14")
        {
            cout << "Mat1 != Mat2  : " <<(mat1 != mat2) << endl ;
        }
        else if ( x == "15")
        {
            char choice ;
            cout << "1- Test with mat1 . \n 2- Test With mat2 . \n Enter your choose :" ;
            cin >> choice ;
            if ( choice == '1')
            {
                cout << "The Result is :"<< mat1.isSquare()  << endl<< endl;

            }
            else if ( choice == '2')
            {
                cout << "The Result is :"<< mat2.isSquare()  << endl<< endl;

            }

        }
        else if ( x == "16")
        {
            char choice ;
            cout << "1- Test with mat1 . \n2- Test With mat2 . \n Enter your choose :" ;
            cin >> choice ;
            if ( choice == '1')
            {
                cout << "The Result is :"<< mat1.isSymetric()  << endl<< endl;

            }
            else if ( choice == '2')
            {
                cout << "The Result is :"<< mat2.isSymetric()  << endl<< endl;

            }
        }
        else if ( x == "17")
        {
            char choice ;
            cout << "1- Test with mat1 . \n2- Test With mat2 . \n Enter your choose :" ;
            cin >> choice ;
            if ( choice == '1')
            {
                cout << "The Result is :"<< mat1.isIdentity()  << endl<< endl;

            }
            else if ( choice == '2')
            {
                cout << "The Result is :"<< mat2.isIdentity() << endl<< endl;

            }
        }
        else if ( x == "18")
        {
            char choice ;
            cout << "1- Test with mat1 . \n2- Test With mat2 . \n Enter your choose :" ;
            cin >> choice ;
            if ( choice == '1')
            {
                cout << "The Result is :\n"<< mat1.transpose()  << endl<< endl;

            }
            else if ( choice == '2')
            {
                cout << "The Result is :"<< mat2.transpose()  << endl<< endl;

            }
        }
        else if ( x == "19")
        {
            cout <<endl << "GOOD BYE ." << endl ;
            break;
        }
        else
        {
            continue;
        }
    }

    return 0;
}


ostream& operator<<(ostream& out, const Matrix& mat)
{
    for (int i = 0 ; i < mat.row; i++)
    {
        for ( int j = 0 ; j < mat.col; j++)
        {
            out << mat.data[i][j]<<" ";
            out << " ";
        }
        out << endl;
    }
    return out ;
}


istream& operator>>(istream& in,  Matrix& mat)
{
    for (int i = 0 ; i < mat.row; i++)
    {
        for ( int j = 0 ; j < mat.col; j++)
        {
            in >> mat.data[i][j];
        }
    }
    return in ;
}
