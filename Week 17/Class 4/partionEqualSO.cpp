#include <bits/stdc++.h>
using namespace std;

bool isSubsetSumSO(vector<int> &nums, int target)
{
    vector<int> curr(target+1, 0);
    vector<int> next(target+1, 0);

    next[0] = 1;

    for(int index=nums.size(); index>=0; index--)
    {
        for(int currTarget=1; currTarget<=target; currTarget++)
        {
            bool include = 0;
            if(currTarget-nums[index]>=0)
                include = next[currTarget-nums[index]];
            bool exclude = next[currTarget];

            curr[currTarget] = (include||exclude);
        }
        next = curr;
    }

    return curr[0];
}

bool canPartition(vector<int> &nums)
{
    int target = 0;
    for(int i=0; i<nums.size(); i++)
        target += nums[i];
    if(target&1==1)
        return false;
    return isSubsetSumSO(nums, target);
}