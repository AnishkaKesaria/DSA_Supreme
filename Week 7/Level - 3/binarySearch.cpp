#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int key, int start, int end)
{
    if(start>end)
        return -1;

    int mid = start + (end-start)/2;
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        return binarySearch(arr, key, start, mid-1);
    else
        return binarySearch(arr, key, mid+1, end);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int key;
    cin>>key;
    cout<<binarySearch(arr,key,0,n-1);
    return 0;
}