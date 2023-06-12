#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout<<q.front()<<" : front"<<endl;
    cout<<q.size()<<" : size"<<endl;

    q.pop();

    cout<<q.front()<<" : front"<<endl;
    cout<<q.size()<<" : size"<<endl;
}