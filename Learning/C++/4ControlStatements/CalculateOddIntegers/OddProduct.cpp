#include <iostream>
#include <string>
using namespace std;

int main()
{
    int product{1};

    for(int i = 1; i <= 15; ++i)
    {
        if(i%2 == 1)
        {
            product *= i;
        }
    }

    cout << "The product of all odd numbers from 1-15 is: " << product;
}