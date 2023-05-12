//Reverse K nodes

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

Node* getMid(Node* &head)
{
    if(head == NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return head;
    }

    if(head->next == NULL)
        return head;

    Node* slow = head;
    Node* fast = head;
//    Node* fast = head->next; If you want 30 as an ans

    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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

Node* reverseKNodes(Node* &head, int k)
{
    if(head == NULL)
    {
        cout<<"LL is empty"<<endl;
        return head;
    }

    int len = getLength(head);

    if(k>len)
    {
        //cout<<"Enter valid value for k!"<<endl;
        return head;
    }

    //A : Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    int count = 0;

    while(count<k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward!=NULL)
    {
        head->next = reverseKNodes(forward, k);
    }

    return prev;

}

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);
    cout<<endl;

    cout<<"Middle Node is: "<<getMid(head)->data<<endl;
    cout<<"Length: "<<getLength(head)<<endl;

    head = reverseKNodes(head,5);
    print(head);

    return 0;
}