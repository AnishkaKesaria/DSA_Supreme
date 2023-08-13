#include <bits/stdc++.h>
using namespace std;

class Solution {
public:    
    int solveUsingTab(vector<int>&nums, int n)
    {
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        
        for(int i=1; i<=n; i++)
        {
            int temp = 0;
            if(i-2>=0)
                temp = dp[i-2];
            int include = temp + nums[i];
            int exclude = dp[i-1];
            
            dp[i] = max(include, exclude);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        int ans = solveUsingTab(nums,n);
        return ans;
    }
};