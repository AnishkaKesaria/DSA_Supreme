#include <bits/stdc++.h>
using namespace std;

void insertInSorted(stack<int> &s,int target)
{
    if(s.empty())
    {
        s.push(target);
        return;
    }

    int temp = s.top();

    //base case
    if(target<temp)
    {
        s.push(target);
        return;
    }


    s.pop();
    insertInSorted(s,target);
    s.push(temp);
    return;
}

int main()
{
    stack<int> s;
    s.push(8);
    s.push(6);
    s.push(4);
    s.push(2);
    int target = 5;
    insertInSorted(s,5);
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}