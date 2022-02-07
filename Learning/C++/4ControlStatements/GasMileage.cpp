//Calculates gas mileage based off of miles driven and gallons used
#include <iostream>


int main()
{
    double milesDriven{0};
    double galUsed{0};
    double milesDrivenTotal{0};
    double galUsedTotal{0};
    double mpg{0};
    double mpgTotal{0};


    
    while(milesDriven != -1)
    {
        std::cout << "Enter miles driven (-1 to quit): ";
        std::cin >> milesDriven;
        milesDrivenTotal += milesDriven;

        if(milesDriven != -1)
        {
            std::cout << "Enter gallons used: ";
            std::cin >> galUsed;
            galUsedTotal += galUsed;

            std::cout << "MPG this trip: " << milesDriven/galUsed << std::endl;
            std::cout << "Total MPG: " << milesDrivenTotal/galUsedTotal << std::endl;
            std::cout << "\n";


        }
    }
   

}