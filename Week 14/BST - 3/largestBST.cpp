#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data)
{
    if(root==NULL)
    {
        root = new Node(data);
        return root;
    }

    if(root->data>data)
        root->left = insertIntoBST(root->left, data);
    else
        root->right = insertIntoBST(root->right, data);
    
    return root;
}

void takeInput(Node* root)
{
   int data;
   cin>>data;

   while(data!=-1)
   {
        root = insertIntoBST(root, data);
        cin>>data;
   } 
   return;
}

class NodeData
{
    public:
    int size;
    int minVal;
    int maxVal;
    bool isValid;

    NodeData(int size, int max, int min, bool validity)
    {
        this->size = size;
        maxVal = max;
        minVal = min;
        isValid = validity;
    }
};


NodeData* largestBST(Node* root, int &ans)
{
    if(root==NULL)
    {
        Node* newNode = new NodeData(0,INT_MAX, INT_MIN, true);
        return newNode;
    }

    NodeData* left = largestBST(root->left, ans);
    NodeData* right = largestBST(root->right, ans);

    int currsize = left->size + right->size + 1;
    int currmax = max(root->data, right->maxVal);
    int currmin = min(root->data, left->minVal);
    bool currvalid;

    if(left->isValid && right->isValid && root->data > left->maxVal && root->data < right->minVal)
        currvalid = true;
    else
        currvalid = false;

    Node* currNode = new NodeData(currsize, currmin, currmax, currvalid);

    if(currvalid==true)
        ans = max(ans, currsize);
    
    return currNode;
}

int largestBST(Node* root) 
{
    int ans = 0;
    Node* newNode = NULL;
    newNode = largestBST(root, ans);
    return ans;
    // Write your code here.
}


int main()
{
    Node* root = NULL;
    takeInput(root);
}