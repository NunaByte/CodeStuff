//Code template

#include <iostream>
#include <math.h>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void displayArray(Array arr)
{
    cout << "Elements of the array are: " << endl;
    for(int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void addElements(Array *arr, int x)
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void deleteElement(Array *arr, int value)
{
    if((value >=0))
    {
        int index;

        for(int i=0; i < arr->length; i++)
        {
            if(value == arr->A[i])
            {
                index = i;
            }
        }

        for(int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;

    }
}

void reverseArray(Array *arr)
{
    for(int i = 0,j= arr->length; i < arr->length; i++,j--)
    {
        char temp;
        temp = arr->A[j];
        arr->A[i] = temp;
    }
}

int binarySearch(Array arr, int key)
{
    int l,mid,h;
    l = 0;
    h = arr.length-1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key == arr.A[mid])
        {
            return mid;
        }
        else if(key < arr.A[mid])
        {
            h = mid-1;
        }
        else
            l = mid+1;
    }
    return -1;
}





int main()
{
    Array arr;
    arr.size = 10;
    arr.length = 5;
    arr.A = new int[arr.size];

    for(int i=0; i < arr.length; i++)
    {
        cout << "Enter value " << i+1 << ": ";
        cin >> arr.A[i];
    }

    displayArray(arr);


    delete[] arr.A;
    arr.A = NULL;

}
    
