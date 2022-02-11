#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

int main()
{
    Date date1{2,10,2022};

    date1.displayDate();
    cout << endl;

    date1.setDay(22);

    date1.displayDate();
}