/*Calculates how much to charge depending on how long
care was parked.*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Function prototype
void calculateCharges(double c1, double c2, double c3);

int main()
{
    //Arguments are how long each car has been parked
    calculateCharges(24,24,24);
}

//CalculateCharges Function
void calculateCharges(double c1, double c2, double c3)
{
    double charge{20.00};
    double chargeE{0};
    double total{0.0};
    double fee{5.00};
    double feeTotal{0};
    double totalHours = c1 + c2 + c3;

    cout << fixed << std::showpoint;
    cout << setprecision(2);

    cout << "Car" << setw(20) << "Hours" << setw(20) << "Charge" << endl;
    
    if(c1 > 3)
    {
        chargeE = c1;
        chargeE -= 3;
        feeTotal = (chargeE * fee) + charge;
        if(feeTotal > 50)
        {
            feeTotal = 50;
        }
        cout << 1 << setw(20) << c1 << setw(20) << feeTotal << endl;
        total += feeTotal;
    }
    else
    {
        feeTotal = charge;
        cout << 1 << setw(20)  << c1 << setw(20) << feeTotal << endl;
        total += feeTotal;
    }

    if(c2 > 3)
    {
        chargeE = c2;
        chargeE -= 3;
        feeTotal = (chargeE * fee) + charge;
        if(feeTotal > 50)
        {
            feeTotal = 50;
        }
        cout << 2 << setw(20) << c2 << setw(20) << feeTotal << endl;
        total += feeTotal;
    }
    else
    {
        feeTotal = charge;
        cout << 2 << setw(20) << c2 << setw(20) << feeTotal << endl;
        total += feeTotal;
    }

    if(c3 > 3)
    {
        chargeE = c3;
        chargeE -= 3;
        feeTotal = (chargeE * fee) + charge;
        if(feeTotal > 50)
        {
            feeTotal = 50;
        }
        cout << 3 << setw(20) << c3 << setw(20) << feeTotal << endl;
        total += feeTotal;
    }
    else
    {
        feeTotal = charge;
        cout << 3 << setw(20) << c3 << setw(20) << feeTotal << endl;
        total += feeTotal;
    }

    cout << "TOTAL" << setw(16) << totalHours << setw(20) << total;
}