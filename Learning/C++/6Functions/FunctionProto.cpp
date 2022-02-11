#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

//Function Prototype
void add(int& x);

int main()
{
    int x{3};
    
    cout << x << endl;
    add(x);
    cout << x << endl;
}

void add(int& x)
{
    x += x;
}