#include <bits/stdc++.h>
using namespace std;

int coinChangeTab(vector<int> &coins, int amount)
{
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<=amount; i++)
    {
        int ans = INT_MAX;
        for(int j=0; j<coins.size(); j++)
        {
            int tempAns = dp[i-coins[j]];
            if(tempAns!=INT_MAX)
                ans = min(ans, tempAns);
        }
        dp[i] = ans;
    }
    return dp[amount];
}

int coinChange(vector<int>& coins, int amount)
{
    int ans = coinChangeTab(coins, amount);
    if(ans==INT_MAX)
        return -1;
    return ans;
}