#include <bits/stdc++.h>
using namespace std;

class info
{
    public:
    int val;
    int row;
    int col;

    info(int val, int row, int col)
    {
        this->val = val;
        this->row = row;
        this->col = col;
    }
};

class compare
{
    public:
    bool operator()(info* a, info* b)
    {
        return (a->val>b->val);
    }
};


vector<int> mergeKSortedArrays(int arr[][4], int k, int n)
{
    priority_queue<info*, vector<info*>, compare> minHeap;

    for(int i=0; i<k; i++)
    {
        info* temp = new info(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;
    while(!minHeap.empty())
    {
        info* temp = minHeap.top();
        int topElement = temp->val;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();

        ans.push_back(topElement);
        if(topCol+1<n)
        {
            info* newInfo = new info(arr[topRow][topCol+1], topRow, topCol+1);
            minHeap.push(newInfo);
        }
    }
    return ans;
}

int main()
{
    int arr[][4] = {{2,4,6,8}, {1,3,5,7}, {8,9,10,11}};
    int k = 3;
    int n = 4;
    vector<int> ans = mergeKSortedArrays(arr, k, n);
    cout<<"Printing:";
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}