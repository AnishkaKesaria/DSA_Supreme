//Circular Tower

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0;
    int start = 0;

    int balance = 0;

    for(int i=0; i<gas.size(); i++)
    {

        if(balance+gas[i]>=cost[i])
        {
            balance = balance + gas[i] - cost[i];
        }
        else
        {
            deficit = balance + gas[i] - cost[i] + deficit;
            balance = 0;
            start = i+1;
        }
    }

    if(balance+deficit>=0)
        return start;
    else
        return -1;
}


int main()
{
    int n;
    cin>>n;

    vector<int> gas;
    vector<int> cost;

    for(int i=0; i<n; i++)
        cin>>gas[i];
        
    for(int i=0; i<n; i++)
        cin>>cost[i];

    cout<<solve(gas, cost);
    return 0;
}