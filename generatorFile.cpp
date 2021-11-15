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
    - number group - generate at run time
    - task - tasks.txt

    this program needs to generate procedural tasks based of of pre-determined inputs and save them to a text file.
    the tasks will be delegated to 100 different people, where there is 10 different tasks, for example, whitney - shopping - 1 or similiar

    In this program (which was supposed to be a script for the file reader)
    i learnt : basic classes, basic file reading and writing, and how to generate a random number.
*/

fstream nameLoader;
fstream taskLoader;
fstream taskOut;

string name;
string task;

vector <string> names;
vector <string> tasks;

// generate a random number between the given parameter
int generateNumber(int limit)
{
    // declare var 
    int out;
    //seed the random function
    srand((unsigned int)time(NULL));
    //give it a random number between one and ten
    out = rand() % limit;
    //return it
    return out;
}

// load the names into a list
vector<string> nameLoaderFunc()
{
    cout << "\n" << "--Processing Names--" << "\n" << "\n";
    nameLoader.open("inputs/name.txt");
    
    if(nameLoader.is_open())
    {
        while (getline(nameLoader, name))
        {
            names.push_back(name);
        }
    }
    nameLoader.close();

    for(int i = 0; i < names.size(); i++){
        cout << names[i] << endl;
    }
    cout << "----------------------\n" << endl; 
    return names;
}

// load the tasks from the file
vector<string> taskLoaderFunc()
{
    // cool title
    cout << "\n" << "--Processing Tasks--" << "\n" << "\n";
    // opens file from directory
    taskLoader.open("inputs/tasks.txt");
    
    if(taskLoader.is_open())
    {
        // go through each line
        while (getline(taskLoader, task))
        {
            // add each line to the array
            tasks.push_back(task);
        }
    }
    // close file after use
    taskLoader.close();
    // simple loop to print out every element
    for(int i = 1; i < tasks.size(); i++){
        cout << tasks[i] << endl;
    }
    return tasks;
}

// class to define the people we are going to need to 'create'
class numPersonTask
{
public:
    // define vars
    string nptName;
    string nptTask;
    int nptNumber;
    string fullString;

    void createString();
    // formats the fullstring within the function, allows us to easily call it if needed for debug
    string outputString()
    {
        //formats the string
        fullString = to_string(nptNumber) + " : " + nptName + " - " + nptTask + "\n";
        // print out for debug
        cout << fullString;
        return fullString;
    }    
};

// allows us to change the values of a class member from outside the class.
void numPersonTask::createString()
{
    nptName = names[rand() % 99 + 1];
    nptTask = tasks[rand() % 10 + 0];
    nptNumber = rand() % 10 + 1;
}

int main()
{
    // seed the random
    srand(time(NULL));
    int amount;
    // add some flavour text
    cout << "--Generator file--" << endl;
    // get input for the for loop
    cout << "how many people need to be generated?" << endl;
    cin >> amount;
    // load names
    taskLoaderFunc();
    nameLoaderFunc();
    
    // gets the location for the output file
    taskOut.open("tasksOut.txt");
    for(int i = 0; i < amount; i++)
    {
        numPersonTask temp;
        temp.createString();
        // checks if file is open
        if(taskOut.is_open())
        {
            // adds it to the file
            taskOut << temp.outputString();
        }
        else cout << "unable to append file";
    }
    taskOut.close();

    // stops program from closing after use
    cout << "\n\n Press any key to close : ";
    int x;
    cin >> x;
}
