#include <bits/stdc++.h>
using namespace std;

int findMid(stack<int> &s, int &totalsize)
{

    if(s.size()==0)
    {
        cout<<"No element in stack";
        return 0;
    }

    int size = s.size();

    if(totalsize%2==0 && totalsize/2==size)
        return s.top();
    if(totalsize%2!=0 && (totalsize/2 + 1)==size)
        return s.top();

    int temp = s.top();
    s.pop();
    int mid = findMid(s, totalsize);
    s.push(temp);
    return mid;
}

int main()
{
    stack<int> s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // s.push(60);
    // s.push(70);
    int totalsize = s.size();
    int mid = findMid(s, totalsize);
    cout<<"Middle element is: "<<mid;
    return 0;
}