#include <iostream>
using namespace std;

struct CardDeck
{
    int A[5];
    int size;
    int length;
};


bool solution(string inputString) 
{
    string reverse;
    int base{0};
    int n = inputString.length();
    
    for(int i = 0; i < n; i++)
    {
        reverse[base] = inputString[i];
        base++;
    }
    
    if(reverse == inputString)
    {
        return true;
    }
    else
        return false;
    
}


void insertionSort(CardDeck *deck)
{
    int j,i,key;
    for(j= 1; j < deck->length; j++)
    {
        key=deck->A[j];
        i = j-1;
        while((i>=0)&&(deck->A[i] > key))
        {
            deck->A[i+1] = deck->A[i];
            i = i-1;
        }
        deck->A[i+1] = key;
    }
}

void Display(CardDeck deck)
{
    int i;
    cout << "The elements of the deck are: ";
    for(i = 0; i < deck.length; i++)
    {
        cout << deck.A[i] << " ";
    }
    cout << endl;
}


int main()
{
    string inputString = "aabaa";
    string reverse;
    int base{0};
    int n = inputString.length();
    
    for(int i = 0; i < n; i++)
    {
        reverse[base] = inputString[i];
        base++;
    }
    cout << reverse;

}
    