#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        cout<<this->data<<" is deleted"<<endl;
    }
};

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int getLength(Node* head)
{
    Node* temp = head;
    int len = 0;
    while(temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
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
    newNode -> next = head;
    head->prev = newNode;
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
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if(position==1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int len = getLength(head);
    if(position>len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node* prevNode = head;

    int i=1;
    while(i<position-1)
    {
        prevNode = prevNode->next;
        i++;
    }

    Node* currNode = prevNode -> next;

    Node* newNode = new Node(data);

    newNode->next = currNode;
    currNode->prev = newNode;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    return;
}

void deleteFromPostion(Node* &head, Node* &tail, int position)
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }

    if(head->next == NULL)
    {
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if(position==1)
    {
        Node* temp = head;
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);

    if(position>len)
    {
        cout<<"Invalid position!"<<endl;
        return;
    }

    if(position==len)
    {
        Node* temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }

    Node* left = head;
    int i=0;
    while(i<position-1)
    {
        left = left->next;
        i++;
    }
    Node* curr = left->next;
    Node* right = curr->next;
    left->next = right;
    right->prev = left;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
    return;
}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* head = first;
    Node* tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    print(first);
    cout<<endl;

    insertAtHead(head, tail, 101);
    print(head);
    cout<<endl;

    insertAtTail(head, tail, 500);
    print(head);
    cout<<endl;

    insertAtPosition(head, tail, 2, 125);
    print(head);
    cout<<endl;

    cout<<"Length: "<<getLength(head)<<endl;

    cout<<"HEAD = "<<head->data<<endl;
    cout<<"TAIL = "<<tail->data<<endl;

    //deleteFromPostion(head,tail,1);

    deleteFromPostion(head, tail, 10);
    print(head);

    return 0;
}