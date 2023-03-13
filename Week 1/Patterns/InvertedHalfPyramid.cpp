#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int row = 0; row<n; row++)
    {
        for(int col=n-row-1; col>=0; col--)
            cout<<"* ";
        cout<<endl;
    }
    return 0;
}