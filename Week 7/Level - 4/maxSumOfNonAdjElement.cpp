#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> arr, int i, int currSum)
{
    if(i>=arr.size())
        return currSum;

    //include
    int Insum = maxSum(arr, i+2, currSum+arr[i]);
    //exclude
    int ExSum = maxSum(arr, i+1, currSum);
    return max(Insum,ExSum);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<maxSum(arr,0,0);
    return 0;
}