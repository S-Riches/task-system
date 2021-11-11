#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>

using namespace std;

/*
    this program will simply generate tasks dependent on its input of tasks

    tasks consist of 3 things
    - name - name.txt
    - number of importance - generate at run time
    - task - tasks.txt

    this program needs to generate procedural tasks based of of pre-determined inputs and save them to a text file.
    the tasks will be delegated to 100 different people, where there is 10 different tasks, for example, whitney - shopping - 1 or similiar

*/

vector <string> output;
int vectorSize;


string generateImportance()
{
    // declare var 
    int importance;
    //seed the random
    srand((unsigned int)time(NULL));
    //give it a random number between one and ten
    importance = rand() % 10 + 1;
    //return it
    return to_string(importance);
}

void generateContent(int vectorSize)

{
    string newString;
    string nameString;
    string taskString;

    fstream nameLoader("inputs/name.txt");
    fstream taskLoader("inputs/tasks.txt");

    if(taskLoader.is_open())
    {
        if(nameLoader.is_open())
        {
            while(getline(nameLoader, nameString))
            {
                while(getline(taskLoader, taskString))
                {   
                    newString = taskString +" : "+ nameString + " : " + generateImportance();
                    cout << newString << endl;   
                }
            }
        }
    }
}


int main()
{
    cout << "generator file" << endl;
    generateContent(1);
}
