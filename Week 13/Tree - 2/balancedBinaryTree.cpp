#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode* root)
{
    if(root == NULL)
        return 0;
    int ans = max(height(root->left), height(root->right)) + 1;
    return ans;
}

bool isBalanced(TreeNode* root) {

    if(root==NULL)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diff = abs(rightHeight - leftHeight);

    bool ans1 = (diff<=1);

    bool leftTree = isBalanced(root->left);
    bool rightTree = isBalanced(root->right);

    if(ans1 && leftTree && rightTree)
        return true;
    else
        return false;
    
}

int main()
{
    return 0;
}