#include <iostream>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};


Array* Merge(Array *arr1, Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array;

    while(i<arr1->length && j <arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length=arr1->length+arr2->length;

    return arr3;
}

void Display(Array arr)
{
    int i;
    cout << "\nElements are\n";
    for(i=0; i<arr.length;i++)
    {
        cout << arr.A[i] << " ";
    }
}

void StringLength(char array[])
{
    int i;
    for(i = 0; array[i] != '\0'; i++);
    {

    }
    cout << "String length is: " << i; 
}

void InsertionSort(Array *arr)
{
    int i,j,key;
    for(i=1; i<arr->length; i++)
    {
        key = arr->A[i];
        j = i-1;

        //Move elements that are greater than key to one position ahead
        while(j >= 0 && arr->A[j] > key)
        {
            arr->A[j + 1] = arr->A[j];
            j--;
        }
        arr->A[j+1] = key;
    }
}

int main()
{
    Array arr1={{5,4,3,7,9},10,5};
    Array arr2={{3,4,7,18,20},10,5};
    char stringArray[20] = "STRING";
    
    for(int i = 0; stringArray[i]!='\0'; i++)
    {
        stringArray[i] += 32;
    }

    for(int i = 0; stringArray[i]!='\0'; i++)
    {
        cout << stringArray[i];
    }

    

    return 0;
}
    