#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pIndex = s;
    int pivot = arr[pIndex];

    int count = 0;
    for(int i=s+1; i<=e; i++) //diff
    {
        if(arr[i]<=pivot)
            count++;
    }
    int rightIndex = count+s;
    swap(arr[rightIndex],arr[pIndex]);
    pIndex = rightIndex;

    int i=s; int j = e;
    while(i<rightIndex && j>rightIndex)
    {
        while(arr[i]<=pivot)
            i++;
        
        while(arr[j]>pivot)
            j--;
        
        if(i<rightIndex && j>rightIndex)
            swap(arr[i++],arr[j--]);
    }

    return rightIndex;

}

void quickSort(int arr[], int s, int e)
{

    if(s>=e)
        return;

    int index = partition(arr,s,e);

    quickSort(arr,s,index-1);
    quickSort(arr,index+1,e);
}

int main()
{
    int arr[] = {1,3,7,2,0};
    int n = 5;
    quickSort(arr,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}