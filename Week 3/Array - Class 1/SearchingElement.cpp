//Linear Search

#include <bits/stdc++.h>
using namespace std;

void find(int* arr, int target, int n)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]==target)
        {
            cout<<"Element found!"<<endl;
            return;
        }
    }
    cout<<"Element not found!"<<endl;
    return;
}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int target;
    cin>>target;
    find(arr,target,n);
    return 0;
}
