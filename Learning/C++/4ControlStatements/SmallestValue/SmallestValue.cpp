//Program finds the smallest value of a set of numbers
#include <iostream>

int main()
{
    int limit{0};
    int num{0};
    int max;
    int min;

    std::cout << "How many numbers would you like to enter(Type an Integer): ";
    std::cin >> limit;

    for(int i = 0; i < limit; i++)
    {
        std::cout << "Enter a number: ";
        std::cin >> num;
        if(i == 0)
        {
            max,min = num;
        }

        if(num > max)
        {
            max = num;
        }
        if(num < min)
        {
            min = num;
        }

        

    }
    std::cout << "The smallest value is " << min;
}