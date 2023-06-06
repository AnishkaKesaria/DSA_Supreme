#include <bits/stdc++.h>
using namespace std;

void prevSmallerElement(vector<int> &v)
{
    vector<int> ans(v.size(), 0);
    stack<int> s;
    s.push(-1);

    for(int i=0; i<v.size(); i++)
    {
        while(s.top()>=v[i])
            s.pop();
        ans[i] = s.top();
        s.push(v[i]);
    }

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    prevSmallerElement(v);
    return 0;
}