#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i)
{
    int index = i;
    int leftindex = 2*i;
    int rightindex = 2*i + 1;

    int largest = index;

    if(leftindex<=size && arr[largest]<arr[leftindex])
        largest = leftindex;
    if(rightindex<=size && arr[largest]<arr[rightindex])
        largest = rightindex;

    if(largest!=index)
    {
        swap(arr[largest], arr[index]);
        index = largest;
        heapify(arr, size, index);
    }
    return;
}

void heapSort(int arr[], int size)
{
    while(size!=1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
    return;
}

void buildHeap(int arr[], int n)
{
    for(int i=n/2; i>0; i--)
        heapify(arr, n, i);
}

int main()
{
    int arr[] = {-1,12,56,43,6,78,87,5,44,3,23,32};
    int size = 11;
    buildHeap(arr,size);
    heapSort(arr, size);

    for(int i=1; i<=size; i++)
        cout<<arr[i]<<" ";

    return 0;
}