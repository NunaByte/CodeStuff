//Class that will be used in AccountTest

#include <string>

class Account
{
    public:
        //constructor iniitializes data member name with parameter accountName
        explicit Account(std::string accountName, int initialBalance)
            : name{accountName} // member initializer
            {
                if(initialBalance > 0)
                {
                    balance = initialBalance;
                }
            }

        //Member function that deposits (adds) only a valid amount to the balance
        void deposit(int depositAmount)
        {
            if(depositAmount > 0)//A check to make sure deposit is greater than 0
            {
                balance += depositAmount; //Adds the depositAmount to the balance
            }
        }

        //Member function returns the account balance
        int getBalance() const
        {
            return balance;
        }

        //Member function that sets the aacount name in the object
        void setName(std::string accountName)
        {
            name = accountName; // store the account name
        }

        //Member function that retrieves the account name from the object
        std::string getName() const
        {
            return name; //return name's value to this function's caller
        }
    
    private:
        std::string name; // data member containing account holder's name
        int balance{0}; // data member with default initial value

}; // End Class Account