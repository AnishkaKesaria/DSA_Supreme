#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int sum, int &maxi, int i)
{
    if(i>=arr.size())
    {
        maxi = max(maxi,sum);
        return;
    }

    //include
    solve(arr,sum+arr[i],maxi,i+2);

    //exclude
    solve(arr,sum,maxi,i+1);
}

int main()
{
    vector<int> arr = {2,1,4,9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;
    solve(arr, sum, maxi, i);
    cout<<maxi;
    return 0;
}