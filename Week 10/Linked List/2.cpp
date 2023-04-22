#include <bits/stdc++.h>
using namespace std;

class Node{
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

};

void print (Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertAtHead(Node* & head, Node* &tail, int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    if(head == NULL)
    {
        //Empty LL
        tail = newNode;
    }
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    Node* newNode = new Node(data);
    if(tail == NULL)
    {
        //first node:
        tail = newNode;
        head = newNode;
    }
    //non-empty LL:
    else
        tail->next = newNode;
    if(head == NULL)
    {
        head = newNode;
    }
    tail = newNode;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 70);
    insertAtHead(head,tail,  100);
    insertAtTail(head, tail,200);

    print(head);

    return 0;
}