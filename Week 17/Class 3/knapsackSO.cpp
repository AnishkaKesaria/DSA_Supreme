//Space Optimised - Previous - O(n*m) - Now - O(m) + O(m)

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

int solveUsingTab(int weight[], int val[], int index, int capacity)
{
    vector<vector<int>> dp(index, vector<int> (capacity+1, 0));
    for(int w=weight[0]; w<=capacity; w++)
    {
        if(weight[0]<=capacity)
            dp[0][w] = val[0];
        else
            dp[0][w] = 0;
    }

    for(int i=1; i<index; i++)
    {
        for(int wt=0; wt<=capacity; wt++)
        {
            //include
            int include = 0;
            if(weight[i]<=wt)
                include = val[i] + dp[i-1][wt-weight[i]];
            //exclude
            int exclude = dp[i-1][wt];
            int ans = max(include, exclude);
            dp[i][wt] = ans;
        }
    }

    return dp[index-1][capacity];
}

int solveUsingSO(int weight[], int val[], int n, int capacity)
{
    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    for(int w=weight[0]; w<=capacity; w++)
    {
        if(weight[0]<=capacity)
            prev[w] = val[0];
        else
            prev[w] = 0;
    }

    for(int i=1; i<n; i++)
    {
        for(int w=0; w<=capacity; w++)
        {
            int include = 0;
            if(weight[i]<=w)
                include = val[i] + prev[w-weight[i]];
            int exclude = prev[w];
            curr[w] = max(include, exclude);    
        }
        //Yaha galti karungi, inner loop me neeche wala expression daal dungi
        prev = curr;
    }

    return prev[capacity];
}

// int solveUsingSOO(int weight[], int val[], int n, int capacity)
// {
//     vector<int> prev(capacity+1, 0);
//     // vector<int> curr(capacity+1, 0);

//     for(int w=weight[0]; w<=capacity; w++)
//     {
//         if(weight[0]<=capacity)
//             prev[w] = val[0];
//         else
//             prev[w] = 0;
//     }

//     int ans = prev[0];

//     for(int i=1; i<n; i++)
//     {
//         for(int w=0; w<=capacity; w++)
//         {
//             int include = 0;
//             if(weight[i]<=w)
//                 include = val[i] + prev[w-weight[i]];
//             int exclude = prev[w];
//             ans = max(include, exclude);    
//         }
//         //Yaha galti karungi, inner loop me neeche wala expression daal dungi
//     }

//     return ans;
// }


int solveUsingSO2(int weight[], int val[], int n, int capacity)
{
    vector<int> curr(capacity+1, 0);

    for(int w=weight[0]; w<=capacity; w++)
    {
        if(weight[0]<=capacity)
            curr[w] = val[0];
        else
            curr[w] = 0;
    }

    for(int i=1; i<n; i++)
    {
        for(int wt=capacity; wt>=0; wt--)
        {
            int include = 0;
            if(weight[i]<=wt)
                include = val[i] + curr[wt-weight[i]];
            int exclude = curr[wt];
            curr[wt] = max(include,exclude);
        }
    }

    return curr[capacity];
}

int main()
{
    int weight[] = {10, 5, 9, 25};
    int val[] = {3, 7, 2, 10};
    int n = 4;
    int capacity = 20;

    // int ans = solveUsingRecursion(weight, val, n-1, capacity);

    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    // int ans = solveUsingMem(weight, val, n-1, capacity, dp);
    // int ans = solveUsingTab(weight, val, n, capacity);
    int ans = solveUsingSO2(weight, val, n, capacity);

    cout<<ans<<endl;
    return 0;
}