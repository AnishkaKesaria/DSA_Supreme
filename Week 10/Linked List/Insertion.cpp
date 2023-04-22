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
};

void InsertAtHead(Node* &head, Node* &tail, int data)
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
}

void InsertAtTail(Node* &head, Node* &tail, int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

int findLen(Node* head)
{
    Node* temp = head;
    int len = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void InsetAtPosition(Node* &head, Node* &tail, int position, int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 0)
    {
        InsertAtHead(head, tail, data);
        return;
    }

    int len = findLen(head);

    if(position >= len)
    {
        InsertAtTail(head, tail, data);
        return;
    }

    //traverse till position
    int i = 1;
    Node* prev = head;
    while(i<position)
    {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    //create node
    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;

    return;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 20);
    InsertAtTail(head, tail, 50);
    InsetAtPosition(head, tail, 2, 105);
    InsertAtTail(head, tail, 70);

    print(head);
    return 0;
}
