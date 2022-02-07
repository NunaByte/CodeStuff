//Testing of Employee Class
#include <iostream>
#include <string>
#include "Employee.h"

int main()
{
    //Varaibles needed
    int raise;

    //Creation of objects
    Employee emp1{"John","Stark",80000};
    Employee emp2{"Arya","Stark",90000};

    //Display of the object salaries
    std::cout << emp1.getFirst() << " " << emp1.getLast() << " salary is: " << emp1.getSalary() << std::endl;
    std::cout << emp2.getFirst() << " " << emp2.getLast() << " salary is: " << emp2.getSalary() << std::endl;
    std::cout << std::endl;


    //Display of the object salaries after 10% raise
    raise = (emp1.getSalary()/100)*110;
    std::cout << emp1.getFirst() << " " << emp1.getLast() << " salary is: " << raise << std::endl;
    raise = (emp2.getSalary()/100)*110;
    std::cout << emp2.getFirst() << " " << emp2.getLast() << " salary is: " << raise << std::endl;
    std::cout << std::endl;


}