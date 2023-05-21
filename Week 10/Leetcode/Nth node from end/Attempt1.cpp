#include <bits/stdc++.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    int getLen(ListNode* &head)
    {
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        return length;
    }

    void deleteAtTail(ListNode* &head, int length)
    {
        int count = 1;
        ListNode* prev = head;
        while(count<length)
        {
            prev = prev->next;
            count++;
        }
        ListNode* curr = prev->next;
        prev->next = NULL;
        delete curr;
        return;
    }

    void deleteAtHead(ListNode* &head)
    {
        if(head==NULL)
            return;
        
        if(head->next == NULL)
        {
            delete head;
            return;
        }

        ListNode* temp = head;
        ListNode* curr = head->next;
        head = curr;
        delete temp;
        return;
    }

    void deleteAfterPosition(ListNode* &head, int position)
    {
        int currpos = 1;
        ListNode* prevNode = head;
        while(currpos < position)
        {
            prevNode = prevNode -> next;
            currpos++;
        }
        ListNode* currNode = prevNode->next;
        ListNode* forward = currNode->next;
        prevNode->next = forward;
        currNode->next = NULL;
        delete currNode;
        return;
    }

    void print(ListNode* &head)
    {
        ListNode* temp = head;
        int length = getLen(head);
        int count = 0;
        while(count<length)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
            count++;
        }
        return;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLen(head);
        cout<<length<<endl;
        if(head==NULL)
            return head;

        // if(length==n)
        // {
        //     deleteAtHead(head);
        //     return head;
        // }

        // if(n==1)
        // {
        //     deleteAtTail(head, n);
        //     return head;
        // }

        //deleteAfterPosition(head, length-n);
        int currpos = 1;
        ListNode* prevNode = head;
        int position = length - n;
        while(currpos < position)
        {
            prevNode = prevNode -> next;
            currpos++;
        }
        ListNode* currNode = prevNode->next;
        ListNode* forward;
        forward = currNode->next;
        prevNode->next = forward;
        currNode->next = NULL;
        delete currNode;
        print(head);
        cout<<endl;
        ListNode* newHead = head;

        return newHead;
    }
};