#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int> &q)
{
    int n = q.size();
    int k = n/2;

    queue<int> u;

    for(int i=0; i<k; i++)
    {
        u.push(q.front());
        q.pop();
    }

    while(!u.empty())
    {
        q.push(u.front());
        u.pop();
        q.push(q.front());
        q.pop();
    }

    if(n&1)
    {
        q.push(q.front());
        q.pop();
    }

    return;
}

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
    interleave(q);
    cout<<"Interleaved Queue: "<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}