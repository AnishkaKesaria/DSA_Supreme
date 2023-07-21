#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Min Heap
    priority_queue<int,vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(7);
    pq.push(8);
    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Size: "<<pq.size()<<endl;
    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
    return 0;
}