//Bank Account Program
#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

int main()
{
    //Creation of two Account objects
    Account account1{"John Doe",500};
    Account account2{"Molly Heart",500};

    //display initial value of name for each Account and Balance
    cout << account1.getName() << " balance: " << account1.getBalance() << endl;
    cout << account2.getName() << " balance: " << account2.getBalance() << endl;

    cout << "\n\nEnter deposit amount for account1: "; //Prompt
    int depositAmount;
    cin >> depositAmount; //Obtain user input
    cout << "adding " << depositAmount << " to account1 balance";
    account1.deposit(depositAmount); //add deposit into account1's balance

    // display balances
    cout << "\n\n" << account1.getName() << " balance: " << account1.getBalance() << endl;
    cout << account2.getName() << " balance: " << account2.getBalance() << endl;


    cout << "\n\nEnter deposit amount for account2: "; //Prompt
    cin >> depositAmount; //Obtain user input
    cout << "adding " << depositAmount << " to account2 balance";
    account2.deposit(depositAmount); //add deposit into account2's balance

    // display balances
    cout << "\n\n" << account1.getName() << " balance: " << account1.getBalance() << endl;
    cout << account2.getName() << " balance: " << account2.getBalance() << endl;

    cout << "Enter withdrawal amount for account1: "; //Prompt
    int withdraw;
    cin >> withdraw;
    cout << "Withdrawing " << withdraw << " from the balance of account 1" << endl;
    account1.withdraw(withdraw);

    // display balances
    cout << "\n" << account1.getName() << " balance: " << account1.getBalance() << endl;


}