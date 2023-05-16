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

Node* reverse(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    while(curr!=NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    Node* newNode = new Node(data);

    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
    return;
}

Node* solve(Node* &head1, Node* &head2)
{
    //1 - REVERSE
    head1 = reverse(head1);
    head2 = reverse(head2);

    //2 - ADD
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    while(head1!=NULL && head2!=NULL)
    {
        int sum = carry + head1->data + head2->data;
        int digit = sum%10;
        carry = sum/10;
        insertAtTail(ansHead, ansTail, digit);
        head1 = head1->next;
        head2 = head2->next;
    }

    while(head1!=NULL)
    {
        int sum = carry + head1->data;
        int digit = sum%10;
        carry = sum/10;
        insertAtTail(ansHead, ansTail, digit);
        head1 = head1->next;
    }

    while(head2!=NULL)
    {
        int sum = carry + head2->data;
        int digit = sum%10;
        carry = sum/10;
        insertAtTail(ansHead, ansTail, digit);
        head2 = head2->next;
    }

    while(carry!=0)
    {
        int digit = carry%10;
        carry = carry/10;
        insertAtTail(ansHead, ansTail, digit);
    }

    //3 - REVERSE ANS;
    ansHead = reverse(ansHead);
    return ansHead;
}

int main()
{
    Node* head1 = new Node(1);
    Node* second1 = new Node(0);
    Node* head2 = new Node(1);
    Node* second2 = new Node(0);
    Node* third2 = new Node(0);

    head1->next = second1;
    head2->next = second2;
   // second2->next = third2;

    print(head1);
    print(head2);

    Node* ans = solve(head1, head2);
    print(ans);

    return 0;
}