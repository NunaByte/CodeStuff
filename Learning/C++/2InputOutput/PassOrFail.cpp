//Program determines if a student has passed or failed based off of an average of grades.
#include <iostream>

int main()
{
    //Variables needed
    int a, b, c, d, e;
    int average;

    //Prompts user to enter 5 integers and stores those entries into the variables declared
     std::cout<< "###############################################\n";
     std::cout<< "Welcome To Pass Or Fail\n";
     std::cout<< "###############################################\n";
     std::cout << "Please enter your 5 grades: ";
     std::cin >> a >> b >> c >> d >> e;
     
    //Calculates the average
     average = ((a+b+c+d+e)/5);

    //Compares the average calculated to the value of 70 to determine if passed or failed
     if(average > 70)
     {
         std::cout << "Congratulations, you have passed the course with a(an): " << average << " average";
     }

     if(average < 70)
     {
         std::cout << "Sorry but you did not pass the course with an average of: " << average << ", better luck next time";
     }

     return 0;

}