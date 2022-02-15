//Program calculates the factorials of 1 through 20
#include <iostream>
using namespace std;

int main()
{
    for(int i = 1; i <= 20; ++i)
    {
        long long factorial{1};
        for(int j = 1; j <= i; ++j)
        {
            factorial *= j;
        }
        
        cout << "The factorial of " << i << " is: " << factorial << endl;
    }
}