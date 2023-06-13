#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int element;
        cin>>element;
        q.push(element);
    }
    stack<int> s;
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        s.push(front);
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    cout<<"Reversed Queue: "<<endl;
    for(int i = 0; i<n; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}