#include <bits/stdc++.h>
using namespace std;


int MOD = 1000000007;

int numRollsTab(int n, int k, int target)
    {
        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
        dp[0][0] = 1;

        for(int index=1; index<=n; index++)
        {
            for(int t=1; t<=target; t++)
            {
                long long int ans = 0;
                for(int i=1; i<=k; i++)
                {
                    if(t-i>=0)
                        ans += dp[index-1][t-i];
                }
                dp[index][t] = ans%MOD;
            }
        }

        return dp[n][target];
    }