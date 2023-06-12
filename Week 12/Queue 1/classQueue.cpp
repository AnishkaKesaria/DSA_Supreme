#include <bits/stdc++.h>
using namespace std;

class Queue
{
    public:
    int size;
    int *arr;
    int front;
    int rear;

    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        this->front = 0;
        this->rear = 0;
    }

    void push(int value)
    {
        if(rear==size)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        // if(front==0)
        // {
        //     arr[rear] = value;
        //     rear++;
        //     front++;
        //     return;
        // }
        arr[rear] = value;
        rear++;
        return;
    }

    void pop()
    {
        if(front == rear)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        arr[front] = -1;
        front++;
        if(front==rear)
        {
            front = 0;
            rear = 0;
        }
        return;
    }

    void getfront()
    {
        if(front==rear)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<arr[front]<<endl;
        return;
    }

    bool isEmpty()
    {
        if(front==rear)
            return 1;
        else
            return 0;
    }

    int getSize()
    {
        int len = rear - front;
        return len;
    }
};

int main()
{
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.getfront();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.getfront();
    q.push(100);
    return 0;
}