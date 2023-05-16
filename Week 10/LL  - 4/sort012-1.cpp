// Brute Force - Counting

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {}
};

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

int getLen(Node* &head)
{
    Node* temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void Sort(Node* &head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    int len = getLen(head);
    Node* temp = head;
    for(int i=0; i<len; i++)
    {
        if(temp->data == 0)
        {
            zeroCount++;
            temp = temp->next;
        }
        else if (temp->data == 1)
        {
            oneCount++;
            temp = temp->next;
        }
        else if(temp->data==2)
        {
            twoCount++;
            temp = temp->next;
        }
    }

//    cout<<zeroCount<<" "<<oneCount<<" "<<twoCount<<" ";

    temp = head;
    while(zeroCount!=0)
    {
        temp->data = 0;
        temp= temp->next;
        zeroCount--;
    }

    while(oneCount!=0)
    {
        temp->data = 1;
        temp = temp->next;
        oneCount--;
    }

    while(twoCount!=0)
    {
        temp->data = 2;
        temp = temp->next;
        twoCount--;
    }

    return;
}

int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* newNode = new Node(0);
    Node* fourth = new Node(0);
    Node* fifth = new Node(0);

    head->next = second;
    second->next = third;
    third->next = newNode;
    newNode->next = fourth;
    fourth->next = fifth;

    cout<<"Input LL: ";
    print(head);

    cout<<"Output LL: ";
    Sort(head);
    print(head);

    return 0;
}