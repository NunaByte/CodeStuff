#include <iostream>
using namespace std;

struct CardDeck
{
    int *A;
    int size;
    int length;
};

void Display(CardDeck &deck)
{
    int i;
    cout << "The elements of the deck are: ";
    for(i = 0; i < deck.length; i++)
    {
        cout << deck.A[i] << " ";
    }
    cout << endl;
}

void Add(CardDeck *deck, int x)
{
    if(deck->length<deck->size)
    {
        deck->A[deck->length++] = x;
    }
}

void Insert(CardDeck *deck, int index, int x)
{
    if(deck->length<deck->size)
    {
        int i;
        for(i = deck->length; i > index; i--)
        {
            deck->A[i] = deck->A[i-1];
        }
        deck->A[index] = x;
        deck->length++;
    }
}

int Delete(CardDeck *deck, int index)
{
    int i;
    if(index>=0 && index<deck->length)
    {
        for(i = index; i<deck->length; i++)
    {
        deck->A[i] = deck->A[i+1];
    }
        deck->length--;
    }

    return 0;
}

void Search(CardDeck *deck, int key)
{
    cout << "Searching for " << key << endl;
    int i;
    bool found = false;
    for(i = 0; i < deck->length; i++)
    {
        if(deck->A[i] == key)
        {
            found = true;
        }
    }
    if(found)
    {   
        cout << key << " was found!";
    }
    else
        cout << key << " was not found :(";
    
}

int BinarySearch(CardDeck deck, int key)
{
    int l,mid,h;
    l=0;
    h=deck.length-1;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==deck.A[mid])
            return mid;
        else if(key<deck.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return 0;
}

int main()
{
    CardDeck deck;

    cout << "Enter how big do you want the deck to be: ";
    cin >> deck.size;

    deck.A = new int[deck.size];

    cout << "\nHow many cards are in the deck currently: ";
    cin >> deck.length;

    int i;

    for(i = 0; i<deck.length; i++)
    {
        cout << "Enter value " << i+1 << ": " ;
        cin >> deck.A[i];
    }

    Display(deck);
    Search(&deck, 5);


}
    