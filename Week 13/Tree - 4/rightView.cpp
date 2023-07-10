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
 
class Solution {
public:
    void rightView(TreeNode* root, int level, vector<int> &ans)
    {
        if(root==NULL)
            return;

        if(ans.size()==level)
            ans.push_back(root->val);

        rightView(root->right, level + 1, ans);
        rightView(root->left, level + 1, ans);
        return;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level = 0;
        rightView(root, level, ans);
        return ans;
    }
};