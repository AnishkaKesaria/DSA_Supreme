#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> &arr)
{
    vector<int> ans(arr.size(), 0);
    stack<int> s;
    s.push(-1);

    for(int i=arr.size()-1; i>=0; i--)
    {
        while(s.top()!= -1 && arr[s.top()]>=arr[i])
            s.pop();
        ans[i] = s.top();
        if(ans[i]==-1)
            ans[i] = arr.size();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int> &arr)
{
    vector<int> ans(arr.size(), 0);
    stack<int> s;
    s.push(-1);

    for(int i=0; i<arr.size(); i++)
    {
        while(s.top()!=-1 && arr[s.top()]>=arr[i])
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestArea(vector<int> &arr)
{
    vector<int> next = nextSmaller(arr);
    vector<int> prev = prevSmaller(arr);

    int maxarea = 0;

    for(int i=0; i<arr.size(); i++)
    {
        int l = arr[i];
        int w = next[i] - prev[i] - 1;
        int area = l*w;
        maxarea = max(area, maxarea);
    }

    return maxarea;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);
    cout<<largestArea(v);
    return 0;
}