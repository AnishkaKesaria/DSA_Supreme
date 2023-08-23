#include <bits/stdc++.h>
using namespace std;

long long countWaysMem(int n, int k, vector<long long> &dp){
        // code here
        long long mod = 1000000007;
        
        if(n==1)
            return k;
            
        if(n==2)
            return (k + k*(k-1));
            
        if(dp[n]!=-1)
            return dp[n];
            
        long long ans = ((countWaysMem(n-1,k,dp)+countWaysMem(n-2,k,dp))*(k-1)) % mod;
        dp[n] = ans;
        return dp[n];
    }

long long countWays(int n, int k)
    {
        vector<long long> dp(n+1, -1);
        long long ans = countWaysMem(n, k, dp);
        return ans;
    }