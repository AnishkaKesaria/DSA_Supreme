#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> &nums, int target, int currIndex)
    {
        cout<<target<<endl;
        if(currIndex>=nums.size())
            return false;
        if(target==0)
            return true;
        if(target<0)
            return false;

        //include
        bool include = isSubsetSum(nums, target-nums[currIndex], currIndex + 1);

        //exclude
        bool exclude = isSubsetSum(nums, target, currIndex + 1);

        return (include||exclude);
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
        return isSubsetSum(nums, target, currIndex);
    }