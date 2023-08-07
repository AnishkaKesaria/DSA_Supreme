#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e-s)/2;
    
    int len1 = mid-s + 1;
    int len2 = e-mid;

    //Dynamically creating array
    int* left = new int[len1];
    int* right = new int[len2];

    //copying values
    int k = s;
    for(int i=0; i<len1; i++)
    {
        left[i] = arr[k];
        k++;
    }
    
    k=mid+1;
    for(int j=0; j<len2; j++)
    {
        right[j] = arr[k];
        k++;
    }

    //merge logic
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;
    while(leftIndex<len1 && rightIndex<len2)
    {
        if(left[leftIndex]<right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex++];
            mainArrayIndex++;
        }
        else
        {
            arr[mainArrayIndex] = right[rightIndex++];
            mainArrayIndex++;
        }

    }

    while(leftIndex<len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    while (rightIndex<len2)
    {
        arr[mainArrayIndex] = right[rightIndex++];
    }
    
    //TODO: Delete left 
    delete[] left;
    delete[] right;
}

void mergeSort(int* arr, int s, int e)
{
    //base case
    //s==e -> single element
    //s>e -> invalid array

    if(s>=e)
        return;
    
    int mid = s + (e-s)/2;

    //left part sort krdo recursion
    mergeSort(arr,s,mid);

    //right part sort
    mergeSort(arr,mid+1,e);

    //merge two sorted array
    merge(arr, s, e);
}

int main()
{
    int arr[] = {4,5,13,2,12};
    int n = 5;

    int s = 0;
    int e = n-1;
    mergeSort(arr,s,e);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}