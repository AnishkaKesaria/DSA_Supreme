#include <bits/stdc++.h>
using namespace std;

void reverseK(queue<int> &q, int k)
{
    stack<int> s;
    int n = q.size();

    if(k>=n || k<0)
        return;

    for(int i=0; i<k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    for(int i = 0; i<q.size()-k; i++)
    {
        q.push(q.front());
        q.pop();
    }
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
    int k;
    cin>>k;

    // stack<int> s;

    // for(int i=0; i<k; i++)
    // {
    //     s.push(q.front());
    //     q.pop();
    // }

    // while(!s.empty())
    // {
    //     q.push(s.top());
    //     s.pop();
    // }

    // for(int i = 0; i<q.size()-k; i++)
    // {
    //     q.push(q.front());
    //     q.pop();
    // }

    reverseK(q,k);

    cout<<"Reversed Queue:"<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}