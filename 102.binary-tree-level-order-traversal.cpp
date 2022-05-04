/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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

// Review: 1

class Solution
{
public:
    // Solution 1: BFS iteration
    // vector<vector<int>> levelOrder(TreeNode *root)
    // {
    //     if(!root)
    //         return {};
    //     vector<vector<int>> result;
    //     vector<int> currentLevel;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         for(int i = q.size(); i > 0; --i){
    //             TreeNode* current = q.front();
    //             q.pop();
    //             currentLevel.push_back(current->val);
    //             if(current->left)
    //                 q.push(current->left);
    //             if(current->right)
    //                 q.push(current->right);
    //         }
    //         result.push_back(currentLevel);
    //         currentLevel.clear();
    //     }
    //     return result;
    // }

    // Solution 2: BFS recursive
    vector<vector<int>> levelOrder(TreeNode *root){
        vector<vector<int>> result;
        bfs(root, 0, result);
        return result;
    }

private:
    void bfs(TreeNode *root, int level, vector<vector<int>>& result){
        if(!root)
            return;
        if(level >= result.size()){
            while(level >= result.size())
                result.push_back({});
        }
        result[level].push_back(root->val);
        bfs(root->left, level + 1, result);
        bfs(root->right, level + 1, result);
    }
};
// @lc code=end
