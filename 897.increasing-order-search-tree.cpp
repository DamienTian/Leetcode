/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 */

// @lc code=start
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
//#include "dummyHead.h"

class Solution
{
public:
    // Solution 1: inOrder with extra space
    TreeNode *increasingBST(TreeNode *root)
    {
        if (!root)
            return root;
        inOrder(root);
        TreeNode* newRoot, *head;
        newRoot = new TreeNode(inOrderArray[0]);
        head = newRoot;
        for(int i = 1; i < inOrderArray.size(); ++i){
            head->right = new TreeNode(inOrderArray[i]);
            head = head->right;
        }
        return newRoot;
    }

    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        inOrderArray.push_back(root->val);
        inOrder(root->right);
    }

private:
    vector<int> inOrderArray;
};
// @lc code=end
