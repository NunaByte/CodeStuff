#include <iostream>
using namespace std;

    void swap(int &x, int &y);

int main()
{
    int x = 10;
    int y = 20;

    cout << "The value of x: " << x << endl;
    cout << "The value of y: " << y << endl;
    swap(x,y);
    cout << "\nAfter Swap" << endl;
    cout << "The value of x: " << x << endl;
    cout << "The value of y: " << y << endl;
}

    void swap(int &x, int &y)
    {
        int *pointX = &x;
        int *pointY = &y;

        int xTemp = *pointX;
        int yTemp = *pointY;

        *pointX = yTemp;
        *pointY = xTemp;
        
    }