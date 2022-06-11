/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode *root)
    {
        // return recursion(root, nullptr, nullptr);
        return inOrder(root);
    }

private:
    // Solution 1: recursion (from huahua)
    bool recursion(TreeNode *root, int* min, int* max){
        if(!root)
            return true;
        if((min && root->val <= *min) || (max && root->val >= *max))
            return false;
        return recursion(root->left, min, &root->val) &&
                recursion(root->right, &root->val, max);
    }

    // Solution 2: in order traversal (from grandyang)
    TreeNode *prev = nullptr;
    bool inOrder(TreeNode *root){
        if(!root)
            return true;
        if(!inOrder(root->left))
            return false;
        if(prev && root->val <= prev->val)
            return false;
        prev = root;
        return inOrder(root->right);
    }
};
// @lc code=end
