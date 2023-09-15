#include <bits/stdc++.h>
using namespace std;    
    
    bool isSubsetSumDP(vector<int> &nums, int target, int currIndex, vector<vector<int>> &dp)
    {
        if(currIndex>=nums.size())
            return false;
        if(target==0)
            return true;
        if(target<0)
            return false;

        if(dp[target][currIndex]!=-1)
            return dp[target][currIndex];

        bool include = isSubsetSumDP(nums, target-nums[currIndex], currIndex+1, dp);
        bool exclude = isSubsetSumDP(nums, target, currIndex+1, dp);

        dp[target][currIndex] = include||exclude;
        return dp[target][currIndex];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        int target = sum/2;
        int currIndex = 0;
        vector<vector<int>> dp(target+1, vector<int> (nums.size(), -1));
        return isSubsetSumDP(nums, target, currIndex, dp);
    }