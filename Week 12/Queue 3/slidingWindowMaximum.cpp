#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;


        for(int i=0; i<k; i++)
        {
            while((!q.empty()) && (nums[q.back()]<=nums[i]))
                q.pop_back();
            q.push_back(i);
        }

        ans.push_back(nums[q.front()]);


        for(int i=k; i<nums.size(); i++)
        {
            while((!q.empty()) && (nums[q.back()]<=nums[i]))
                q.pop_back();
            q.push_back(i);

            if(i-q.front()>=k && !q.empty())
                q.pop_front();

            ans.push_back(nums[q.front()]);
        }

        // int maxnum = nums[0];
        // q.push_back(0);

        // for(int i=1; i<k; i++)
        // {
        //     q.push_back(i);
        //     if(nums[i]>=maxnum)
        //     {
        //         while(q.front()<i)
        //             q.pop_front();
        //         //q.pop_front();
        //         maxnum = nums[i];
        //     }
        // }

        // for(int i=k; i<nums.size(); i++)
        // {
        //     ans.push_back(nums[q.front()]);
        //     q.push_back(i);

        //     if(i-q.front()>=k)
        //     {
        //         q.pop_front();
        //         maxnum = q.front();
        //     }

        //     if(nums[i]>=maxnum)
        //     {
        //         while(q.front()<i)
        //             q.pop_front();
        //         maxnum = nums[i];
        //         // q.pop_front();
        //         // maxnum = nums[i];
        //         // q.push_back(i);
        //     }

            
        // }

        // ans.push_back(nums[q.front()]);
        return ans;
    }
};