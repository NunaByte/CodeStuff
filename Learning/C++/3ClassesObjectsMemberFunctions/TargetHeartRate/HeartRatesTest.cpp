#include <iostream>
#include <string>
#include "HeartRates.h"
using namespace std;

int main()
{
    string firstName;
    string lastName;
    int month;
    int day;
    int year;

    //Prompt and data collection
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter your birth month: ";
    cin >> month;
    cout << "Enter your birth day: ";
    cin >> day;
    cout << "Enter your birth year: ";
    cin >> year;
    cout << "\n";

    //Creation of HeartRates Object
    HeartRates Rate1{firstName,lastName,month,day,year};

    Rate1.displayData();
}