#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    if(amount==0)
        return 0;
    if(amount<0)
        return INT_MAX;

    int ans = INT_MAX;
    for(int i=0; i<coins.size(); i++)
    {
        int tempAns = coinChange(coins, amount-coins[i]);
        if(tempAns!=INT_MAX)
            ans = min(ans, tempAns+1);
    }

    if(ans==INT_MAX || ans==0)
        return -1;

    return ans;
}