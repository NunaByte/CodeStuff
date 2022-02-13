//Fig 7.13: GradeBook.h
// Definition of class GradeBook that uses an array to store test grades.
#include <string>
#include <array>
#include <iostream>
#include <iomanip> // parameterized stream manipulators

//GradeBook class defintion
class GradeBook
{
    public:
     // constant number of students who took the test
     static const size_t students{10}; // Note this is public data
    
    // constructor initializes courseName and grades array
    GradeBook(const std::string& name, const std::array<int, students>& gradesArray)
    : courseName{name}, grades{gradesArray}
    {

    }

    // setter and getter for course name

    // setter
    void setCourseName(const std::string& name)
    {
        courseName = name; // store the course name
    }

    // getter
    const std::string& getCourseName() const 
    {
        return courseName;
    }

    // function that displays a welcome message to the GradeBook user
    void displayMessage() const
    {
        // call getCourseName to get the name of this GradeBook's course
        std::cout << "Welcome to the grade book for\n" << getCourseName() << "!" << std::endl;
    }

    // function that performs various operations on the data (none modify the data)
    void processGrades() const
    {
        outputGrades(); //output grades array

        // call function getAverage to calculate the average grade
        std::cout << std::setprecision(2) << std::fixed;
        std::cout << "\nClass average is " << getAverage() << std::endl;

        // call functions getMinimum and get Maximum
        std::cout << "Loweest grade is " << getMinimum() << "\nHighest grade is " << getMaximum() << std::endl;

        outputBarChart(); //display grade distribution chart  
    }

    // function to find minimum grade
    int getMinimum() const
    {
        int lowGrade{100}; // assume lowest grade is 100

        //loop through grades array
        for(int grade : grades)
        {
            // if current grade is lower than lowGrade, assign it to lowGrade
            if(grade < lowGrade)
            {
                lowGrade = grade; // new lowest grade
            }
        }
        return lowGrade; // return lowest grade
    }

    // function to find maximum grade
    int getMaximum() const
    {
        int highGrade{100}; // assume highest grade is 0

        //loop through grades array
        for(int grade : grades)
        {
            // if current grade is higher than highGrade, assign it to highGrade
            if(grade > highGrade)
            {
                highGrade = grade; // new highest grade
            }
        }
        return highGrade; // return highest grade
    }

    // function to find the average of grades
    double getAverage() const
    {
        int total{0}; // initialize total

        // sum grades in array
        for (int grade : grades)
        {
            total += grade;
        }

        //return average of grades
        return static_cast<double>(total) / grades.size();
    }





    // output bar chart displaying grade distribution
    void outputBarChart() const
    {
        std::cout << "\nGrade distribution:" << std::endl;

        // stores frequencey of grades in each range of 10 grades
        const size_t frequencySize{11};
        std::array<unsigned int, frequencySize> frequency{}; // initializes to 0s

        // for each grade, increment the appropriate frequency
        for(int grade : grades)
        {
            ++frequency[grade / 10];
        }

        // for each grade frequency, print bar in chart
        for(size_t count{0}; count < frequencySize; ++count)
        {
            // output bar labels ("0-9:", ..., "90-99:", "100:")
            if(0 == count)
            {
                std::cout << " 0-9: ";
            }
            else if(10 == count)
            {
                std::cout << " 100: ";
            }
            else
            {
                std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
            }

            //print bar of astrisks
            for(unsigned int stars{0}; stars < frequency[count]; ++stars)
            {
                std::cout << '*';
            }

            std::cout << std::endl; // starts a new line of output
        }
    }



    // output the contents of the grades array
    void outputGrades() const
    {
        std::cout << "\nThe grades are:\n\n";

        //output each student's grade
        for(size_t student{0}; student < grades.size(); ++student)
        {
            std::cout << "Student " << std::setw(2) << student + 1 << ": " << std::setw(3) << grades[student] << std::endl;
        }
    }




    private:
     std::string courseName; // course name for this grade book
     std::array<int, students> grades; // array of student grades
};