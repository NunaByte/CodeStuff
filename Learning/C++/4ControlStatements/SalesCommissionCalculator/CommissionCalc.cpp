//Program to calculate sales commissions
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed;
    double salary{0};
    double grossSales{0};

    while(grossSales != -1)
    {
        cout << "Enter sales in dollars (-1 to end): ";
        cin >> grossSales;

        if(grossSales != -1)
        {
            salary = ((grossSales/100) * 9) + 200;
            cout << "Salary is: $" <<  setprecision(2) << salary;
            cout << "\n\n";
        }
    }
}