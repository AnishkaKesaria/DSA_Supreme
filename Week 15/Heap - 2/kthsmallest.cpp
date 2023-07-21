#include <bits/stdc++.h>
using namespace std;


int kthsmallest(vector<int> arr, int k)
{
    priority_queue<int> pq;
    for(int i=0; i<arr.size(); i++)
    {
        if(i<k)
            pq.push(arr[i]);
        else
        {
            if(arr[i]<pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }
    return pq.top();
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
    {
        int element;
        cin>>element;
        arr[i] = element;
    }
    int k;
    cin>>k;
    cout<<"kth smallest: "<<kthsmallest(arr, k);
    return 0;
}