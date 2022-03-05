#include <iostream>

using namespace std;


struct Node
{
    int data;
    Node *next;
}*first=NULL;

void create(int A[], int n)
{
    int i;
    Node *t,*last;
    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void Display(Node *p)
{
    while(p!=NULL)
    {
        cout << p->data << " ";
        p=p->next;
    }
}


int main()
{
    int A[] = {3,5,7,10,15};
    create(A,5);

    Display(first);

    return 0;
}
    
