#include <string>

class Employee
{
    public:
        Employee(std::string first, std::string last, int sal)
            : firstName{first}, lastName{last}
        {
            if(sal > 0)
            {
                salary = sal;
            }
            if(sal < 0)
            {
                salary = 0;
            }
        }

        //Set and get for first name
        void setFirst(std::string first)
        {
            firstName = first;
        }
        std::string getFirst()
        {
            return firstName;
        }
        //Set and get for last name
        void setLast(std::string last)
        {
            lastName = last;
        }
        std::string getLast()
        {
            return lastName;
        }

        //Set and get for Salary
        void setSalary(int sal)
        {
            if(sal > 0)
            {
                salary = sal;
            }
            if(sal < 0)
            {
                salary = 0;
            }
        }
        int getSalary()
        {   
            return salary;
        }






    private:
    std::string firstName;
    std::string lastName;
    int salary;
};