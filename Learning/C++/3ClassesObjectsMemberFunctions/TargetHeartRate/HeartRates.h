#include <string>
#include <iostream>

class HeartRates
{
    public:
    //Constructor
    HeartRates(std::string first,std::string last, int m, int d, int y)
     : firstName{first}, lastName{last}, year{y}
    {
        if(m > 12 || m < 1)
        {
            month = 1;
        }
        else
        {
            month = m;
        }
        if(d > 31 || d < 1)
        {
            day = 1;
        }
        else
        {
            day = d;
        }
    }

    //Setters and getters for name
    //First Name
    void setFirstName(std::string first)
    {
        firstName = first;
    }
    std::string getFirstName() const
    {
        return firstName;
    }
    //Last Name
    void setLastName(std::string last)
    {
        lastName = last;
    }
    std::string getLastName() const
    {
        return lastName;
    }

    //Setters and getters for birthday
    void setBirthday(int m, int d, int y)
    {
        month = m;
        day = d;
        year = y;
    }
    void showBirthday() const
    {
        std::cout << "Date of birth: " << month << "/" << day << "/" << year << std::endl;
    }

    //Function to calculate age
    int getAge()
    {
        int age = 2022 - year;
        return age;
    }

    //Function to get maximum heart rate
    int getMaximumHeartRate()
    {
        int maxHeart;
        maxHeart = 220 - getAge();
        return maxHeart;
    }

    int getTargetHeartRate()
    {
        return getMaximumHeartRate() / 2;
    }

    //Function to display all info
    void displayData() 
    {
        std::cout << "Name: " << firstName << " " << lastName << std::endl;
        showBirthday();
        std::cout << "Age: " << getAge() << std::endl;
        std::cout << "Maximum Heart Rate: " << getMaximumHeartRate() << std::endl;
        std::cout << "Target Heart Rate: " << getTargetHeartRate() << std::endl; 

        
    }


    private:
    std::string firstName;
    std::string lastName;
    int month;
    int day;
    int year;
};