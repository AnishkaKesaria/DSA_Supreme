//Pyaari approach

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

void insertAtTail(Node* &head, Node* &tail, int data)
{
    if(head == tail)
    {
        Node* newNode = new Node(data);
        head->next = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
    return;
}

void Sort(Node* &head)
{
    if(head==NULL)
    {
        return;
    }

    Node* temp = head;
    Node* zeroKaHead = new Node(-1);
    Node* zeroTail = zeroKaHead;
    Node* oneKaHead = new Node(-1);
    Node* oneKaTail = oneKaHead;
    Node* twoKaHead = new Node(-1);
    Node* twoKaTail = twoKaHead;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            insertAtTail(zeroKaHead,zeroTail,0);
        }
        else if(temp->data == 1)
        {
            insertAtTail(oneKaHead,oneKaTail,1);
        }
        else if(temp->data == 2)
        {
            insertAtTail(twoKaHead,twoKaTail,2);
        }
        Node* dummy = temp;
        temp = temp->next;
        dummy->next = NULL;
        delete dummy;
    }

    Node* dummy1 = oneKaHead;
    oneKaHead = oneKaHead->next;
    delete dummy1;

    Node* dummy2 = twoKaHead;
    twoKaHead = twoKaHead->next;
    delete dummy2;

    if(oneKaHead!=NULL)
    {
        zeroTail->next = oneKaHead;
        if(twoKaHead!=NULL)
        {
            oneKaTail->next = twoKaHead;
        }
    }
    else if(twoKaHead!=NULL)
    {
        zeroTail->next = twoKaHead;
    }

    Node* dummy = zeroKaHead;
    head = zeroKaHead->next;
    dummy-> next = NULL;
    delete dummy;
    

    // Node* temporary = head;

    // while(temporary->next!=NULL)
    // {
    //     temporary = temporary->next;
    // }

    // temporary->next = oneKaHead;

    // while(temporary->next!=NULL)
    // {
    //     temporary = temporary->next;
    // }

    // temporary->next = twoKaHead;

    return;
}

int main()
{
    Node* head = new Node(2);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* newNode = new Node(2);
    Node* fourth = new Node(2);
    Node* fifth = new Node(2);

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