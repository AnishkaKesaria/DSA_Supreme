#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int count = 0;
        int maxcount = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                st.pop();
                if(!st.empty())
                {
                    count = i - (st.top());
                    maxcount = max(count, maxcount);
                }
                else
                    st.push(i);
            }
        }
        return maxcount;
    }
};