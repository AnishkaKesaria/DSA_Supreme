#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveUsingRec(int start, int end)
    {
        if(start>=end)
            return 0;

        int ans = INT_MAX;

        for(int i=start; i<=end; i++)
        {
            ans = min(ans, i + max(solveUsingRec(start, i-1), solveUsingRec(i+1, end)));
        }

        return ans;
    }

    int getMoneyAmount(int n) {
        int start = 1;
        int end = n;
        int ans = solveUsingRec(start, end);
        return ans;
    }
};