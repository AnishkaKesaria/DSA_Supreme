#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;

int numRollsTabSO(int n, int k, int target)
    {
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        
        prev[0]=1;
        
        for(int index=1; index<=n; index++)
        {
            for(int t=1; t<=target; t++)
            {
                long long int ans = 0;
                for(int i=1; i<=k; i++)
                {
                    if(t-i>=0)
                        ans += prev[t-i];
                }
                curr[t] = ans%MOD;
            }
            prev = curr;
        }

        return curr[target];
    }