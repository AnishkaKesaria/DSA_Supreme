#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_front(10);
    dq.push_back(15);
    dq.push_front(20);
    while(!dq.empty())
    {
        cout<<dq.back()<<" ";
        dq.pop_back();
    }
    return 0;
}