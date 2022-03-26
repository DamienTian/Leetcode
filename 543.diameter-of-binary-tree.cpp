/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
//#include "dummyHead.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Solution: DFS
//  ref: https://www.cnblogs.com/grandyang/p/6607318.html
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
    
    int dfs(TreeNode* root, int& result){
        if(!root)
            return 0;
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result = max(result, left + right);
        return max(left, right) + 1;
    }
    
private:
};

// @lc code=end
