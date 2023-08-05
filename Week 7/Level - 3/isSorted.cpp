#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &arr, int i)
{
    if(i>=arr.size()-1)
        return true;
    
    if(arr[i]<=arr[i+1])
        return isSorted(arr, i+1);
    else
        return false;

}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<isSorted(arr, 0);
    return 0;
}