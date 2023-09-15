#include <bits/stdc++.h>
using namespace std;

bool isSubsetSumSOO(vector<int> &nums, int target)
{
    int n = nums.size();
    // vector<int> curr(target+1, 0);
    vector<int> next(target+1, 0);
    next[0] = 1;
    
    for(int index = n-1; index>=0; index--)
    {
        for(int currTarget = target; currTarget>=0; currTarget--)
        {
            bool include = 0;
            if(currTarget-nums[index]>=0)
                include = next[currTarget-nums[index]];
            bool exclude = next[currTarget];
            next[currTarget] = (include||exclude);
        }
    }
    return next[target];
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
        sum+=nums[i];
    if(sum&1==1)
        return false;
    int target = sum/2;
    // int currIndex = 0;
    // vector<vector<int>> dp(target+1, vector<int> (nums.size(), -1));
    // return isSubsetSumMem(nums, target);
    return isSubsetSumSOO(nums, target);
}