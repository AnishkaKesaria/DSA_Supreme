#include <bits/stdc++.h>
using namespace std;

void printExtreme(int* arr, int n)
{
    int start = 0;
    int end = n-1;
    while(start<end)
    {
        cout<<arr[start++]<<" ";
        cout<<arr[end--]<<" ";
    }
    if(start==end)
        cout<<arr[start++];
    return;
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    printExtreme(arr,n);
    return 0;
}