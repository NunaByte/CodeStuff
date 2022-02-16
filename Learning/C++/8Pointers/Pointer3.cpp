//Array, Pointer, Dynamic Memory Practice
#include <iostream>
using namespace std;

int return5()
{
    return 5;
}


int main()
{
    int(*funcPtr)() = return5;
    cout << funcPtr();

    system("pause>0");
    return 0;
}
