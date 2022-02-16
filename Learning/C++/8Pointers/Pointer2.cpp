//Array, Pointer, Dynamic Memory Practice
#include <iostream>
using namespace std;


int main()
{
   int rows, cols;
   cout << "How many rows: ";
   cin >> rows;
   cout << "How many columns: ";
   cin >> cols;

   int** table = new int*[rows];

   for(int i = 0; i < rows; i++)
   {
       table[i] = new int[cols];
   }

   for(int i = 0; i < rows; i++)
   {
       delete[] table[i];
   }

   delete[] table;
   table = NULL;




    system("pause>0");
    return 0;
}


