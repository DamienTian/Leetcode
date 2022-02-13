/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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

// ref: https://zxi.mytechroad.com/blog/tree/leetcode-1302-deepest-leaves-sum/
class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        int result = 0;
        int maxDepth = 0;
        helper(root, 0, result, maxDepth);
        return result;
    }

    void helper(TreeNode *root, int depth, int &result, int &maxDepth)
    {
        if (!root)
            return;

        if (depth > maxDepth)
        {
            maxDepth = depth;
            result = 0;
        }
        if (depth == maxDepth)
            result += root->val;

        helper(root->left, depth + 1, result, maxDepth);
        helper(root->right, depth + 1, result, maxDepth);
    }
};
// @lc code=end
