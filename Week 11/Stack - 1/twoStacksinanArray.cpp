//Two stacks in an array

#include <iostream>
using namespace std;

class Stack
{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        if(top2-top1==1)
        {
            cout<<"Stack 1 overflow"<<endl;
            return;
        }
        top1++;
        arr[top1] = data;
        return;

    }

    void push2(int data)
    {
        if(top2-top1==1)
        {
            cout<<"Stack 2 overflow"<<endl;
            return;
        }
        top2--;
        arr[top2] = data;
        return;
    }

    void pop1()
    {
        if(top1==-1)
        {
            cout<<"Stack 1 underflow"<<endl;
            return;
        }
        top1--;
        cout<<arr[top1+1]<<endl;
        return;
    }

    void pop2()
    {
        if(top2==size)
        {
            cout<<"Stack 2 underflow"<<endl;
            return;
        }
        top2++;
        cout<<arr[top2-1]<<endl;
        return;
    }

    void print()
    {
        cout<<"Top 1: "<<top1<<endl;
        cout<<"Top 2: "<<top2<<endl;
        for(int i=0; i<size; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

};

int main()
{
    Stack s(10);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push2(5);
    s.push2(15);
    s.push2(25);
    s.print();
    s.pop1();
    s.print();
    s.pop2();
    s.print();
    s.pop2();
    s.pop2();
    s.pop2();
    s.push2(100);
    s.print();
    s.pop1();
    s.pop1();
    s.pop1();
    s.push1(500);
    s.push1(600);
    s.push1(700);
    s.push1(800);
    s.push2(555);
    s.push2(755);
    s.push2(955);
    s.push2(155);
    s.print();
    s.push2(399);
    s.push1(999);
    return 0;
}