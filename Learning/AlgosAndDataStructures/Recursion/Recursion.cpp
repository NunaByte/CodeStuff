#include <iostream>
using namespace std;

void fun1(int n)
{
    if(n > 0)
    {
        
        cout << n << endl;
        fun1(n-1);
        fun1(n-1);
    }
}




int main()
{
    fun1(3);
}