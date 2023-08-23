#include <bits/stdc++.h>
using namespace std;

//index - index of last element
int solveUsingRecursion(int weight[], int val[], int index, int capacity)
{
    //base case - only 1 iteam
    if(index==0)
    {
        if(weight[0]<=capacity)
            return val[0];
        else
            return 0;
    }

    //include
    int include = 0;
    if(weight[index]<=capacity)
        include = val[index] + solveUsingRecursion(weight, val, index-1, capacity-weight[index]);

    //exclude
    int exclude = solveUsingRecursion(weight, val, index-1, capacity);

    return max(include,exclude);
}

int solveUsingMem(int weight[], int val[], int index, int capacity, vector<vector<int>> &dp)
{
    //base case - only 1 iteam
    if(index==0)
    {
        if(weight[0]<=capacity)
            return val[0];
        else
            return 0;
    }

    if(dp[index][capacity]!=-1)
        return dp[index][capacity];

    //include
    int include = 0;
    if(weight[index]<=capacity)
        include = val[index] + solveUsingMem(weight, val, index-1, capacity-weight[index], dp);

    //exclude
    int exclude = solveUsingMem(weight, val, index-1, capacity, dp);

    int ans = max(include,exclude);
    dp[index][capacity] = ans;

    return dp[index][capacity];
}

int main()
{
    int weight[] = {10, 5, 9, 25};
    int val[] = {3, 7, 2, 10};
    int n = 4;
    int capacity = 20;

    // int ans = solveUsingRecursion(weight, val, n-1, capacity);

    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    int ans = solveUsingMem(weight, val, n-1, capacity, dp);

    cout<<ans<<endl;
    return 0;
}