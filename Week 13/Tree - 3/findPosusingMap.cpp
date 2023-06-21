#include <bits/stdc++.h>
using namespace std;

void createMapping(unordered_map<int, int> &mapping, int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        mapping[arr[i]] = i;
    }
}

int main()
{
    int size = 9;
    int arr[] = {10,20,40,90,100,2,4,6,8};
    unordered_map<int,int> mapping;
    createMapping(mapping, arr, size);
    cout<<mapping[200];
    return 0;
}