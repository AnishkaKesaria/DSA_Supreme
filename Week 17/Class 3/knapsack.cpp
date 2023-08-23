#include <bits/stdc++.h>
using namespace std;

//index - index of last element
int solveUsingRecursion(int weight[], int val[], int index, int capacity)
{
    //base case - only 1 iteam
    if(index==0)
    {
        if(weight[0]<=capacity)
            return val[0];
        else
            return 0;
    }

    //include
    int include = 0;
    if(weight[index]<=capacity)
        include = val[index] + solveUsingRecursion(weight, val, index-1, capacity-weight[index]);

    //exclude
    int exclude = solveUsingRecursion(weight, val, index-1, capacity);

    return max(include,exclude);
}

int main()
{
    int weight[] = {4,5,1};
    int val[] = {1,2,3};
    int n = 3;
    int capacity = 4;

    int ans = solveUsingRecursion(weight, val, n-1, capacity);

    cout<<ans<<endl;
    return 0;
}