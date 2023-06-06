#include <bits/stdc++.h>
using namespace std;

void nextSmallerElement(vector<int> arr)
{
    int n = arr.size();
    stack<int> s;
    vector<int> result(n,0);
    s.push(-1);
    for(int i=arr.size()-1; i>=0; i--)
    {
        while(s.top()>=arr[i])
        {
            s.pop();
        }
        result[i] = s.top();
        s.push(arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        cout<<result[i]<<" ";
    }
    return;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    nextSmallerElement(v);
    return 0;
}