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

string name;
string task;

vector <string> names;
vector <string> tasks;

// generate a random number between 1 and 10
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
        //cout << names[i] << endl;
    }
    return names;
    
}

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
        //cout << tasks[i] << endl;
    }
    return tasks;
}

// class to define the people we are going to need to 'create'
class numPersonTask
{
public:
    string nptName;
    string nptTask;
    int nptNumber;
    string fullString;

    // this line of code is saying that the numpersontask class can be passed into ostreams out function
    friend ostream& operator <<(ostream& os, const numPersonTask& npt);

    void createString();
    // formats the fullstring within the function, allows us to easily call it if needed for debug
    string outputString()
    {
        fullString = to_string(nptNumber) + " : " + nptName + " - " + nptTask + "\n";
        cout << fullString;
        return fullString;
    }

    
};

void numPersonTask::createString()
{
    srand(time(NULL));
    nptName = names[rand() % 100 + 1];
    nptTask = tasks[rand() % 10 + 0];
    nptNumber = rand() % 10 + 1;
}

// tells the ostream to allow fullstring to be passed
ostream& operator <<(ostream& os, const numPersonTask& npt)
{
    os << npt.fullString;
    return os;
}



int main()
{
    int amount;
    cout << "--Generator file--" << endl;
    cout << "how many people need to be generated?" << endl;
    cin >> amount;
    taskLoaderFunc();
    nameLoaderFunc();
    
    for(int i = 0; i < amount; i++)
    {
        numPersonTask temp;
        temp.createString();
        temp.outputString();

    }
}
