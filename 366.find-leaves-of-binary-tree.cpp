/*
 * @lc app=leetcode id=366 lang=cpp
 *
 * [366] Find Leaves of Binary Tree
 */

// @lc code=start

// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: DFS (post order) + remove leaves
    // ref: https://www.cnblogs.com/grandyang/p/5616158.html
    // vector<vector<int>> findLeaves(TreeNode *root)
    // {
    //     if(!root)
    //         return {};
    //     vector<vector<int>> result;
    //     while(root){
    //         vector<int> current;
    //         root = dfs(root, current);
    //         result.push_back(current);
    //     }
    //     return result;
    // }

    // Solution 2: self-recursion
    // ref: https://www.cnblogs.com/grandyang/p/5616158.html
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        if(!root)
            return {};
        vector<vector<int>> left = findLeaves(root->left);
        vector<vector<int>> right = findLeaves(root->right);
        // assign larger result and append smaller one into larger one
        vector<vector<int>> result = (left.size() >= right.size()) ? left : right;
        vector<vector<int>> another = (left.size() >= right.size()) ? right : left;
        for(int i = 0; i < another.size(); ++i){
            result[i].insert(result[i].begin(), another[i].begin(), another[i].end());
        }
        // add root itself into a new layer
        result.push_back({root->val});
        return result;
    }
private:
    TreeNode* dfs(TreeNode *root, vector<int>& current){
        if(!root)
            return nullptr;
        // push and delete every leaves
        if(!root->left && !root->right){
            current.push_back(root->val);
            //delete root;  // leetcode compiler doesn't support garbage collection, but this is correct
            root = nullptr;
            return root;
        }
        root->left = dfs(root->left, current);
        root->right = dfs(root->right, current);
        return root;
    }
};

// @lc code=end