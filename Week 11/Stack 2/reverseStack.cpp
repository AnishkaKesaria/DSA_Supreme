#include <bits/stdc++.h>
using namespace std;


void inserAtBottom(stack <int> &s, int &target)
{
    if(s.empty())
    {
        s.push(target);
        return;
    }

    int top = s.top();
    s.pop();
    inserAtBottom(s, target);
    s.push(top);
    return;
}

void reverseStack(stack<int> &s)
{
    if(s.empty())
        return;

    int target = s.top();
    s.pop();
    reverseStack(s);
    inserAtBottom(s, target);
    return;
}



int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    reverseStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}