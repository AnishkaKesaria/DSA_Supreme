// WIthout STL

#include <iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    //function

    void push(int data)
    {
        if(size-top>1)
        {
            //Space available
            top++;
            arr[top] = data;
        }
        else // Space not available
            cout<<"Stack Overflow";
        return;
    }

    void pop()
    {
        if(top!=-1)
            top--;
        else
            cout<<"Stack Underflow";
        return;
    }

    int getTop()
    {
        if(top==-1)
            cout<<"Stack is Empty";
        else
            return arr[top];
        return 0;
    }

    int getSize()
    {
        return top+1;
    }

    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack s(10);
    s.push(10);
    s.push(30);
    s.push(60);
    while(!s.isEmpty())
    {
        cout<<s.getTop()<<endl;
        s.pop();
    }
    cout<<"Size of stack: "<<s.getSize()<<endl;
    s.pop();
    return 0;
}