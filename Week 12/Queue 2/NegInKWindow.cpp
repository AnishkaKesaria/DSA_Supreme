// First -ve integer in k sized window

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr, int n, int k)
{
    vector<int> result;
    deque<int> q;
    for(int i=0; i<k; i++)
    {
        if(arr[i]<0)
            q.push_back(i);
    }

    // if(!q.empty())
    //     result.push_back(arr[q.front()]);
    // else
    //     result.push_back(0);

    // for(int i=k; i<n-1; i++)
    // {
    //     while(i-q.front()>=k)
    //         q.pop_front();
    //     if(arr[i]<0)
    //         q.push_back(i);

    //     if(!q.empty())
    //         result.push_back(arr[q.front()]);
    //     else
    //         result.push_back(0);
    // }

    for(int i=k; i<n-1; i++)
    {
        if(!q.empty())
            result.push_back(arr[q.front()]);
        else
            result.push_back(0);

        while((i-q.front()>=k) && (!q.empty()))
            q.pop_front();
        if(arr[i]<0)
            q.push_back(i);
    }

    if(q.empty())
        result.push_back(0);
    else
        result.push_back(arr[q.front()]);

    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int k;
    cin>>k;

    vector<int> ans;
    ans = solve(arr, n, k);

    cout<<"Result is: "<<endl;

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    
    return 0;
}