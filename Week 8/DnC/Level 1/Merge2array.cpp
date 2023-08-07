#include <bits/stdc++.h>
using namespace std;

void merge(int *left, int *right, int* arr, int len1, int len2, int s)
{
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
}

int main()
{
    int n1, n2;
    cin>>n1>>n2;
    int* arr1 = new int[n1];
    int* arr2 = new int[n2];

    for(int i=0; i<n1; i++)
        cin>>arr1[i];

    for(int i=0; i<n2; i++)
        cin>>arr2[i];

}