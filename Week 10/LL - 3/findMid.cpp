//Brute - HW

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
        this-> next = NULL;
    }

    ~Node()
    {
        cout<<this->data<<" has been deleted"<<endl;
    }
};

int getLength(Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

int findMid(Node* head)
{
    int len = getLength(head);
    int midindex;
    if(len%2==0)
        midindex = len/2;
    else
        midindex = len/2 +1;

    int i = 1;
    Node* mid = head;
    
    while(i<midindex)
    {
        mid = mid->next;
        i++;
    }

    return mid->data;
}

void insertAtHead(Node* &head, Node* &tail, int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return;
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void deleteAtPos(Node* &head, Node* tail, int index)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
        return;
    }

    if(index==1)
    {
        Node* temp = head;
        head = head->next;
        temp->next =  NULL;
        delete temp;
        return;
    }

    int len = getLength(head);

    if(index<=len)
    {
        Node* temp = head;
        int i=1;
        while(i<index-1)
        {
            temp = temp-> next;
            i++;
        }
        if(index==len)
        {
            tail = temp;
            tail->next = NULL;
            delete temp;
            return;
        }
        Node* forward = temp->next->next;
        Node* curr = temp->next;
        curr->next = NULL;
        temp->next = forward;
        delete curr;
        return;
    }
}


void print(Node* head)
{
    Node* temp = head;
    int len = getLength(head);
    int i = 0;
    while(i<len)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
        i++;
    }
    cout<<endl;
    return;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtTail(head, tail, 25);
    insertAtTail(head, tail, 15);
    //insertAtTail(head, tail, 5);
    print(head);

    cout<<"Mid of LL is "<<findMid(head)<<endl;

    deleteAtPos(head, tail, 2);
    print(head);
    return 0;
}