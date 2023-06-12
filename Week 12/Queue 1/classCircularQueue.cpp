#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    CircularQueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        //Queue full
        if((front==0 && rear==size-1) || rear == front-1)
        {
            cout<<"CQ is full";
            return;
        }
        //First element
        else if(front== -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        //Circular nature
        else if(rear==size-1 && front !=0)
        {
            rear = 0;
            arr[rear] = val;
            return;
        }
        //normal
        rear++;
        arr[rear] = val;
    }

    void pop()
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
        arr[front]= -1;
        front++;
        return;
        //Normal
    }

};


int main()
{
    return 0;
}