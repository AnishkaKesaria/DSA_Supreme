#include <bits/stdc++.h>
using namespace std;

long long countWaysTab(int n, int k)
    {
        long long mod = 1000000007;
        vector<long long> dp(n+1, -1);
        dp[1] = k;
        dp[2] = k + (k*(k-1));
        
        for(int i=3; i<=n; i++)
        {
            dp[i] = ((dp[i-1] + dp[i-2]) * (k-1)) % mod;
        }
        
        return dp[n];
    }