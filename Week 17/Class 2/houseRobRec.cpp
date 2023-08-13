#include <bits/stdc++.h>
using namespace std;

int solveUsingRec(vector<int> &nums, int n)
{
    if(n<0)
        return 0;
    if(n==0)
        return nums[0];

    int include = solveUsingRec(nums,n-2) + nums[n];
    int exclude = solveUsingRec(nums, n-1);

    return max(include, exclude);
}

int rob(vector<int> &nums)
{
    int n = nums.size() -1;
    int ans = solveUsingRec(nums,n);
    return ans;
}