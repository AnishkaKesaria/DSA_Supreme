#include <bits/stdc++.h>
using namespace std;

class Heap{
    public: 
    int arr[101];
    int size;

    Heap()
    {
        size = 0;
    }

    void insert(int val)
    {

        //insert at end
        size = size+1;
        int index = size;
        arr[index] = val;

        //move to right position
        while(index>1)
        {
            int parentIndex = index/2;
            if(arr[index]>arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
                break;
        }

    }
    
};

int main()
{
    Heap h;
    // h.arr[0] = -1;
    // h.arr[1] = 100;
    // h.arr[2] = 50;
    // h.arr[3] = 60;
    // h.arr[4] = 40;
    // h.arr[5] = 45;
    // h.size = 5;
    // cout<<"printing heap"<<endl;
    // for(int i=1; i<=h.size; i++)
    //     cout<<h.arr[i]<<" ";
    // cout<<endl;
    // h.insert(110);
    // cout<<"printing heap"<<endl;
    // for(int i=1; i<=h.size; i++)
    //     cout<<h.arr[i]<<" ";
    // cout<<endl;

    h.size = 0;
    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);

    for(int i=1; i<=h.size; i++)
        cout<<h.arr[i]<<" ";
    return 0;
}