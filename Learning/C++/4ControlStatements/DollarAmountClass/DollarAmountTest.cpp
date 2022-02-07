#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "DollarAmount.h"

int main()
{
    DollarAmount Test{10000};
    DollarAmount Test1{10000};

    Test.add(Test1);
    std::cout << Test.getPennies() << std::endl;
    Test.substract(Test1);
    std::cout << Test.getPennies();

}