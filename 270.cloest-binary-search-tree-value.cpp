/*
 * @lc app=leetcode id=270 lang=cpp
 *
 * [270] Closest Binary Search Tree Value
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
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int result = -1;
        double minDiff = numeric_limits<double>::max();
        inOrder(root, target, result, minDiff);
        return result;
    }
    
    void inOrder(TreeNode* root, double target, int& result, double& minDiff){
        if(!root)
            return;
        inOrder(root->left, target, result, minDiff);
        if(abs(target - root->val) < minDiff){
            cout << root->val << endl;
            result = root->val;
            minDiff = min(minDiff, abs(target - root->val));
        }
        if(root->val >= target)
            return;
        inOrder(root->right, target, result, minDiff);
    }
};

// @lc code=end