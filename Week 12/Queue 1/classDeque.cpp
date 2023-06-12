#include <bits/stdc++.h>
using namespace std;


class Deque
{
    public:

    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data)
    {
        //Q is full
        if((rear==size-1 && front==0) || (rear == front-1))
        {
            cout<<"DQ is full, cannot push";
            return;
        }
        //First element
        else if(rear==-1)
        {
            front=0;
            rear=0;
            arr[rear] = data;
            return; 
        }
        //Circular nature
        else if(rear==size-1 && front!=0)
        {
            rear = 0;
            arr[rear] = data;
            return;
        }
        rear++;
        arr[rear] = data;
        return;
    }

    void pushFront(int data)
    {
        //DQ is full
        if((rear==size-1 && front==0) || (rear == front-1))
        {
            cout<<"DQ is full, cannot push";
            return;
        }
        //First element
        else if(rear==-1)
        {
            front=0;
            rear=0;
            arr[rear] = data;
            return; 
        }
        //Circular nature
        else if(front==0 && rear!=size-1)
        {
            front = size-1;
            arr[front] = data;
            return;
        }
        front--;
        arr[front] = data;
        return;
    }


    void popFront()
    {
        //Empty Stack
        if(front=-1)
        {
            cout<<"CQ is empty, cannot pop";
            return;
        }
        //Single ELement
        else if(front==rear)
        {
            arr[front] = -1;
            rear = -1;
            front = -1;
            return;
        }
        //Circular Nature
        else if(front==size-1)
        {
            arr[front]==-1;
            front = 0;
            return;
        }
        //Normal
        arr[front]= -1;
        front++;
        return;
    }

    void popRear()
    {
        if(front=-1)
        {
            cout<<"CQ is empty, cannot pop";
            return;
        }
        else if(front==rear)
        {
            arr[front] = -1;
            rear = -1;
            front = -1;
            return;
        }
        else if(rear==0)
        {
            arr[rear] = -1;
            rear = size-1;
            return;
        }
        arr[rear] = -1;
        rear--;
        return;
    }
};