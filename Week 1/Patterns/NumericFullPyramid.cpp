#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     int count = 0;
//     for(int row=0; row<n; row++)
//     {
//         count += 1;
//         for(int col=0; col<n+row; col++)
//         {
//             if(col<n-row-1)
//                 cout<<"  ";
//             else if(col<n)
//             {
//                 cout<<count<<" ";
//                 count+=1;
//             }
//             else
//             {
//                 if(col==n)
//                     count-=1;
//                 count-=1;
//                 cout<<count<<" ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }

int main()
{
    int n;
    cin>>n;
    int count = 0;
    for(int row=0; row<n; row++)
    {
        count +=1;
        for(int col=0; col<n+row; col++)
        {
            if(col<n)
            {
                if(col<n-row-1)
                    cout<<"  ";
                else
                {
                    cout<<count<<" ";
                    count += 1;
                }
            }
            //count -=1;
            // if(col==n)
            //     count--;

            if(col>=n)
            {
                count-=1;
                cout<<count-1<<" ";
            }
        }
        count--;
        cout<<endl;
    }
}