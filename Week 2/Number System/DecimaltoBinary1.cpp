//Division Method

#include <bits/stdc++.h>
using namespace std;

/*int main()
{
    int n;
    cin>>n;
    int sum=0,i=0;
    while(n>0)
    {
        int bit = n%2;
        cout<<sum<<endl;
        // cout<<(pow(10,2));
        cout<<pow(10,i);
        sum = (pow(10,i)*bit) + sum;
        cout<<sum<<endl;
        i++;
        n /= 2;
    }
    cout<<sum<<endl;
    return 0;
}*/

int main()
{
    int n;
    cin>>n;
    int sum = 0, i=0;
    while(n>0)
    {
        int bit = n%2;
        cout<<bit<<endl;
        cout<<sum<<" :before"<<endl;
        cout<<(pow(10,i)*bit) + sum<<endl;
        sum += (pow(10,i)*bit);
        cout<<sum<<" :after"<<endl;
        i++;
        n = n/2;
    }
    cout<<sum<<endl;
    return 0;
}