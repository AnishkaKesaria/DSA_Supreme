#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    //choose pivot element
    int pIndex = s;
    int pivot = arr[s];

    //placing pivot at right position
    //count elements lesser than pivot
    int count = 0;
    for(int i=s; i<=e; i++)
    {
        if(arr[i]<pivot)
            count++;
    }
    swap(arr[pIndex],arr[count+1]);
    pIndex = count+1;

    //left me chote, right me bade
    int i=s;
    int j=e;
    while(i<pIndex && j>pIndex)
    {
        while(arr[i]<=pivot)
            i++;
        
        while(arr[j]>pivot)
            j--;

        //2 possible cases
        if(i<pIndex && j>pIndex)
        {
            swap(arr[i],arr[j]);
        }
    }
    return pIndex;
}

void quickSort(int arr[], int s, int e)
{
    //base case
    if(s>=e)
        return;
    
    //partition logic
    int index = partition(arr,s,e);

    //recursive call
    quickSort(arr,s,index-1);
    quickSort(arr,index+1,e);
    cout<<"Hi";
}

int main()
{
    int arr[] = {8,1,20,30,6,5,60,5};
    int n= 8;
    int s =0;
    int e = n-1;
    cout<<"Hi";
    quickSort(arr,s,e);
    cout<<"Hi";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}