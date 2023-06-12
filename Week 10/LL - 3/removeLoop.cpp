//Remove Loop

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

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int getLength(Node* &head)
{
    int i=0;
    Node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

bool ifLoop(Node* &head)
{
    if(head==NULL)
        return false;

    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow)
            return true;
    }

    return false;

}

void removeLoop(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if(fast==slow)
        {
            slow = head;
            break;
        }
    }

    Node* prev = fast;

    while(slow!=fast)
    {
        prev = fast;
        fast = fast->next;
        slow = slow->next;
    }
    prev->next = NULL;

    return;
}


int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = fourth;

    //print(head);
    cout<<"Loop is: ";
    if(ifLoop(head))
        cout<<"present";
    else
        cout<<"absent";
    cout<<endl;

    removeLoop(head);

    cout<<"Loop is: ";
    if(ifLoop(head))
        cout<<"present";
    else
        cout<<"absent";
    cout<<endl;

    if(!ifLoop(head))
        print(head);

    return 0;
}