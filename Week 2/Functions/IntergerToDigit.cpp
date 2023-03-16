#include <bits/stdc++.h>
using namespace std;

void DigitsOf(int n)
{
    stack<int> digits;
    while(n>0)
    {
        digits.push(n%10);
        n /=10;
    }
    while(!digits.empty())
    {
        cout<<digits.top()<<endl;;
        digits.pop();
    }
}

int main()
{
    int n;
    cin>>n;
    DigitsOf(n);
    return 0;
}