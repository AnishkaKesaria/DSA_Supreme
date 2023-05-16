// If LL is Palindrome

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

void removeDup(Node* &head)
{
    if(head==NULL)
    {
        cout<<"LL is empty"<<endl;
        return;
    }

    if(head->next == NULL)
    {
        cout<<"Single node in LL"<<endl;
        return;
    }

    Node* curr = head;
    while(curr!=NULL)
    {
        if(curr->next != NULL && curr->data == curr->next->data)
        {
            Node* temp = curr->next;
            temp->next = NULL;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return;
}

int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* newNode = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = newNode;
    newNode->next = fourth;
    fourth->next = fifth;

    cout<<"Input LL: ";
    print(head);

    cout<<"Output LL: ";
    removeDup(head);
    print(head);

    return 0;
}