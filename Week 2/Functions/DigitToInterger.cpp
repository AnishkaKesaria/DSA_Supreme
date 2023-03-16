#include <bits/stdc++.h>
using namespace std;

int toInteger(vector<int> digits)
{
    int ans=0;
    for(int i=0; i<digits.size(); i++)
    {
        ans = (ans*10) + digits[i];
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter number of digits: ";
    cin>>n;
    vector<int> digits;
    for(int i=0; i<n; i++)
    {
        int digit;
        cin>>digit;
        digits.push_back(digit);
    }
    int ans = toInteger(digits);
    cout<<ans;
}