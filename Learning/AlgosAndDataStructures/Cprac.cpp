#include <iostream>

using namespace std;




int main()
{
    int test[5] = {4,3,5,6,7};
    int n =5, d=2;

    for(int i =d+1; i <n-1; i++)
    {
        if(i > d)
        {
            cout << test[i];
        }
    }


}
    