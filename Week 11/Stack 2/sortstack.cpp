#include <bits/stdc++.h>
using namespace std;

void insertInSorted(stack<int> &s, int target)
{
    if(s.empty())
    {
        s.push(target);
        return;
    }

    int temp = s.top();

    if(target<=temp)
    {
        s.push(target);
        return;
    }

    s.pop();
    insertInSorted(s,target);
    s.push(temp);
    return;
}

void sortStack(stack<int> &s)
{
    if(s.empty())
        return;

    int temp = s.top();
    s.pop();
    sortStack(s);
    insertInSorted(s, temp);
    return;
}

int main()
{
    stack <int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);
    sortStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}