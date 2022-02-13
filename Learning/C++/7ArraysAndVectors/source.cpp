#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    const size_t arraySize{12};

    array<int, arraySize> c; //c is an array of 12 int values
    array<int, 5> b{5,2,4,7,4};

    for(size_t i{0}; i < b.size(); ++i)
    {
        cout << b[i] << endl;
    } 
}