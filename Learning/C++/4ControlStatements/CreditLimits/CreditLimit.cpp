#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    unsigned int actNumber{0};
    unsigned int bBalance{0};
    int charges{0};
    int credits{0};
    int creditLimit{0};
    int nBalance{0};

    
    while(actNumber != -1)
    {
        cout << "Enter account number (or -1 to quit): ";
        cin >> actNumber;
        
        if(actNumber != -1)
        {

            cout << "Enter beginning balance: ";
            cin >> bBalance;
            
            cout << "Enter total charges: ";
            cin >> charges;

            cout << "Enter total credits: ";
            cin >> credits;

            cout << "Enter credit limit: ";
            cin >> creditLimit;

            nBalance = (bBalance + charges) - credits;

            if(nBalance <  creditLimit)
            {
               cout << "New balance is " << nBalance << endl;
               cout << endl;
            }
            else
            {
               cout << "New balance is " << nBalance << endl;
               cout << "Account: " << setw(5) << actNumber << endl;
               cout << "Credit limit: " << creditLimit << endl;
               cout << "Balance: " << nBalance << endl;
               cout << "Credit Limit Exceeded." << endl;
               cout << endl;
            }   
        }
    }
}