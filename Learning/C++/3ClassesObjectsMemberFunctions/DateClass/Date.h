#include <string>
#include <iostream>

 class Date
 {
     public:

     explicit Date(int m,int d, int y)
     : day{d}, year{y}
     {
         if(m < 0 || m > 12)
         {
             month = 1;
         }
         else
         {
             month = m;
         }
     }
     //Set and Get for month
     void setMonth(int m)
     {
         month = m;
     }
     int getMonth()
     {
         return month;
     }
     //Set and Get for day
     void setDay(int d)
     {
         day = d;
     }
     int getDay()
     {
         return day;
     }
     //Set and Get for year
     void setYear(int y)
     {
         year = y;
     }
     int getYear()
     {
         return year;
     }
     //Display date function
     void displayDate()
     {
         std::cout << month << "/" << day << "/" << year;
     }


     private:

     int month;
     int day;
     int year;
 };