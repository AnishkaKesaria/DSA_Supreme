#include <bits/stdc++.h>
using namespace std;

int main()
{
    //Max Heap
    priority_queue<int> pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Size: "<<pq.size()<<endl;
    cout<<pq.empty()<<endl;
    cout<<"Top: "<<pq.top()<<endl;
    return 0;
}