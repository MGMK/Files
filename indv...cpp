

#include <iostream>
#include<algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <errno.h>


using namespace std;

// Team functions
void racer();
void load_data();
void display_data_sets();

int main()
{
    racer();

}


void load_data()
{
    cout << "\nTwo data sets are loaded .\n";
}


//////////////////////////////////// function 3 in Team functions





////// Mohamed Hamdy Function pones 1
void racer()
{
    ifstream file_1;
    file_1.open("filename.txt");
    int counter1=0;
    int array_1[100];
    string name;
    cout << "Enter your racer number :";
    cin >> name;
    if (file_1.is_open())
    {
        while (file_1 >> array_1[counter1])
        {
            ++counter1;
        }
    }

    int   racer_1[10], racer_2[10], racer_3[10] ;



    if ( name == "100")
    {

        int k = 0;
        for ( int i = 1 ;  i < 10 ; i++)
        {
            if ( array_1[k] == 100)
            {
                racer_1[i-1] = array_1[i];

            }
        }
        int counter = 3, number_of_points = 0 ,  temp[3] , temp_1[3] , temp_2[3] ;
        while ( number_of_points <= 2 )
        {

            cout << "\nthe racer reach at point number " << number_of_points  << " at : ";
            for ( int j = counter-3 ; j < counter ; j++)
            {
                cout << racer_1[j] << " ";
            }
            counter += 3 ;
            number_of_points++;

        }

        cout << endl;

    }


    if ( name == "132")
    {

        int x = 10, y = 0 ;
        for ( int i = 11 ;  i < 20 ; i++)
        {
            if ( array_1[x] == 132)
            {
                racer_2[y] = array_1[i];
                y++;
            }
        }
        int counter = 3, number_of_points = 0 ;

        while ( number_of_points <= 2 )
        {
            cout << "\nthe racer reach at point number " << number_of_points  << " at : ";
            for ( int j = counter-3 ; j < counter ; j++)
            {
                cout << racer_2[j] << " ";
            }
            counter += 3 ;
            number_of_points++;
        }
        cout << endl;
    }


    if ( name == "182")
    {

        int z = 20, w = 0 ;
        for ( int i = 21 ;  i < 30 ; i++)
        {
            if ( array_1[z] == 182)
            {
                racer_3[w] = array_1[i];
                ++w;
            }

        }
        int counter = 3, number_of_points = 0 ;

        while ( number_of_points <= 2 )
        {
            cout << "\nthe racer reach at point number " << number_of_points  << " at : ";
            for ( int j = counter-3 ; j < counter ; j++)
            {
                cout << racer_3[j] << " ";
            }
            counter += 3 ;
            number_of_points++;
        }
        cout << endl;
    }

}

