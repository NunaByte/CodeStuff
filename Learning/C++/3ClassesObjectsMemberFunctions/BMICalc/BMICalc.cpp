#include <iostream>
using namespace std;

int main()
{
    //Establishes needed varaibles
    int weight;
    int finalWeight;
    int height;
    int bmi;


    std::cout << "#######################################################" << std::endl;
    std::cout << "WELCOME TO THE BMI CALCULATOR" << std::endl;
    std::cout << "#######################################################\n" << std::endl;

    std::cout << "Please Enter Your Weight(In Pounds): ";
    std::cin >> weight;
    finalWeight = weight * 703;
    
    std::cout << "Please Enter Your Height(In Inches): ";
    std::cin >> height;
    bmi = finalWeight/(height*height);
    std::cout << "#######################################################" << std::endl;


    if(bmi < 18.5)
    {
        std::cout << "Your BMI: " << bmi << "\nCategory: Underweight" << std::endl;
    }
    if(bmi > 18.5 && bmi < 24.9)
    {
        std::cout << "Your BMI: " << bmi << "\nCategory: Normal weight" << std::endl;
    }
    if(bmi > 25 && bmi < 29.9)
    {
        std::cout << "Your BMI: " << bmi << "\nCategory: Overweight" << std::endl;
    }
    if(bmi > 30)
    {
        std::cout << "Your BMI: " << bmi << "\nCategory: Obese" << std::endl;
    }

    std::cout << "#######################################################" << std::endl;

    std::cout << "BMI Categories:\nUnderwight = <18.5\nNormal weight = 18.5-24.9\nOverweight = 25-29.9\nObesity = BMI of 30 or greater" << std::endl;


    return 0;
}