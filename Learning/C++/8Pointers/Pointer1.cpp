//Array, Pointer, Dynamic Memory Practice
#include <iostream>
using namespace std;


int main()
{
    int size;
    cout << "Size: ";
    cin >> size;

    int * myArray= new int [size];

    for(int i = 0; i < size; i++)
    {
        myArray[i] = i;
    }

    for(int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }


    delete[]myArray;
    myArray = NULL;


    system("pause>0");
    return 0;
}


