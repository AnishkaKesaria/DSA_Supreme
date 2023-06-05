#include <bits/stdc++.h>
using namespace std;

void solve(stack <int> &s, int target)
{
    if(s.empty())
    {
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s, target);
    s.push(temp);
    return;
}

void insertAtBottom(stack<int> &s)
{
    if(s.empty())
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    int target = s.top();
    s.pop();
    solve(s, target);
    return;
}



int main()
{
    stack <int> s;
    s.push(5);
    s.push(15);
    s.push(27);
    s.push(32);
    s.push(11);
    int top = s.top();
    insertAtBottom(s);
    cout<<"After:"<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}