#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>

// i know this is bad practice but i really dont care for this program
using namespace std;

/*
this is a program that will be able to take input from a txt file
read the file, which will be unordered
and order the tasks and output its correct order
*/

/*
TODO: WILL NEED TO WRITE A GOOD DATA VALIDATION FUNCTION
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
*/
  
//vector to hold the other vectors
vector<vector<string>> holder;
//get input from txt file, put into string vector or array, return the value to then be 
void getInput(string fileLoc)
{
    // temp variables for comparison
    string tempStr;
    string tempNum;
    // temp vector to add to the holder
    vector <string> col;

    // instantiate an ifstream object to use to read the file
    fstream fileStream(fileLoc, ios::in);
    // temp comments until i work out how to write this 
        if(fileStream.is_open())
        {
            // text to confirm the file was opened succesfully
            cout << "file opened";
            while (getline(fileStream, tempStr))
            {
                // get the first two characters from tempstr and then store them in a temp string for processing.
                tempNum = tempStr.substr(0,2);
                // debug
                cout << tempNum << endl;
                // ugly switch statement, as they normally are :(
                switch (stoi(tempNum))
                {
                case 1:
                    /* code */
                    break;
                case 2:
                    /* code */
                    break;
                case 3:
                    /* code */
                    break;
                case 4:
                    /* code */
                    break;
                case 5:
                    /* code */
                    break;
                case 6:
                    /* code */
                    break;
                case 7:
                    /* code */
                    break;
                case 8:
                    /* code */
                    break;
                case 9:
                    /* code */
                    break;
                case 10:
                    /* code */
                    break;
                
                default:
                    break;
                }
            }
        }
    fileStream.close();
    // call out inv
    // close file

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
    //dataValidation(fileLoc);
    getInput(fileLoc);


    return 0;
}