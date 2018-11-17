#include<iostream>
using namespace std;

/* Function to swap two characters */
void swap_fun(char& a, char& b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

/* Function to obtain permutations of string characters */
void permutation(string str , int starting_index , int Ending_index)
{
    if (starting_index == Ending_index)
        cout << str << "\n";
    else
    {
        for (int j = starting_index; j < str.length(); j++)
        {
            swap_fun(str[starting_index],str[j]);
            permutation(str, starting_index + 1, Ending_index);
            swap_fun(str[starting_index],str[j]);
             /*
             step 2 :
             round one : program start ----> Swapping Equation 1 with starting_index = 0 and j = 0 and ------> it make swap between a and a
             round two : ------------------> calling function starting_index = 1 and j = 1 and ------> it make swap between b and b
             print "abc" and then calling the same function .
             round three : ----------------> Swapping Equation 2  function starting_index = 2 and j = 1 and ------> it make swap between b and c
             print acb


             step 2 :  calling the function but Now j = starting index + 1 (+1 from for loop becouse this is time two after j = 0 ) so starting index = 0 and j = 1

             round one : Do Swapping Equation 1 with starting_index = 0 and j = 1 and ------> it make swap between a and b
             round two : ------------------> calling function starting_index = 1 and j = 1 and ------> it make swap between a and a
             print "bac" and then calling the same function .
             round three : ----------------> Swapping Equation 2  function starting_index = 2 and j = 1 and ------> it make swap between a and c
             print "bca"



             step 2 :  calling the function but Now j = starting index + 1 (+1 from for loop becouse this is time two after j = 1 ) so starting index = 0 and j = 2
             round one : Do Swapping Equation 1 with starting_index = 0 and j = 2 and ------> it make swap between a and c
             round two : ------------------> calling function starting_index = 1 and j = 2 and ------> it make swap between b and c
             print "cba" and then calling the same function .
             round three : ----------------> Swapping Equation 2  function starting_index = 2 and j = 2 and ------> it make swap between b and b
             print "cab"


            */
            /// summary :
            /// in for loop the starting index will increase by 1 and j will be fixed
            /// after Two print Process j will increase by 1 and starting index will be fixed = 0
            /// and enter the for loop and starting index will increase and j will be fixed
            /// and so what ... etc .


            /// Note i send Ending index = str.length() - 1 to print the two output in one for loop that using Swap function two time and j start from 0 .
        }
    }
}

int main()
{
    string str;
    cout << "Enter the string : ";
    cin >> str;
    cout << endl << "The permutations of the given string : " << endl;
    permutation(str, 0, str.length() - 1);   /// Ending index = str.length() - 1 Because the counter in for loop j start from 0 .
    cout << endl;
}
