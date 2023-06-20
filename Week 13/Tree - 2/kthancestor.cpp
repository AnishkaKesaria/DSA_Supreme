#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        this->val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildTree()
{
    int data;
    cout<<"Enter data:";
    cin>>data;

    if(data==-1)
        return NULL;

    //A - create node
    TreeNode* root = new TreeNode(data);

    //B - Left child
    cout<<"Enter left child of "<<data<<":"<<endl;
    root->left = buildTree();

    //C - Right child
    cout<<"Enter right child of "<<data<<":"<<endl;
    root->left = buildTree();
    return root;
}

bool kthAncestor(TreeNode* root, int p, int &k)
{
    if(root==NULL)
        return false;

    if(root->val == p)
        return true;

    bool leftAns = kthAncestor(root->left, p, k);
    bool rightAns = kthAncestor(root->right, p, k);

    if(leftAns || rightAns)
        k--;
    if(k==0)
    {
        cout<<root->val<<endl;
        k = -1;
    }

    return (leftAns||rightAns);
}

int main()
{
    TreeNode* root = NULL;
    root = buildTree();
    int p,k;
    cout<<"Enter p: "<<endl;
    cin>>p;
    cout<<"Enter k: "<<endl;
    cin>>k;
    kthAncestor(root, p, k);
    return 0;
}