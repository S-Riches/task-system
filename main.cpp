/*
this is a program that will be able to take input from a txt file
read the file, which will be unordered
and order the tasks and output its correct order

need to make a c++ file that will generate an unorded list for demo purpose.
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

// i know this is bad practice but i really dont care for this program
using namespace std;

string dataValidation(string input)
{
    if(input.empty() != true)
    {
        // perhaps check that the input is infact a string and not an int would avoid errors.
        try
        {  
            cout << input << endl;
            return input;
        }
        catch(...)
        {
            // ?!??
        }
    }

}

//get input from txt file, put into string vector or array, return the value to then be 
void getInput(string fileLoc)
{
    // instantiate an ifstream object to use to read the file
    ifstream fileStream;
    // temp comments until i work out how to write this 

    // checks if string is empty or not, if string is not empty then try to open.
    if(fileLoc.empty())
    {  
        // open file
        fileStream.open(fileLoc);
        cout << "file opened!" << endl;
    }
    // call out inv
    // outInv();
    // close file

    // check f stream docs.

}

string outInv()
{
    string temp_string;
    // need to loop through each line
    for (int i = 0; i < 10; i++)
    {
        // temp place holder text
        /* 
        the temp string will be used to format and output the text in the correct way
        we cant use the return keyword as it will break out of the for loop and return a value way
        too early
        */
    }
    return temp_string;
}

int main()
{
    // declare vars
    string fileLoc;
    // title, just cosmetic.
    cout << "--Inventory System--" << endl;
    // input to get file location
    cout << "Please input file to read : ";
    cin >> fileLoc;
    dataValidation(fileLoc);
    //getInput(fileLoc);


    return 0;
}