#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Function prototype
void roundNumber(double a, double b, double c);

int main()
{
    roundNumber(55, 60, 83);
}

void roundNumber(double a, double b, double c)
{
    cout << "Original Value: " << a << "  Rounded Value: " << ceil(a + 0.5) << endl;
    cout << "Original Value: " << b << "  Rounded Value: " << ceil(b + 0.5) << endl;
    cout << "Original Value: " << c << "  Rounded Value: " << ceil(c + 0.5) << endl;
}