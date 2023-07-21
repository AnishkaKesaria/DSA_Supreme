#include <bits/stdc++.h>
using namespace std;

class Heap
{
    public:
    int arr[101];
    int size;

    Heap()
    {
        size = 0;
    }

    void delete()
    {
        //replace root with last
        arr[1] = arr[size];
        size--;
        //place at right position
        int index = 1;
        while(index<size)
        {
            int left = 2*index;
            int right = 2*index +1;

            if(left<size && arr[largest]<arr[left])
                largest = left;
            if(right<size && arr[largest]<arr[right])
                largest = right;
            
            if(largest==index)
                return;
            else
            {
                swap(arr[largest], arr[index]);
                index = largest;
            }            
        }
        return;
    }
};