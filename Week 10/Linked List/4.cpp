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
    {
        cout<<"Node with value "<<this->data<<" is deleted"<<endl;
    }
};

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
}

void insertAtTail(Node* &head, Node* &tail, int data)
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

int findLength(Node* head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtPosition(int position, Node* &head, Node* &tail, int data)
{
    if(position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);

    if(position >=len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    //Find the position
    int i = 1;
    Node* prev = head;
    while(i<position)
    {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    //step2
    Node* newNode = new Node(data);

    //step 3
    newNode->next = curr;

    //step 4
    prev->next = newNode;

}

void deleteNode(int position, Node* &head, Node* &tail)
{
    if(head==NULL)
    {
        cout<<"Cannot delets, LL is empty";
        return;
    }

    if(position==1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    int len = findLength(head);

    if(position==len)
    {
        //find prev
        Node* prev = head;
        int i=1;
        while(i<position-1)
        {
            prev = prev->next;
            i++;
        }
        //2
        prev->next = NULL;
        //3
        Node* temp = tail;
        tail = prev;
        //4
        delete temp;
        return;
    }

    Node* prev = head;
    int i=1;
    while(i<position-1)
    {
        prev= prev->next;
        i++;
    }
    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    //prev->next = curr;
    delete curr;
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
    // insertAtHead(head, tail, 10);
    // insertAtHead(head, tail, 20);
    // insertAtHead(head, tail, 30);
    // insertAtTail(head, tail, 35);
    // insertAtHead(head, tail, 40);
    // insertAtTail(head, tail, 45);
    // print(head);
    // cout<<endl;
    // insertAtPosition(2, head, tail, 100);
    // insertAtPosition(4, head, tail, 325);
    // print(head);
    // cout<<"Length is: "<<findLength(head);

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 50);
    insertAtPosition(2, head, tail, 105);
    insertAtTail(head, tail, 70);
    print(head);
    cout<<endl;
    deleteNode(3,head,tail);
    print(head);
    deleteNode(5,head,tail);
    return 0;
}