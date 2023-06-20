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
    void solve(TreeNode* root, int targetSum, int &currSum, vector<int> &path, vector<vector<int>> &ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            currSum += root->val;
            path.push_back(root->val);
            if(currSum == targetSum)
                ans.push_back(path);
            path.pop_back();
            currSum-= root->val;
            return;
        }

        currSum += root->val;
        path.push_back(root->val);

        solve(root->left, targetSum, currSum, path, ans);
        solve(root->right, targetSum, currSum, path, ans);

        currSum -= root->val;
        path.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int currSum = 0;
        vector<vector<int>> ans;
        vector<int> path;

        solve(root, targetSum, currSum, path, ans);
        return ans;
    }
};