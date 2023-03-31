#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a{1,2,3,4,6,8};
    vector<int> b{3,4,10};

    vector<int> ans;

    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<b.size(); j++)
        {
            if(a[i]==b[j])
                ans.push_back(a[i]);
        }
    }

    //for auto valu belongs to ans
    for(auto value: ans)
    {
        cout<<value<<" ";
    }
}