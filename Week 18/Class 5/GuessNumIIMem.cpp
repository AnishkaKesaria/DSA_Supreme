#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingMem(int start, int end, vector<vector<int>> &dp)
    {
        if(start>=end)
            return 0;

        if(dp[start][end]!=INT_MIN)
            return dp[start][end];

        int ans = INT_MAX;

        for(int i=start; i<=end; i++)
        {
            ans = min(ans, i + max(solveUsingMem(start, i-1, dp), solveUsingMem(i+1, end, dp)));
        }

        dp[start][end] = ans;
        return dp[start][end];
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        vector<vector<int>> dp (n+1, vector<int> (n+1, INT_MIN));
        int ans = solveUsingMem(start, end, dp);
        return ans;
    }
};