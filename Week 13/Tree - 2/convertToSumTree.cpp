#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int convertToSumTree(TreeNode* root)
{
    if(root==NULL)
        return 0;

    root->left->val = convertToSumTree(root->left);
    root->right->val = convertToSumTree(root->right);
    //int currNode = root->val;

    int newVal = root->left->val + root->right->val + root->val;

    return newVal;
}

void toSumTree(TreeNode* root)
{
    root->val = convertToSumTree(root);
}

int main()
{
    return 0;
}