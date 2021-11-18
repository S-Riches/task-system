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

// appologies in advance for this sacrilege
vector<string> group1;
vector<string> group2;
vector<string> group3;
vector<string> group4;
vector<string> group5;
vector<string> group6;
vector<string> group7;
vector<string> group8;
vector<string> group9;
vector<string> group10;
vector<vector<string>> holder = {group1,group2,group3,group4,group5,group6,group7,group8,group9,group10};
bool check = false;
//get input from txt file, put into string vector or array, return the value to then be 
void getInput(string fileLoc)
{
    // temp variables for comparison
    string tempStr;
    string tempNum;

    fstream fileStream(fileLoc, ios::in);
    // instantiate an ifstream object to use to read the file
    // temp comments until i work out how to write this 
        if(fileStream.is_open())
        {
            check == true;
            // text to confirm the file was opened succesfully
            cout << "file opened\n Assigning groups\n";
            while (getline(fileStream, tempStr))
            {
                // get the first two characters from tempstr and then store them in a temp string for processing.
                tempNum = tempStr.substr(0,2);
                // ugly switch statement, as they normally are :(
                switch (stoi(tempNum))
                {
                    // temporary solution for a problem, how do we scale up this without using a case switch like this?? its a bit spaghetti like
                case 1:
                    holder.at(0).push_back(tempStr);
                    cout << "group 1\n";
                    break;
                case 2:
                    holder.at(1).push_back(tempStr);
                    cout << "group 2\n";
                    break;
                case 3:
                    holder.at(2).push_back(tempStr);
                    cout << "group 3\n";
                    break;
                case 4:
                    holder.at(3).push_back(tempStr);
                    cout << "group 4\n";
                    break;
                case 5:
                    holder.at(4).push_back(tempStr);
                    cout << "group 5\n";
                    break;
                case 6:
                    holder.at(5).push_back(tempStr);
                    cout << "group 6\n";
                    break;
                case 7:
                    holder.at(6).push_back(tempStr);
                    cout << "group 7\n";
                    break;
                case 8:
                    holder.at(7).push_back(tempStr);
                    cout << "group 8\n";
                    break;
                case 9:
                    holder.at(8).push_back(tempStr);
                    cout << "group 9\n";
                    break;
                case 10:
                    holder.at(9).push_back(tempStr);
                    cout << "group 10\n";
                    break;
                default:
                    cout << "error occured!" << endl;
                    break;
                }
                cout << tempStr << endl;
            }
        }
    fileStream.close();
}

void outputGroups()
{
    if(check = true)
    {
        for(int i = 0; i < holder.size(); i++)
        {
            cout << "\n--Group " + to_string(i+1) + "--\n";
            for(int x = 0; x < holder[i].size(); x++){
                cout << holder[i][x] << "\n";
            }
            cout << "\n";
        }
    }
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
    getInput(fileLoc);
    cout << "---------------------" << endl;
    outputGroups();
    

    return 0;
}