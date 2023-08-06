//Coin change

#include <bits/stdc++.h>
using namespace std;

int minToTarget(vector<int> arr, int target, int mini)
{
    if(target==0)
        return 0;

    if(target<0)
        return INT_MAX;

    int mini = INT_MAX;

    for(int i=0; i<arr.size(); i++)
    {
        int ans = minToTarget(arr, target-arr[i], mini);
        if(ans!=INT_MAX)
            mini = min(ans+1,mini);
    }

    if(mini==0 || mini==INT_MAX)
        return -1;

    return mini;
}

int main()
{
    int n;
    cin>>n; 
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int target;
    cin>>target;
    int mini = INT_MAX;
    cout<<minToTarget(arr, target, mini);
}