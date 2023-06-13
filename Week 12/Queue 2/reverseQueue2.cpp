//Recursion approach

#include <bits/stdc++.h>
using namespace std;


void reverseQueue(queue<int> &q)
{
    if(q.empty())
        return;
    int e = q.front();
    q.pop();
    reverseQueue(q);
    q.push(e);
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
    reverseQueue(q);
    cout<<"Reversed Queue: "<<endl;
    for(int i=0; i<n; i++)
    {
        int f = q.front();
        cout<<f<<" ";
        q.pop();
    }
    return 0;
}