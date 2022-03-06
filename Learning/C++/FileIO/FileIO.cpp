#include <iostream>
#include <fstream>

using namespace std;


const int MAX_TASK_SIZE = 512;

struct Task
{
    char isDone[1];
    char task[MAX_TASK_SIZE];
};

struct TaskDB
{
    Task *optrTasks;
    int numberOfTasks;
    int capacity;
};

int main()
{
    char option;

    do
    {
        
        option = GetOptionFromUser();

        ExecuteOption(option);

    } while(option != 'q');
    

    return 0;
}