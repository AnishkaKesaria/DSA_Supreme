#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n<2)
        return 0;

    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            cout<<n<<" is Not Prime"<<endl;
            return 0;
        }
    }
    cout<<n<<" is Prime"<<endl;
    return 1;
}

int main()
{
    // int n;
    // cin>>n;
    for(int i=0; i<=100; i++)
        isPrime(i);
    return 0;
}