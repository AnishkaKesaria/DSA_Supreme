#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr {0,1,1,0,0,0,0,1,1,1,1,1,0,1,0,1};
    int start = 0;
    int end = arr.size() - 1;
    while(start<=end)
    {
        if(arr[start]>arr[end])
        {
            swap(arr[start],arr[end]);
            end--;
        }
        start++;
    }
    for(auto i: arr)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}