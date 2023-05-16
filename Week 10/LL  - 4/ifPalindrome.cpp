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
};

Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    while(curr!= NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

bool checkPalindrome(Node* &head)
{
    if(head==NULL)
    {
        cout<<"LL is empty"<<endl;
        return 1;
    }

    if(head->next==NULL)
    {
        return 1;
    }

    //A - Find mid node
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast!= NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    //slow is pointing to mid node

    //B - reverse LL after mid node
    Node* reverseKaHead = reverse(slow->next);
    slow->next = reverseKaHead; //Joining could be skipped

    //C- start comparison
    Node* temp1 = head;
    Node* temp2 = reverseKaHead;

    while(temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            return false;
        }
        else
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // if(temp2==NULL && temp1==slow)
    // {
    //     return true;
    // }

    return true;
}

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* newNode = new Node(30);
    Node* fourth = new Node(20);
    Node* fifth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = newNode;
    newNode->next = fourth;
    fourth->next = fifth;

    bool isPalindrome = checkPalindrome(head);

    if(isPalindrome)
        cout<<"LL is a valid palindrome"<<endl;
    else
        cout<<"LL is not a palindrome"<<endl;

    return 0;
}