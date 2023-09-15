#include <bits/stdc++.h>
using namespace std;



    bool isSubsetSumMem(vector<int> &nums, int target)
    {
        vector<vector<int>> dp(nums.size()+1, vector<int> (target+1, 0));
        for(int i=0; i<nums.size(); i++)
        {
            dp[i][0] = 1;
        }

        for(int index = nums.size()-1; index>=0; index--)
        {
            for(int currTarget = 1; currTarget<=target; currTarget++)
            {
                bool include = 0;
                if(currTarget-nums[index]>=0)
                    include = dp[index+1][currTarget-nums[index]];
                bool exclude = dp[index+1][currTarget];

                dp[index][currTarget] = include||exclude;
            }
        }

        return dp[0][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        int target = sum/2;
        int currIndex = 0;
        // vector<vector<int>> dp(target+1, vector<int> (nums.size(), -1));
        return isSubsetSumMem(nums, target);
    }