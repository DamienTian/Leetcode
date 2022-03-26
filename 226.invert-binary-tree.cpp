/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
//#include "dummyHead.h"

class Solution
{
public:
    // Solution 1: DFS recursion
    //  ref: https://www.cnblogs.com/grandyang/p/4790476.html
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        // TreeNode *tmp = root->left;
        // root->left = root->right;
        // root->right = tmp;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    // Solution 2: BFS iteration
    //  ref: https://www.cnblogs.com/grandyang/p/4572877.html
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        queue<TreeNode*> q {{root}};
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left || curr->right){
                swap(curr->left, curr->right);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return root;
    }
};

// @lc code=end