#include <iostream>
#include <array>
using namespace std;

int main()
{
    const int arraySize{6};
    array <char,arraySize> alphabet{'A','B','C','D','E','F'};
    // cout << alphabet[5];

    array <double, arraySize> grades{0,0,0,0,0,0};

    for(double display : grades)
    {
        cout << display << " ";
    }
    cout << endl;

    cout << "Input a value for element 4 of the array: ";
    cin >> grades[3];
    cout << endl;

    for(double display : grades)
    {
        cout << display << " ";
    }


}